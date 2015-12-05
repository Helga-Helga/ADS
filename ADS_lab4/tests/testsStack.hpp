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

using namespace CppUnit;
using namespace std;

class TestStack : public CppUnit::TestFixture {
    CPPUNIT_TEST_SUITE(TestStack);
    CPPUNIT_TEST(testPushAndPop);
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp(void);
    void tearDown(void);

protected:
    void testPushAndPop(void);

private:
    Stack<int> **stacks;
    int stacksCount;
};

void TestStack::setUp(void) {
    this->stacksCount = 3;
    this->stacks = new Stack<int>*[this->stacksCount];
    this->stacks[0] = new StackArray<int>();
    this->stacks[1] = new StackArray<int>((StackArray<int>*)(this->stacks[0]));
    this->stacks[2] = new StackList<int>();
}

void TestStack::tearDown(void) {
    for (int i = 0; i < this->stacksCount; i++) {
        delete this->stacks[i];
    }
    delete[] this->stacks;
}

void TestStack::testPushAndPop(void) {
    for (int i = 0; i < this->stacksCount; i++) {
        this->stacks[i]->push(2*i);
        this->stacks[i]->push(3*i);
        CPPUNIT_ASSERT_EQUAL(3*i, this->stacks[i]->pop());
        CPPUNIT_ASSERT_EQUAL(2*i, this->stacks[i]->pop());
    }
}

CPPUNIT_TEST_SUITE_REGISTRATION( TestStack );
