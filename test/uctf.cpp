/**
 * Copyright(c) 2010 Cnangel, All Rights Reserved.
 * 
 * @file uctf.cpp
 * @details uc test
 * @author cnangel
 * @version 1.0.0
 * @date 2010/01/06 23:51:20
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

