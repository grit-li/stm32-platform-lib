#include "syslog.h"
#include "components/syslogd/syslogd.h"
#include "rtthread.h"

#define SYSLOG_BUFFER_SIZE 1024

static enum LOG_LEVEL_E g_log_level = LOG_LEVEL_ALL;

void syslog_print(enum LOG_LEVEL_E level, const char* prefix, const char* funcName, const char* fmt, ...)
{
    if(g_log_level > level) {
        return;
    }
    static char buff[SYSLOG_BUFFER_SIZE] = { 0 };
    uint32_t n;

    n = rt_snprintf(buff, SYSLOG_BUFFER_SIZE, "[STM32][%s][%s]", prefix, funcName);

    va_list args;
    va_start(args, fmt);
    n += rt_snprintf(&buff[n], SYSLOG_BUFFER_SIZE - n, fmt, args);
    va_end(args);
    syslogd_writebuff(buff, n);
}
