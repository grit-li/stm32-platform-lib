#ifndef __SYSLOGD_H__
#define __SYSLOGD_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

void syslogd_writebuff(const char* buff, uint32_t size);

#ifdef __cplusplus
}
#endif

#endif