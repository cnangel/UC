/**
 * Copyright(c) 2009 Cnangel, All Rights Reserved.
 * 
 * @file uctf.h
 * @details uc test 
 * @author cnangel
 * @version 1.0.0
 * @date 2009/08/19 17:23:57
 */

#ifndef __UC_UCTF_H__
#define __UC_UCTF_H__

#include <cppunit/extensions/HelperMacros.h>

extern "C" {
#include <uc.h>
}

namespace sme
{
	class SmeUrlTF : public CppUnit::TestFixture {

		CPPUNIT_TEST_SUITE(SmeUrlTF);
		CPPUNIT_TEST(testInit);
		CPPUNIT_TEST_SUITE_END();

		public:
		void setUp();
		void tearDown();
		void testInit();
	};
};

#endif 

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */

