#include <stdio.h>
#include "syslogd.h"
#include "datacache.h"
#include "rtthread.h"
#include "../finsh/finsh.h"

#define SYSLOGD_CACHE_SIZE       (20 * 1024)
#define SYSLOGD_FRAME_CACHE_SIZE 63

static uint8_t syslogd_cache[SYSLOGD_CACHE_SIZE];
static struct DATA_CACHE syslogd_datacache;

static inline struct DATA_CACHE* GetSyslogdCache(void)
{
    return &syslogd_datacache;
}

void syslogd_writebuff(const char* buff, uint32_t size)
{
    struct DATA_CACHE* pCache = GetSyslogdCache();
    PushDataCacheBuff(pCache, (const uint8_t *)buff, size);
}

int syslogd_init(void)
{
    DataCacheInit(&syslogd_datacache, syslogd_cache, SYSLOGD_CACHE_SIZE);
    return 0;
}
INIT_APP_EXPORT(syslogd_init);

static long logread(void)
{
    uint8_t FrameCache[SYSLOGD_FRAME_CACHE_SIZE + 1];
    uint32_t FrameCacheSize = 0;
    struct DATA_CACHE* pCache = GetSyslogdCache();
    FrameCache[SYSLOGD_FRAME_CACHE_SIZE] = '\0';
    FrameCacheSize = DataCacheSize(pCache);
    while(FrameCacheSize > 0) {
        if(FrameCacheSize > SYSLOGD_FRAME_CACHE_SIZE) {
            PopDataCacheBuff(pCache, FrameCache, SYSLOGD_FRAME_CACHE_SIZE);
            FrameCacheSize -= SYSLOGD_FRAME_CACHE_SIZE;
        } else {
            PopDataCacheBuff(pCache, FrameCache, FrameCacheSize);
            FrameCache[FrameCacheSize] = '\0';
            FrameCacheSize = 0;
        }
        rt_kprintf("%s", FrameCache);
    }
    return 0;
}
MSH_CMD_EXPORT(logread, "output debug info");
