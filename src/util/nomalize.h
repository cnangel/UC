/**
 * Copyright(c) 2009 Cnangel, All Rights Reserved.
 * 
 * @file nomalize.h
 * @details lower and upper
 * @author cnangel
 * @version 1.0.0
 * @date 2010/01/06 23:00:38 
 */
#ifndef __UTIL_NOMALIZE_H__
#define __UTIL_NOMALIZE_H__

#include <string.h>
#include <stdlib.h>

/**
 * a string is changed string of lowercase 
 * @param str the string which want to change.
 * @param strLen the length of str
 * @return 1 if fail; otherwise, return 0.
 */
extern int lcchar(char *str, size_t strLen);

/**
 * a string is changed capital letters
 * @param str the string which want to change.
 * @param strLen the length of str
 * @return 1 if fail; otherwise, return 0.
 */
extern int ucchar(char *str, size_t strLen);

#endif //__UTIL_NOMALIZE_H__

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */

