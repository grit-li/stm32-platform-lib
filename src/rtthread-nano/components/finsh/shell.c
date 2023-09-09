/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2006-04-30     Bernard      the first version for FinSH
 * 2006-05-08     Bernard      change finsh thread stack to 2048
 * 2006-06-03     Bernard      add support for skyeye
 * 2006-09-24     Bernard      remove the code related with hardware
 * 2010-01-18     Bernard      fix down then up key bug.
 * 2010-03-19     Bernard      fix backspace issue and fix device read in shell.
 * 2010-04-01     Bernard      add prompt output when start and remove the empty history
 * 2011-02-23     Bernard      fix variable section end issue of finsh shell
 *                             initialization when use GNU GCC compiler.
 * 2016-11-26     armink       add password authentication
 * 2018-07-02     aozima       add custom prompt support.
 */

#include <rthw.h>
#include <string.h>
#include <stdio.h>

#include "shell.h"
#include "msh.h"

/* finsh thread */
#ifndef RT_USING_HEAP
    static struct rt_thread finsh_thread;
    ALIGN(RT_ALIGN_SIZE)
    static char finsh_thread_stack[FINSH_THREAD_STACK_SIZE];
    struct finsh_shell _shell;
#endif

/* finsh symtab */
struct finsh_syscall *_syscall_table_begin  = NULL;
struct finsh_syscall *_syscall_table_end    = NULL;

struct finsh_shell *shell;
static char *finsh_prompt_custom = RT_NULL;

#ifdef RT_USING_HEAP
int finsh_set_prompt(const char *prompt)
{
    if (finsh_prompt_custom)
    {
        rt_free(finsh_prompt_custom);
        finsh_prompt_custom = RT_NULL;
    }

    /* strdup */
    if (prompt)
    {
        finsh_prompt_custom = (char *)rt_malloc(strlen(prompt) + 1);
        if (finsh_prompt_custom)
        {
            strcpy(finsh_prompt_custom, prompt);
        }
    }

    return 0;
}
#endif /* RT_USING_HEAP */

#define _MSH_PROMPT "msh "

const char *finsh_get_prompt(void)
{
    static char finsh_prompt[RT_CONSOLEBUF_SIZE + 1] = {0};

    /* check prompt mode */
    if (!shell->prompt_mode)
    {
        finsh_prompt[0] = '\0';
        return finsh_prompt;
    }

    if (finsh_prompt_custom)
    {
        strncpy(finsh_prompt, finsh_prompt_custom, sizeof(finsh_prompt) - 1);
    }
    else
    {
        strcpy(finsh_prompt, _MSH_PROMPT);
    }

    strcat(finsh_prompt, ">");

    return finsh_prompt;
}

/**
 * @ingroup finsh
 *
 * This function get the prompt mode of finsh shell.
 *
 * @return prompt the prompt mode, 0 disable prompt mode, other values enable prompt mode.
 */
rt_uint32_t finsh_get_prompt_mode(void)
{
    RT_ASSERT(shell != RT_NULL);
    return shell->prompt_mode;
}

/**
 * @ingroup finsh
 *
 * This function set the prompt mode of finsh shell.
 *
 * The parameter 0 disable prompt mode, other values enable prompt mode.
 *
 * @param prompt the prompt mode
 */
void finsh_set_prompt_mode(rt_uint32_t prompt_mode)
{
    RT_ASSERT(shell != RT_NULL);
    shell->prompt_mode = prompt_mode;
}

int finsh_getchar(void)
{
#ifdef RT_USING_DEVICE
    char ch = 0;

    rt_device_t device;

    RT_ASSERT(shell != RT_NULL);

    device = shell->device;
    if (device == RT_NULL)
    {
        return -1; /* EOF */
    }

    while (rt_device_read(device, -1, &ch, 1) != 1)
    {
        rt_sem_take(&shell->rx_sem, RT_WAITING_FOREVER);
        if (shell->device != device)
        {
            device = shell->device;
            if (device == RT_NULL)
            {
                return -1;
            }
        }
    }
    return ch;
#else
    extern char rt_hw_console_getchar(void);
    return rt_hw_console_getchar();
#endif /* RT_USING_DEVICE */
}

