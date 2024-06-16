#ifndef _CONFIG_H_
#define _CONFIG_H_

#if defined(__STM32F103)
	#define USER_FIRM		    STM32F103
	#define USER_PRODUCT		Demo
#elif defined(__STM32L475)
	#define USER_FIRM			STM32L475
    #define USER_PRODUCT		Demo
#elif
	#pragma message("unkown error")
#endif


#if !defined(USER_FIRM)
	#error("no defined USER_FIRM")
#elif !defined(USER_PRODUCT)
	#error("no defined no defined USER_FIRM")
#else
	#define USER_CONFIG_DIR									USER_FIRM/USER_PRODUCT
#endif

#define  USER_INIT_H										<../config/Consumer/USER_CONFIG_DIR/UserInit.h>
#include USER_INIT_H

#endif /* _CONFIG_H_ */

