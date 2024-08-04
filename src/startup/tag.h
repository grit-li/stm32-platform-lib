#ifndef __STM32_TAG_H__
#define __STM32_TAG_H__

#include <stdint.h>

struct tag_header
{
    unsigned int size;
    unsigned int tag;
};

#define ATAG_CORE 0x54410001
#define ATAG_NONE 0x00000000
struct tag_core {
    unsigned int flags;        /* bit 0 = read-only */
    unsigned int pagesize;
    unsigned int rootdev;
};

#define ATAG_CMDLINE    0x54410009
struct tag_cmdline {
    char cmdline[1];    /* this is the minimum size */
};

struct tag {
    struct tag_header hdr;
    union {
        struct tag_core       core;
        struct tag_cmdline    cmdline;
    } u;
};

void load_tag(uintptr_t);

#endif