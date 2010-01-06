/**
 * Copyright(c) 2010 Cnangel, All Rights Reserved.
 * 
 * @Filename: uctf.cpp
 * @Description:
 * @Author: cnangel
 * @Version: 1.0.0
 * @Time: 2010/01/06 22:52:13
 */

#include <stdlib.h>
#include "uctf.h"

using namespace uc;

CPPUNIT_TEST_SUITE_REGISTRATION(UCTF);

void UCTF::setUp() {

}

void UCTF::tearDown() {

}

void UCTF::testInit() {
	char *str = (char *)malloc(128);
	CPPUNIT_ASSERT(str);
	int ret = helloworld("HHH", str, 0);
	CPPUNIT_ASSERT_EQUAL(0, ret);
	free(str);
}


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */

