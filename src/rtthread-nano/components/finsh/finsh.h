/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2010-03-22     Bernard      first version
 */
#ifndef __FINSH_H__
#define __FINSH_H__

#include <rtdef.h>

typedef long (*syscall_func)(void);
#define MSH_FUNCTION_EXPORT_CMD(name, cmd, desc)                      \
                const char __fsym_##name##_name[] SECTION(".rodata.name") = cmd;    \
                const char __fsym_##name##_desc[] SECTION(".rodata.name") = desc;   \
                RT_USED const struct finsh_syscall __fsym_##name SECTION("FSymTab")= \
                {                           \
                    __fsym_##name##_name,    \
                    __fsym_##name##_desc,    \
                    (syscall_func)&name     \
                };

/**
 * @ingroup msh
 *
 * This macro exports a command to module shell.
 *
 * @param command is the name of the command.
 * @param desc is the description of the command, which will show in help list.
 */
#define MSH_CMD_EXPORT(command, desc)   \
  MSH_FUNCTION_EXPORT_CMD(command, #command, desc)

/**
 * @ingroup msh
 *
 * This macro exports a command with alias to module shell.
 *
 * @param command is the name of the command.
 * @param alias is the alias of the command.
 * @param desc is the description of the command, which will show in help list.
 */
#define MSH_CMD_EXPORT_ALIAS(command, alias, desc)  \
    MSH_FUNCTION_EXPORT_CMD(command, alias, desc)

/* system call table */
struct finsh_syscall
{
    const char     *name;       /* the name of system call */
    const char     *desc;       /* description of system call */
    syscall_func func;      /* the function address of system call */
};

/* system call item */
struct finsh_syscall_item
{
    struct finsh_syscall_item *next;    /* next item */
    struct finsh_syscall syscall;       /* syscall */
};

extern struct finsh_syscall *_syscall_table_begin, *_syscall_table_end;

#if defined(RT_USING_DEVICE)
void finsh_set_device(const char *device_name);
#endif

#endif
