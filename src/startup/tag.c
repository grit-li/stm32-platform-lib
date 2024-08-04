#include <string.h>
#include "stm32_types.h"
#include "tag.h"

static void tag_cmdline(struct tag* p);

#define CMDSIZE 1023

struct tag_cmd_list
{
    unsigned int tag;
    void (*tag_callback)(struct tag *);
};

static char g_default_cmdline[CMDSIZE + 1] = { 0 };
static struct tag_cmd_list g_cmd_list[] = {
    { ATAG_CMDLINE, tag_cmdline},
};

static void tag_cmdline(struct tag* p)
{
    uint32_t length = p->hdr.size - sizeof(struct tag_header);

    if(length > CMDSIZE) {
        length = CMDSIZE;
    }
    memcpy(g_default_cmdline, p->u.cmdline.cmdline, length - 1);
}

void load_tag(uintptr_t addr)
{
    struct tag* p = (struct tag *)addr;

    if(!p || p->hdr.tag != ATAG_CORE) {
        return;
    }

    do {
        for(int i = 0; i < sizeof(g_cmd_list)/sizeof(struct tag_cmd_list); i++) {
            if(p->hdr.tag == g_cmd_list[i].tag) {
                g_cmd_list->tag_callback(p);
                break;
            }
        }
        p = (struct tag *)((uint8_t *)p + p->hdr.size);
    } while(p->hdr.tag != ATAG_NONE);
}

const char* stm32_get_cmdlind(void)
{
    return g_default_cmdline;
}