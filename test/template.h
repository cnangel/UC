/**
 * Copyright(c) 2010 Cnangel, All Rights Reserved.
 * 
 * @Filename: template.h
 * @Description:
 * @Author: cnangel
 * @Version: 1.0.0
 * @Time: 2010/01/06 22:49:25
 */

#ifndef __UC_TEMPLATE_H__
#define __UC_TEMPLATE_H__

#include <cppunit/extensions/HelperMacros.h>
#include <uc.h>

namespace uc
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

