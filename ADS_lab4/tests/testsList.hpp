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
#include "../src/list.hpp"

using namespace CppUnit;
using namespace std;

class TestList : public CppUnit::TestFixture {
    CPPUNIT_TEST_SUITE(TestList);
    CPPUNIT_TEST(testInsertAndRemove);
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp(void);
    void tearDown(void);

protected:
    void testInsertAndRemove(void);

private:
    List<int> *list;
};

void TestList::setUp(void) {
    this->list = new List<int>();
}

void TestList::tearDown(void) {
    delete this->list;
}

void TestList::testInsertAndRemove(void) {
    this->list->insert(1, true);
    CPPUNIT_ASSERT_EQUAL(1, this->list->remove());
    this->list->insert(1, false);
    this->list->insert(2, true);
    CPPUNIT_ASSERT_EQUAL(1, this->list->remove());
}

CPPUNIT_TEST_SUITE_REGISTRATION( TestList );
