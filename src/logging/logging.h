//
// Created by Andres O. Vela on 14/07/21.
//

#ifndef TEMPLATE_LOGGING_H
#define TEMPLATE_LOGGING_H

#include <stdio.h>
#include <logging_groups.h>

#define LOG_LEVEL_OFF 			0
#define LOG_LEVEL_ERROR			1
#define LOG_LEVEL_WARNING 		2
#define LOG_LEVEL_INFO			3
#define LOG_LEVEL_DEBUG			4
#define LOG_LEVEL_TRACE			5
#define LOG_LEVEL_TRACE2 		6
#define LOG_LEVEL_HIGHLIGHT		3

#define LOG_CTRL_RESET                "[0m"         // Reset to default colors
#define LOG_CTRL_TEXT_BRIGHT_RED      "[1;31m"
#define LOG_CTRL_TEXT_BRIGHT_GREEN    "[1;32m"
#define LOG_CTRL_TEXT_BRIGHT_YELLOW   "[1;33m"
#define LOG_CTRL_TEXT_BRIGHT_BLUE     "[1;34m"

#ifndef LOG_ERROR_COLOR
#define LOG_ERROR_COLOR 	LOG_CTRL_TEXT_BRIGHT_RED
#endif

#ifndef LOG_WARNING_COLOR
#define LOG_WARNING_COLOR 	LOG_CTRL_TEXT_BRIGHT_YELLOW
#endif

#ifndef LOG_INFO_COLOR
#define LOG_INFO_COLOR 		LOG_CTRL_RESET
#endif

#ifndef LOG_DEBUG_COLOR
#define LOG_DEBUG_COLOR 	LOG_CTRL_RESET
#endif

#ifndef LOG_TRACE_COLOR
#define LOG_TRACE_COLOR 	LOG_CTRL_RESET
#endif

#ifndef LOG_TRACE2_COLOR
#define LOG_TRACE2_COLOR 	LOG_CTRL_RESET
#endif

#ifndef LOG_HIGHLIGHT_COLOR
#define LOG_HIGHLIGHT_COLOR LOG_CTRL_TEXT_BRIGHT_BLUE
#endif

#ifndef LOG_RAW_COLOR
#define LOG_RAW_COLOR 		LOG_CTRL_RESET
#endif

#ifndef __FILENAME__
#error Missing filename define: __FILENAME__ is not defined
#endif

// <e> Helper macro for log functions
#ifndef LOG_MODULE_GROUP
#error Missing log configuration: No group name is defined
#endif

#ifndef LOG_LEVEL
#error Missing log configuration: No log level is defined
#endif

#define log_internal(lvl, color, ...) do { 										\
	if (LOG_MODULE_GROUP && LOG_LEVEL >= lvl) 									\
	{																			\
		printf(color); 															\
		printf(	"%-28s:%4d: ",		 											\
			__FILENAME__, 														\
			__LINE__);			 												\
		printf(__VA_ARGS__);													\
		printf("\n");															\
	}																			\
} while( 0 )

#define log_internal_raw(lvl, ...) do{				 							\
	if (LOG_MODULE_GROUP && LOG_LEVEL >= lvl)									\
	{																			\
		printf(__VA_ARGS__ ); 													\
	}																			\
} while( 0 )

#define log_flush_internal()


#define log_error(...) 			log_internal(LOG_LEVEL_ERROR, LOG_ERROR_COLOR, __VA_ARGS__)
#define log_warning(...) 		log_internal(LOG_LEVEL_WARNING, LOG_WARNING_COLOR, __VA_ARGS__)
#define log_info(...)  			log_internal(LOG_LEVEL_INFO, LOG_INFO_COLOR, __VA_ARGS__)
#define log_debug(...)  		log_internal(LOG_LEVEL_DEBUG, LOG_DEBUG_COLOR, __VA_ARGS__)
#define log_trace(...)  		log_internal(LOG_LEVEL_TRACE, LOG_TRACE_COLOR, __VA_ARGS__)
#define log_trace2(...) 		log_internal(LOG_LEVEL_TRACE2, LOG_TRACE2_COLOR, __VA_ARGS__)
#define log_highlight(...)  	log_internal(LOG_LEVEL_HIGHLIGHT, LOG_HIGHLIGHT_COLOR, __VA_ARGS__)
#define log_raw_error(...) 		log_internal_raw(LOG_LEVEL_ERROR, __VA_ARGS__)
#define log_raw_warning(...)	log_internal_raw(LOG_LEVEL_WARNING, __VA_ARGS__)
#define log_raw_info(...)		log_internal_raw(LOG_LEVEL_INFO, __VA_ARGS__)
#define log_raw_debug(...)		log_internal_raw(LOG_LEVEL_DEBUG, __VA_ARGS__)
#define log_raw_trace(...)		log_internal_raw(LOG_LEVEL_TRACE, __VA_ARGS__)
#define log_raw_trace2(...) 	log_internal_raw(LOG_LEVEL_TRACE2, __VA_ARGS__)
#define log_raw_highlight(...)	log_internal_raw(LOG_LEVEL_HIGHLIGHT, __VA_ARGS__)

#define log_flush() 			log_flush_internal()

#endif //TEMPLATE_LOGGING_H
