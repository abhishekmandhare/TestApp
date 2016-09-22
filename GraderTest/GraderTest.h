#pragma once

#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>
#include <vector>
//#include <cppunit/TestFixture.h>
#include "Grader.h"

class GraderTest : public CPPUNIT_NS::TestFixture
{
	CPPUNIT_TEST_SUITE(GraderTest);
	
	CPPUNIT_TEST(testRead);
	CPPUNIT_TEST(testWrite);
	
	CPPUNIT_TEST_SUITE_END();
public:
	GraderTest();
	~GraderTest();
	virtual void setUp();
protected:
	void testRead();
	void testWrite();
private:
	std::vector<StudentData> m_testResult;
};

