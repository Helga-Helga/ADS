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
#include "../src/queueArray.hpp"

using namespace CppUnit;
using namespace std;

class TestContainer : public CppUnit::TestFixture {
    CPPUNIT_TEST_SUITE(TestContainer);
    CPPUNIT_TEST(testPushAndPop);
    CPPUNIT_TEST(testContainer);
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp(void);
    void tearDown(void);

protected:
    void testPushAndPop(void);
    void testContainer(void);

private:
    Container<int> **containers;
    int containersCount;
};

void TestContainer::setUp(void) {
    this->containersCount = 2;
    this->containers = new Container<int>*[this->containersCount];
    this->containers[0] = new StackArray<int>();
    this->containers[1] = new QueueArray<int>();
}

void TestContainer::tearDown(void) {
	for (int i = 0; i < this->containersCount; i++) {
		delete this->containers[i];
	}
    delete[] this->containers;
}

void TestContainer::testPushAndPop(void) {
	for (int i = 0; i < this->containersCount; i++) {
	    this->containers[i]->push(1);
	    CPPUNIT_ASSERT_EQUAL(1, this->containers[i]->pop());
	}
    
}

void TestContainer::testContainer(void) {
    for (int i = 0; i < this->containersCount; i++) {
	    this->containers[i]->push(1);
	    CPPUNIT_ASSERT_EQUAL(1, this->containers[i]->pop());
	    this->containers[i]->push(2);
	    CPPUNIT_ASSERT_EQUAL(2, this->containers[i]->pop());
	}
}

CPPUNIT_TEST_SUITE_REGISTRATION( TestContainer );
