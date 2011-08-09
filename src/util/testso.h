/**
 * Copyright(c) 2010 Cnangel, All Rights Reserved.
 * 
 * @file nomalize.h
 * @details lower and upper, and only for child directory test
 * @author cnangel
 * @version 1.0.0
 * @date 2010/01/06 23:54:12
 */

#ifndef __UTIL_TESTSO_H__
#define __UTIL_TESTSO_H__

#include <string.h>
#include <stdlib.h>

namespace so
{

class SoTest
{
public:
	SoTest(){}
	~SoTest(){}

public:
/**
 * a string is changed string of lowercase 
 * @param str the string which want to change.
 * @param strLen the length of str
 * @return 1 if fail; otherwise, return 0.
 */
int lcchar(char *str, size_t strLen);

/**
 * a string is changed capital letters
 * @param str the string which want to change.
 * @param strLen the length of str
 * @return 1 if fail; otherwise, return 0.
 */
int ucchar(char *str, size_t strLen);

};

}

#endif 

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */

