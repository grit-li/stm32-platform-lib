#ifndef _STDIO_H_
#define	_STDIO_H_

#include <stm32_gcc_attribute.h>

#ifdef __cplusplus
extern "C" {
#endif

int printf(const char *__restrict, ...) __stm32_platform_format__(__printf__, 1, 2);

#ifdef __cplusplus
}
#endif

#endif /* _STDIO_H_ */
