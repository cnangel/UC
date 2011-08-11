/**
 * Copyright(c) 2010 Cnangel, All Rights Reserved.
 * 
 * @file nomalize.c
 * @details lower and upper, and only for child directory test
 * @author cnangel
 * @version 1.0.0
 * @date 2010/01/06 23:54:39
 */

#include <util/testso.h>

namespace so
{

int SoTest::lcchar(char *str, size_t strLen)
{
	if (strLen == 0) return 1;
	size_t i = 0;
	for (; i < strLen; i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			str[i] = str[i] + ' ';
		}
	}
	return 0;
}

int SoTest::ucchar(char *str, size_t strLen)
{
	if (strLen == 0) return 1;
	size_t i = 0;
	for (; i < strLen; i++) {
		if (str[i] >= 'a' && str[i] <= 'z') {
			str[i] = str[i] - ' ';
		}
	}
	return 0;
}

}

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */

