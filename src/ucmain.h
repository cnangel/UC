/**
 * Copyright(c) 2009 Cnangel, All Rights Reserved.
 * 
 * @file ucmain.h
 * @details for uc template 
 * @author cnangel
 * @version 1.0.0
 * @date 2009/08/19 16:34:35 
 */

#ifndef __UCMAIN_H__
#define __UCMAIN_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <string.h>
#include <stdlib.h>

/**
 * a string do something
 * @param src the origin input string 
 * @param desc the output string
 * @param flag method or action
 * @return 1 if fail; otherwise, return 0.
 */
extern int helloworld(const char *src, char *desc, int flag);

#ifdef __cplusplus
 }
#endif

#endif //__UCMAIN_H__

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */

