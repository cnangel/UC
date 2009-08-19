/**
 * Copyright(c) 2009 Cnangel, All Rights Reserved.
 * 
 * @file template.cpp
 * @details template for test
 * @author cnangel
 * @version 1.0.0
 * @date 2009/08/19 17:15:27
 */

#ifndef __SME_TEMPLATE_H__
#define __SME_TEMPLATE_H__

#include <cppunit/extensions/HelperMacros.h>
#include <sme.h>

namespace sme
{
	class TemplateTF : public CppUnit::TestFixture {

		CPPUNIT_TEST_SUITE(TemplateTF);
		CPPUNIT_TEST(testTemplate);
		CPPUNIT_TEST_SUITE_END();

		public:
		void setUp();
		void tearDown();
		void testTemplate();
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

