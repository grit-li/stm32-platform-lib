#include <_ansi.h>
#include <_syslist.h>
#include <errno.h>
#include <sys/time.h>
#include <sys/times.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdint.h>
#include <stdio.h>
#include "stm32/gpio.h"
#include "stm32/usart.h"

#define STDIN_FILENO  0
#define STDOUT_FILENO 1
#define STDERR_FILENO 2

static HGPIO hrx = MAKE_HGPIO(gpio_group_a, gpio_port_10, gpio_mode_output_alternate_push_pull_up, gpio_alternate_7, gpio_status_low);
static HGPIO htx = MAKE_HGPIO(gpio_group_a, gpio_port_9, gpio_mode_output_alternate_push_pull_up, gpio_alternate_7, gpio_status_low);
static unsigned int g_system_printf_init_flag = 0;

static void system_printf_init(void)
{
    gpio_init(hrx);
    gpio_init(htx);
    struct usart_init_t init;
    usart_struct_init(&init, usart_type_1);
    usart_init(&init);
    setvbuf(stdout, NULL, _IONBF, 0);
    g_system_printf_init_flag = 1;
}

void _retarget_init(void)
{
    system_printf_init();
}

int _isatty(int fd)
{
    if(fd >= STDIN_FILENO && fd <= STDERR_FILENO)
        return 1;
    errno = EBADF;
    return 0;
}

int _write(int fd, char *ptr, int len)
{
    if(fd == STDOUT_FILENO || fd == STDERR_FILENO) {
        if(g_system_printf_init_flag) {
            usart_send_data(usart_type_1, (const uint8_t *)ptr, len);
            return len;
        }
        return EIO;
    }
    errno = EBADF;
    return -1;
}

int _close(int fd)
{
    if(fd >= STDIN_FILENO && fd <= STDERR_FILENO)
        return 0;
    errno = EBADF;
    return -1;

}

int _lseek(int fd, int ptr, int dir)
{
    (void) fd;
    (void) ptr;
    (void) dir;
    errno = EBADF;
    return -1;
}

int _read(int fd, char *ptr, int len)
{
    errno = EBADF;
    return -1;
}

int _fstat(int fd, struct stat *st)
{
    if(fd >= STDIN_FILENO && fd <= STDERR_FILENO) {
        st->st_mode = S_IFCHR;
        return 0;
    }
    errno = EBADF;
    return 0;
}

caddr_t _sbrk(int increment)
{
    extern char end asm("end");
    register char* pStack asm("sp");

    static char* s_pHeapEnd;

    if(!s_pHeapEnd)
        s_pHeapEnd = &end;

    if(s_pHeapEnd + increment > pStack)
        return (caddr_t)-1;

    char* pOldHeapEnd = s_pHeapEnd;
    s_pHeapEnd += increment;
    return (caddr_t)pOldHeapEnd;
}

