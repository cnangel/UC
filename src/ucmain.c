/**
 * Copyright(c) 2009 Cnangel, All Rights Reserved.
 * 
 * @file ucmain.c
 * @details for test only
 * @author cnangel
 * @version 1.0.0
 * @date 2009/08/19 17:12:23
 */

#include <uc.h>
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
		lc(desc, strlen(desc));
	} else if (flag == 0) {
		uc(desc, strlen(desc));
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

