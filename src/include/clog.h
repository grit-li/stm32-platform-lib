#ifndef __STM32_LOG_H__
#define __STM32_LOG_H__

#include <stdio.h>

#ifndef SDK_RELEASE
#define debug_printf printf
#else
#define debug_printf(fmt, ...)
#endif

#define COLOR_BLACK
#define COLOR_HIGHT_BLACK

#define COLOR_RED
#define COLOR_HIGHT_RED

#define COLOR_GREEN
#define COLOR_HIGHT_GREEN

#define COLOR_YELLOW
#define COLOR_HIGHT_YELLOW

#define COLOR_BLUE
#define COLOR_HIGHT_BLUE

#define COLOR_PURPLE
#define COLOR_HIGHT_PURPLE

#define COLOR_CYAN
#define COLOR_HIGHT_CYAN

#define COLOR_GRAY
#define COLOR_HIGHT_GRAY

#define COLOR_WHITE
#define COLOR_HIGHT_WHITE

#define PRINTF_COLOR_FONT_BLACK         "\033[0;30m"
#define PRINTF_COLOR_FONT_HIGHT_BLACK   "\033[1;30m"

#define PRINTF_COLOR_FONT_RED           "\033[0;31m"
#define PRINTF_COLOR_FONT_HIGHT_RED     "\033[1;31m"

#define PRINTF_COLOR_FONT_GREEN         "\033[0;32m"
#define PRINTF_COLOR_FONT_HIGHT_GREEN   "\033[1;32m"

#define PRINTF_COLOR_FONT_YELLOW        "\033[0;33m"
#define PRINTF_COLOR_FONT_HIGHT_YELLOW  "\033[1;33m"

#define PRINTF_COLOR_FONT_BLUE          "\033[0;34m"
#define PRINTF_COLOR_FONT_HIGHT_BLUE    "\033[1;34m"

#define PRINTF_COLOR_FONT_PURPLE        "\033[0;35m"
#define PRINTF_COLOR_FONT_HIGHT_PURPLE  "\033[1;35m"

#define PRINTF_COLOR_FONT_CYAN          "\033[0;36m"
#define PRINTF_COLOR_FONT_HIGHT_CYAN    "\033[1;36m"

#define PRINTF_COLOR_FONT_GRAY          "\033[0;37m"
#define PRINTF_COLOR_FONT_HIGHT_GRAY    "\033[1;37m"

#define PRINTF_COLOR_FONT_WHITE         "\033[0;37m"
#define PRINTF_COLOR_FONT_HIGHT_WHITE   "\033[1;37m"

#define PRINTF_COLOR_FONT_NODE          "\033[0m"

#define PRINTF_HIDE                     "\033[8m"
#define PRINTF_CLEAR                    "\033[2j"
#define PRINTF_CLEAR_LINE               "\015\033[K"
#define PRINTF_END                      PRINTF_COLOR_FONT_NODE

#define FONT_COLOR_BLACK(s)             PRINTF_COLOR_FONT_BLACK         s PRINTF_COLOR_FONT_NODE
#define FONT_COLOR_HIGHT_BLACK(s)       PRINTF_COLOR_FONT_HIGHT_BLACK   s PRINTF_COLOR_FONT_NODE

#define FONT_COLOR_RED(s)               PRINTF_COLOR_FONT_RED           s PRINTF_COLOR_FONT_NODE
#define FONT_COLOR_HIGHT_RED(s)         PRINTF_COLOR_FONT_HIGHT_RED     s PRINTF_COLOR_FONT_NODE

#define FONT_COLOR_GREEN(s)             PRINTF_COLOR_FONT_GREEN         s PRINTF_COLOR_FONT_NODE
#define FONT_COLOR_HIGHT_GREEN(s)       PRINTF_COLOR_FONT_HIGHT_GREEN   s PRINTF_COLOR_FONT_NODE

#define FONT_COLOR_YELLOW(s)            PRINTF_COLOR_FONT_YELLOW        s PRINTF_COLOR_FONT_NODE
#define FONT_COLOR_HIGHT_YELLOW(s)      PRINTF_COLOR_FONT_HIGHT_YELLOW  s PRINTF_COLOR_FONT_NODE

#define FONT_COLOR_BLUE(s)              PRINTF_COLOR_FONT_BLUE          s PRINTF_COLOR_FONT_NODE
#define FONT_COLOR_HIGHT_BLUE(s)        PRINTF_COLOR_FONT_HIGHT_BLUE    s PRINTF_COLOR_FONT_NODE

#define FONT_COLOR_PURPLE(s)            PRINTF_COLOR_FONT_PURPLE        s PRINTF_COLOR_FONT_NODE
#define FONT_COLOR_HIGHT_PURPLE(s)      PRINTF_COLOR_FONT_HIGHT_PURPLE  s PRINTF_COLOR_FONT_NODE

#define FONT_COLOR_CYAN(s)              PRINTF_COLOR_FONT_CYAN          s PRINTF_COLOR_FONT_NODE
#define FONT_COLOR_HIGHT_CYAN(s)        PRINTF_COLOR_FONT_HIGHT_CYAN    s PRINTF_COLOR_FONT_NODE

#define FONT_COLOR_GRAY(s)              PRINTF_COLOR_FONT_GRAY          s PRINTF_COLOR_FONT_NODE
#define FONT_COLOR_HIGHT_GRAY(s)        PRINTF_COLOR_FONT_HIGHT_GRAY    s PRINTF_COLOR_FONT_NODE

#define FONT_COLOR_WHITE(s)             PRINTF_COLOR_FONT_WHITE         s PRINTF_COLOR_FONT_NODE
#define FONT_COLOR_HIGHT_WHITE(s)       PRINTF_COLOR_FONT_HIGHT_WHITE   s PRINTF_COLOR_FONT_NODE

#define FONT_COLOR(color, str)          FONT_##color(str)

#define TARGET_ERR                      FONT_COLOR(COLOR_HIGHT_WHITE, "[")  FONT_COLOR(COLOR_HIGHT_RED,     "ERROR")     FONT_COLOR(COLOR_HIGHT_WHITE, "]")
#define TARGET_WAR                      FONT_COLOR(COLOR_HIGHT_WHITE, "[")  FONT_COLOR(COLOR_HIGHT_PURPLE,  "WARNING")   FONT_COLOR(COLOR_HIGHT_WHITE, "]")
#define TARGET_DEB                      FONT_COLOR(COLOR_HIGHT_WHITE, "[")  FONT_COLOR(COLOR_HIGHT_GREEN,   "DEBUG")     FONT_COLOR(COLOR_HIGHT_WHITE, "]")
#define TARGET_INFO                     FONT_COLOR(COLOR_HIGHT_WHITE, "[")  FONT_COLOR(COLOR_HIGHT_WHITE,   "INFO")      FONT_COLOR(COLOR_HIGHT_WHITE, "]")
#define TARGET_FAIL                     FONT_COLOR(COLOR_HIGHT_WHITE, "[")  FONT_COLOR(COLOR_HIGHT_WHITE,   "FAIL")      FONT_COLOR(COLOR_HIGHT_WHITE, "]")
#define TARGET_RLS                      FONT_COLOR(COLOR_HIGHT_WHITE, "[")  FONT_COLOR(COLOR_HIGHT_BLUE,    "RELEASE")   FONT_COLOR(COLOR_HIGHT_WHITE, "]")

#define LOG_TAG                         "[STM32]"
#define INFO_TAG                        "[%s][%d][%s]"
#define STM32_LOG_ERR(fmt, ...)         debug_printf(LOG_TAG TARGET_ERR INFO_TAG fmt, __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__)
#define STM32_LOG_WAR(fmt, ...)         debug_printf(LOG_TAG TARGET_WAR INFO_TAG fmt, __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__)
#define STM32_LOG_DEB(fmt, ...)         debug_printf(LOG_TAG TARGET_DEB INFO_TAG fmt, __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__)
#define STM32_LOG_INFO(fmt, ...)        debug_printf(LOG_TAG TARGET_INFO INFO_TAG fmt, __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__)
#define STM32_LOG_FAIL(fmt, ...)        debug_printf(LOG_TAG TARGET_FAIL INFO_TAG fmt, __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__)

#define STM32_LOG_COLOR_D(color, fmt, ...)  debug_printf(FONT_ ## color(fmt), ##__VA_ARGS__)
#define STM32_LOG_COLOR_R(color, fmt, ...)  printf(FONT_ ## color(fmt), ##__VA_ARGS__)

#define STM32_LOG_RLS(fmt, ...)         printf(LOG_TAG TARGET_RLS INFO_TAG fmt, __FILE__, __LINE__, ##__VA_ARGS__)

#endif