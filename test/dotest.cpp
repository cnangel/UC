/**
 * Copyright(c) 2009 Cnangel, All Rights Reserved.
 * 
 * @file dotest.cpp
 * @details test main programe
 * @author cnangel
 * @version 1.0.0
 * @date 2009/08/19 17:11:41 
 */

#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/CompilerOutputter.h>
#include <signal.h>

using namespace CppUnit;
using namespace std;

int main(int argc, char* argv[])
{
	signal(SIGPIPE, SIG_IGN);
	TextUi::TestRunner runner;
	CompilerOutputter *outputter = new CompilerOutputter(&runner.result(), cerr);
	runner.setOutputter(outputter);
	TestFactoryRegistry &registry = TestFactoryRegistry::getRegistry();
	runner.addTest( registry.makeTest() );
	return runner.run("", false) ? 0 : 1;
}
