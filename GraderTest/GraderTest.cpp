#include "stdafx.h"
#include "GraderTest.h"

using namespace CppUnit;
using namespace std;

GraderTest::GraderTest()
{
	
}


GraderTest::~GraderTest()
{
}
void GraderTest::setUp()
{
	StudentData data;
	data.first_name = "TERESSA";
	data.last_name = "BUNDY";
	data.score = 88;

	m_testResult.push_back(data);

	data.first_name = "MADISON";
	data.last_name = "KING";
	data.score = 88;

	m_testResult.push_back(data);

	data.first_name = "FRANCIS";
	data.last_name = "SMITH";
	data.score = 85;

	m_testResult.push_back(data);

	data.first_name = "ALLAN";
	data.last_name = "SMITH";
	data.score = 70;

	m_testResult.push_back(data);
}
void GraderTest::testRead()
{
	Grader grader("Names.txt");
	grader.ReadFile();

	const studentList& list1 = grader.GetList();

	CPPUNIT_ASSERT(list1.size() == m_testResult.size());
	int i = 0;
	for (studentList::iterator it = list1.begin(); it != list1.end(); ++it)
	{
		CPPUNIT_ASSERT(it->first_name == m_testResult[i].first_name);
		CPPUNIT_ASSERT(it->last_name == m_testResult[i].last_name);
		CPPUNIT_ASSERT(it->score == m_testResult[i].score);
		++i;
	}

}

void GraderTest::testWrite()
{
	Grader grader("Names.txt");
	grader.ReadFile();
	grader.WriteFile();

	ifstream infile;

	infile.open("Names-graded.txt", ifstream::in);

	CPPUNIT_ASSERT(infile.is_open());
	
	string line;
	StudentData data;
	getline(infile, line);
	CPPUNIT_ASSERT(line == "BUNDY, TERESSA, 88");
	getline(infile, line);
	CPPUNIT_ASSERT(line == "KING, MADISON, 88");
	getline(infile, line);
	CPPUNIT_ASSERT(line == "SMITH, FRANCIS, 85");
	getline(infile, line);
	CPPUNIT_ASSERT(line == "SMITH, ALLAN, 70");

}