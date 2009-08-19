/**
 * Copyright(c) 2009 Cnangel, All Rights Reserved.
 * 
 * @file uctf.cpp
 * @details uc test
 * @author cnangel
 * @version 1.0.0
 * @date 2009/08/19 17:25:16
 */

#include <stdlib.h>
#include "uctf.h"

using namespace sme;

CPPUNIT_TEST_SUITE_REGISTRATION(SmeUrlTF);

void SmeUrlTF::setUp() {

}

void SmeUrlTF::tearDown() {

}

void SmeUrlTF::testInit() {
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

