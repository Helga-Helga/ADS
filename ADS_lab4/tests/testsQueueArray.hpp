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
#include "../src/queueArray.hpp"

using namespace CppUnit;
using namespace std;

class TestQueueArray : public CppUnit::TestFixture {
    CPPUNIT_TEST_SUITE(TestQueueArray);
    CPPUNIT_TEST(testCircularity);
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp(void);
    void tearDown(void);

protected:
    void testCircularity(void);

private:
    QueueArray<int> *queue;
};

void TestQueueArray::setUp(void) {
    this->queue = new QueueArray<int>[1];
}

void TestQueueArray::tearDown(void) {
    delete[] this->queue;
}

void TestQueueArray::testCircularity(void) {
    for (int i = 0; i<80; i++) {
        this->queue->push(i);
        CPPUNIT_ASSERT_EQUAL(i, this->queue->pop());
    }
}

CPPUNIT_TEST_SUITE_REGISTRATION( TestQueueArray );
