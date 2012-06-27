#include "StdAfx.h"
#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TextTestProgressListener.h>

#include "AbstractBaseGraphTest.hpp"

int mainz()//int argc, char* argv[] waren parameter im original
{
	CppUnit::TestCaller<AbstractBaseGraphTest> test( "testKonstruktor",
	                                             &AbstractBaseGraphTest::testKonstruktor );

	CppUnit::TextUi::TestRunner runner;
	runner.addTest(AbstractBaseGraphTest::suite());

	runner.run();





return 0;
#if 0
	CppUnit::TextUi::TestRunner runner;
	CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
	runner.addTest( registry.makeTest() );
	runner.run();

	return 0;
#endif


#if 0
  // Get the top level suite from the registry
  CPPUNIT_NS::Test *suite = CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest();

  // Adds the test to the list of test to run
  CPPUNIT_NS::TextUi::TestRunner runner;


  CppUnit::TestResult controller;
  CppUnit::TestResultCollector result;

  controller.addListener( &result );

//  CppUnit::TextTestProgressListener progress;
//  controller.addListener( &progress );


  runner.addTest( suite );
  runner.addTest( AbstractBaseGraphTest::suite() );
  // Change the default outputter to a compiler error format outputter
  runner.setOutputter( new CPPUNIT_NS::CompilerOutputter( &runner.result(),
                                                          CPPUNIT_NS::stdCOut() ) );


  // Run the test.
  runner.run(controller,"");


  CppUnit::CompilerOutputter outputter( &result, std::cerr );

  outputter.write();

  // Return error code 1 if the one of test failed.
  return result.wasSuccessful() ? 0 : 1;
#endif
}