#if defined(RT_USING_DEVICE)
static rt_err_t finsh_rx_ind(rt_device_t dev, rt_size_t size)
{
    RT_ASSERT(shell != RT_NULL);

    /* release semaphore to let finsh thread rx data */
    rt_sem_release(&shell->rx_sem);

    return RT_EOK;
}

/**
 * @ingroup finsh
 *
 * This function sets the input device of finsh shell.
 *
 * @param device_name the name of new input device.
 */
void finsh_set_device(const char *device_name)
{
    rt_device_t dev = RT_NULL;

    RT_ASSERT(shell != RT_NULL);
    dev = rt_device_find(device_name);
    if (dev == RT_NULL)
    {
        rt_kprintf("finsh: can not find device: %s\n", device_name);
        return;
    }

    /* check whether it's a same device */
    if (dev == shell->device) return;
    /* open this device and set the new device in finsh shell */
    if (rt_device_open(dev, RT_DEVICE_OFLAG_RDWR | RT_DEVICE_FLAG_INT_RX | \
                       RT_DEVICE_FLAG_STREAM) == RT_EOK)
    {
        if (shell->device != RT_NULL)
        {
            /* close old finsh device */
            rt_device_close(shell->device);
            rt_device_set_rx_indicate(shell->device, RT_NULL);
        }

        /* clear line buffer before switch to new device */
        rt_memset(shell->line, 0, sizeof(shell->line));
        shell->line_curpos = shell->line_position = 0;

        shell->device = dev;
        rt_device_set_rx_indicate(dev, finsh_rx_ind);
    }
}

/**
 * @ingroup finsh
 *
 * This function returns current finsh shell input device.
 *
 * @return the finsh shell input device name is returned.
 */
const char *finsh_get_device()
{
    RT_ASSERT(shell != RT_NULL);
    return shell->device->parent.name;
}
#endif /* defined(RT_USING_DEVICE) */

/**
 * @ingroup finsh
 *
 * This function set the echo mode of finsh shell.
 *
 * FINSH_OPTION_ECHO=0x01 is echo mode, other values are none-echo mode.
 *
 * @param echo the echo mode
 */
void finsh_set_echo(rt_uint32_t echo)
{
    RT_ASSERT(shell != RT_NULL);
    shell->echo_mode = (rt_uint8_t)echo;
}

/**
 * @ingroup finsh
 *
 * This function gets the echo mode of finsh shell.
 *
 * @return the echo mode
 */
rt_uint32_t finsh_get_echo()
{
    RT_ASSERT(shell != RT_NULL);

    return shell->echo_mode;
}

#ifdef FINSH_USING_AUTH
/**
 * set a new password for finsh
 *
 * @param password new password
 *
 * @return result, RT_EOK on OK, -RT_ERROR on the new password length is less than
 *  FINSH_PASSWORD_MIN or greater than FINSH_PASSWORD_MAX
 */
rt_err_t finsh_set_password(const char *password)
{
    rt_base_t level;
    rt_size_t pw_len = rt_strlen(password);

    if (pw_len < FINSH_PASSWORD_MIN || pw_len > FINSH_PASSWORD_MAX)
        return -RT_ERROR;

    level = rt_hw_interrupt_disable();
    rt_strncpy(shell->password, password, FINSH_PASSWORD_MAX);
    rt_hw_interrupt_enable(level);

    return RT_EOK;
}

/**
 * get the finsh password
 *
 * @return password
 */
const char *finsh_get_password(void)
{
    return shell->password;
}

static void finsh_wait_auth(void)
{
    int ch;
    rt_bool_t input_finish = RT_FALSE;
    char password[FINSH_PASSWORD_MAX] = { 0 };
    rt_size_t cur_pos = 0;
    /* password not set */
    if (rt_strlen(finsh_get_password()) == 0) return;

    while (1)
    {
        rt_kprintf("Password for login: ");
        while (!input_finish)
        {
            while (1)
            {
                /* read one character from device */
                ch = (int)finsh_getchar();
                if (ch < 0)
                {
                    continue;
                }

                if (ch >= ' ' && ch <= '~' && cur_pos < FINSH_PASSWORD_MAX)
                {
                    /* change the printable characters to '*' */
                    rt_kprintf("*");
                    password[cur_pos++] = ch;
                }
                else if (ch == '\b' && cur_pos > 0)
                {
                    /* backspace */
                    cur_pos--;
                    password[cur_pos] = '\0';
                    rt_kprintf("\b \b");
                }
                else if (ch == '\r' || ch == '\n')
                {
                    rt_kprintf("\n");
                    input_finish = RT_TRUE;
                    break;
                }
            }
        }
        if (!rt_strncmp(shell->password, password, FINSH_PASSWORD_MAX)) return;
        else
        {
            /* authentication failed, delay 2S for retry */
            rt_thread_delay(2 * RT_TICK_PER_SECOND);
            rt_kprintf("Sorry, try again.\n");
            cur_pos = 0;
            input_finish = RT_FALSE;
            rt_memset(password, '\0', FINSH_PASSWORD_MAX);
        }
    }
}
#endif /* FINSH_USING_AUTH */

static void shell_auto_complete(char *prefix)
{
    rt_kprintf("\n");
    msh_auto_complete(prefix);

    rt_kprintf("%s%s", FINSH_PROMPT, prefix);
}

#ifdef FINSH_USING_HISTORY
static rt_bool_t shell_handle_history(struct finsh_shell *shell)
{
#if defined(_WIN32)
    int i;
    rt_kprintf("\r");

    for (i = 0; i <= 60; i++)
        putchar(' ');
    rt_kprintf("\r");

#else
    rt_kprintf("\033[2K\r");
#endif
    rt_kprintf("%s%s", FINSH_PROMPT, shell->line);
    return RT_FALSE;
}

static void shell_push_history(struct finsh_shell *shell)
{
    if (shell->line_position != 0)
    {
        /* push history */
        if (shell->history_count >= FINSH_HISTORY_LINES)
        {
            /* if current cmd is same as last cmd, don't push */
            if (memcmp(&shell->cmd_history[FINSH_HISTORY_LINES - 1], shell->line, FINSH_CMD_SIZE))
            {
                /* move history */
                int index;
                for (index = 0; index < FINSH_HISTORY_LINES - 1; index ++)
                {
                    rt_memcpy(&shell->cmd_history[index][0],
                           &shell->cmd_history[index + 1][0], FINSH_CMD_SIZE);
                }
                rt_memset(&shell->cmd_history[index][0], 0, FINSH_CMD_SIZE);
                rt_memcpy(&shell->cmd_history[index][0], shell->line, shell->line_position);

                /* it's the maximum history */
                shell->history_count = FINSH_HISTORY_LINES;
            }
        }
        else
        {
            /* if current cmd is same as last cmd, don't push */
            if (shell->history_count == 0 || memcmp(&shell->cmd_history[shell->history_count - 1], shell->line, FINSH_CMD_SIZE))
            {
                shell->current_history = shell->history_count;
                rt_memset(&shell->cmd_history[shell->history_count][0], 0, FINSH_CMD_SIZE);
                rt_memcpy(&shell->cmd_history[shell->history_count][0], shell->line, shell->line_position);

                /* increase count and set current history position */
                shell->history_count ++;
            }
        }
    }
    shell->current_history = shell->history_count;
}
#endif

void finsh_thread_entry(void *parameter)
{
    int ch;
    /* normal is echo mode */
#ifndef FINSH_ECHO_DISABLE_DEFAULT
    shell->echo_mode = 1;
#else
    shell->echo_mode = 0;
#endif

#if defined(RT_USING_DEVICE)
    /* set console device as shell device */
    if (shell->device == RT_NULL)
    {
        rt_device_t console = rt_console_get_device();
        if (console)
        {
            finsh_set_device(console->parent.name);
        }
    }
#endif /* defined(RT_USING_DEVICE) */

#ifdef FINSH_USING_AUTH
    /* set the default password when the password isn't setting */
    if (rt_strlen(finsh_get_password()) == 0)
    {
        if (finsh_set_password(FINSH_DEFAULT_PASSWORD) != RT_EOK)
        {
            rt_kprintf("Finsh password set failed.\n");
        }
    }
    /* waiting authenticate success */
    finsh_wait_auth();
#endif

    rt_kprintf(FINSH_PROMPT);

    while (1)
    {
        ch = (int)finsh_getchar();
        if (ch < 0)
        {
            continue;
        }

        /*
         * handle control key
         * up key  : 0x1b 0x5b 0x41
         * down key: 0x1b 0x5b 0x42
         * right key:0x1b 0x5b 0x43
         * left key: 0x1b 0x5b 0x44
         */
        if (ch == 0x1b)
        {
            shell->stat = WAIT_SPEC_KEY;
            continue;
        }
        else if (shell->stat == WAIT_SPEC_KEY)
        {
            if (ch == 0x5b)
            {
                shell->stat = WAIT_FUNC_KEY;
                continue;
            }

            shell->stat = WAIT_NORMAL;
        }
        else if (shell->stat == WAIT_FUNC_KEY)
        {
            shell->stat = WAIT_NORMAL;

            if (ch == 0x41) /* up key */
            {
#ifdef FINSH_USING_HISTORY
                /* prev history */
                if (shell->current_history > 0)
                    shell->current_history --;
                else
                {
                    shell->current_history = 0;
                    continue;
                }

                /* copy the history command */
                rt_memcpy(shell->line, &shell->cmd_history[shell->current_history][0],
                       FINSH_CMD_SIZE);
                shell->line_curpos = shell->line_position = (rt_uint16_t)strlen(shell->line);
                shell_handle_history(shell);
#endif
                continue;
            }
            else if (ch == 0x42) /* down key */
            {
#ifdef FINSH_USING_HISTORY
                /* next history */
                if (shell->current_history < shell->history_count - 1)
                    shell->current_history ++;
                else
                {
                    /* set to the end of history */
                    if (shell->history_count != 0)
                        shell->current_history = shell->history_count - 1;
                    else
                        continue;
                }

                rt_memcpy(shell->line, &shell->cmd_history[shell->current_history][0],
                       FINSH_CMD_SIZE);
                shell->line_curpos = shell->line_position = (rt_uint16_t)strlen(shell->line);
                shell_handle_history(shell);
#endif
                continue;
            }
            else if (ch == 0x44) /* left key */
            {
                if (shell->line_curpos)
                {
                    rt_kprintf("\b");
                    shell->line_curpos --;
                }

                continue;
            }
            else if (ch == 0x43) /* right key */
            {
                if (shell->line_curpos < shell->line_position)
                {
                    rt_kprintf("%c", shell->line[shell->line_curpos]);
                    shell->line_curpos ++;
                }

                continue;
            }
        }

        /* received null or error */
        if (ch == '\0' || ch == 0xFF) continue;
        /* handle tab key */
        else if (ch == '\t')
        {
            int i;
            /* move the cursor to the beginning of line */
            for (i = 0; i < shell->line_curpos; i++)
                rt_kprintf("\b");

            /* auto complete */
            shell_auto_complete(&shell->line[0]);
            /* re-calculate position */
            shell->line_curpos = shell->line_position = (rt_uint16_t)strlen(shell->line);

            continue;
        }
        /* handle backspace key */
        else if (ch == 0x7f || ch == 0x08)
        {
            /* note that shell->line_curpos >= 0 */
            if (shell->line_curpos == 0)
                continue;

            shell->line_position--;
            shell->line_curpos--;

            if (shell->line_position > shell->line_curpos)
            {
                int i;

                rt_memmove(&shell->line[shell->line_curpos],
                           &shell->line[shell->line_curpos + 1],
                           shell->line_position - shell->line_curpos);
                shell->line[shell->line_position] = 0;

                rt_kprintf("\b%s  \b", &shell->line[shell->line_curpos]);

                /* move the cursor to the origin position */
                for (i = shell->line_curpos; i <= shell->line_position; i++)
                    rt_kprintf("\b");
            }
            else
            {
                rt_kprintf("\b \b");
                shell->line[shell->line_position] = 0;
            }

            continue;
        }

        /* handle end of line, break */
        if (ch == '\r' || ch == '\n')
        {
#ifdef FINSH_USING_HISTORY
            shell_push_history(shell);
#endif
            if (shell->echo_mode)
                rt_kprintf("\n");
            msh_exec(shell->line, shell->line_position);

            rt_kprintf(FINSH_PROMPT);
            rt_memset(shell->line, 0, sizeof(shell->line));
            shell->line_curpos = shell->line_position = 0;
            continue;
        }

        /* it's a large line, discard it */
        if (shell->line_position >= FINSH_CMD_SIZE)
            shell->line_position = 0;

        /* normal character */
        if (shell->line_curpos < shell->line_position)
        {
            int i;

            rt_memmove(&shell->line[shell->line_curpos + 1],
                       &shell->line[shell->line_curpos],
                       shell->line_position - shell->line_curpos);
            shell->line[shell->line_curpos] = ch;
            if (shell->echo_mode)
                rt_kprintf("%s", &shell->line[shell->line_curpos]);

            /* move the cursor to new position */
            for (i = shell->line_curpos; i < shell->line_position; i++)
                rt_kprintf("\b");
        }
        else
        {
            shell->line[shell->line_position] = ch;
            if (shell->echo_mode)
                rt_kprintf("%c", ch);
        }

        ch = 0;
        shell->line_position ++;
        shell->line_curpos++;
        if (shell->line_position >= FINSH_CMD_SIZE)
        {
            /* clear command line */
            shell->line_position = 0;
            shell->line_curpos = 0;
        }
    } /* end of device read */
}

void finsh_system_function_init(const void *begin, const void *end)
{
    _syscall_table_begin = (struct finsh_syscall *) begin;
    _syscall_table_end = (struct finsh_syscall *) end;
}

/*
 * @ingroup finsh
 *
 * This function will initialize finsh shell
 */
int finsh_system_init(void)
{
    rt_err_t result = RT_EOK;
    rt_thread_t tid;

    extern const int __fsymtab_start;
    extern const int __fsymtab_end;
    finsh_system_function_init(&__fsymtab_start, &__fsymtab_end);

#ifdef RT_USING_HEAP
    /* create or set shell structure */
    shell = (struct finsh_shell *)rt_calloc(1, sizeof(struct finsh_shell));
    if (shell == RT_NULL)
    {
        rt_kprintf("no memory for shell\n");
        return -1;
    }
    tid = rt_thread_create(FINSH_THREAD_NAME,
                           finsh_thread_entry, RT_NULL,
                           FINSH_THREAD_STACK_SIZE, FINSH_THREAD_PRIORITY, 10);
#else
    shell = &_shell;
    tid = &finsh_thread;
    result = rt_thread_init(&finsh_thread,
                            FINSH_THREAD_NAME,
                            finsh_thread_entry, RT_NULL,
                            &finsh_thread_stack[0], sizeof(finsh_thread_stack),
                            FINSH_THREAD_PRIORITY, 10);
#endif /* RT_USING_HEAP */

    rt_sem_init(&(shell->rx_sem), "shrx", 0, 0);
    finsh_set_prompt_mode(1);
    if (tid != NULL && result == RT_EOK)
        rt_thread_startup(tid);
    return 0;
}
INIT_APP_EXPORT(finsh_system_init);
