/**
 * Copyright(c) 2009 Cnangel, All Rights Reserved.
 * 
 * @file nomalize.c
 * @details only for child directory test
 * @author cnangel
 * @version 1.0.0
 * @date 2009/08/19 17:14:02
 */

#include <nomalize.h>

int lc(char *str, size_t strLen)
{
	if (strLen == 0) return 1;
	int i = 0;
	for (; i < strLen; i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			str[i] = str[i] + ' ';
		}
	}
	return 0;
}

int uc(char *str, size_t strLen)
{
	if (strLen == 0) return 1;
	int i = 0;
	for (; i < strLen; i++) {
		if (str[i] >= 'a' && str[i] <= 'z') {
			str[i] = str[i] - ' ';
		}
	}
	return 0;
}

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */

