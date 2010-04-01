/**
 * Copyright(c) 2010 Cnangel, All Rights Reserved.
 * 
 * @file ucmain.c
 * @details for test only
 * @author cnangel
 * @version 1.0.0
 * @date 2010/01/06 23:45:40 
 */

#include <common.h>
#include <util/nomalize.h>

/* desc must relocate space, otherwise not safe */
int 
helloworld(const char *src, char *desc, int flag)
{
	size_t srcLen = strlen(src);
	if (srcLen == 0) return 1;
	strncpy(desc, src, srcLen);
	strcat(desc, ", hello, world!");
	if (flag == 1) {
		lcchar(desc, strlen(desc));
	} else if (flag == 0) {
		ucchar(desc, strlen(desc));
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

