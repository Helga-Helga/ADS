#include <iostream>
#include <string>
#include <cppunit/TestCase.h>
#include <cppunit/TestFixture.h>
#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/CompilerOutputter.h>
#include "../src/stackArray.hpp"
#include "../src/postfixForm.hpp"

using namespace CppUnit;
using namespace std;

class TestPostfixForm : public CppUnit::TestFixture {
    CPPUNIT_TEST_SUITE(TestPostfixForm);
    CPPUNIT_TEST(test);
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp(void);
    void tearDown(void);

protected:
    void test(void);

private:
    
};

void TestPostfixForm::setUp(void) {
    
}

void TestPostfixForm::tearDown(void) {
    
}

void TestPostfixForm::test(void) {
    double values[] = {1, 2, 3, 1, 2, 6};
    CPPUNIT_ASSERT_DOUBLES_EQUAL(2, calc(values), 0.1);
}

CPPUNIT_TEST_SUITE_REGISTRATION( TestPostfixForm);
