#include "stdafx.h"
#include "Grader.h"

#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

Grader::Grader(string filename):
    m_filename(filename)
{
    //ctor
}
void Grader::StartGrading()
{
	if (ReadFile())
	{
		WriteFile();
	}
}
bool Grader::ReadFile()
{
	try
	{
		ifstream infile;

		infile.open(m_filename, ifstream::in);

		if (!infile.is_open())
		{
			cout << "Unable to open the file for reading " << endl;
			return false;
		}
		string line;
		StudentData data;
		while (getline(infile, line))
		{
			if (line == "" || line == "\n") break;
			vector<string> result;
			parseCommaSeperatedStr(line, result);

			if (result.size() == 3)
			{
				data.last_name = result[0];
				data.first_name = result[1];
				data.score = atoi(result[2].c_str());
			}
			else
			{
				cout << "Unable to parse. Please check the input file";
				return false;
			}
			//This will auto sort during insertion as per the comparator function we provided for set
			m_data.insert(data);
		}
		infile.close();
		return true;

	}
	catch (exception& ex)
	{
		cout << "Exception while reading file : " << ex.what() << endl;
	}
	return false;
}
bool Grader::WriteFile()
{
	try
	{

		ofstream outfile;

		//Prepare the file name
		string rawname = m_filename;
		string extension = "";
		size_t lastdot = m_filename.find_last_of(".");
		if (lastdot != std::string::npos)
		{
			rawname = m_filename.substr(0, lastdot);
			extension = m_filename.substr(lastdot, m_filename.size());
		}

		string filename = rawname + "-graded" + extension;

		//Open the file
		outfile.open(filename, ofstream::trunc);

		if (!outfile.is_open())
		{
			cout << "Unable to open the file for writing" << endl;
			return false;
		}

		for (studentList::iterator it = m_data.begin(); it != m_data.end(); ++it)
		{
			cout << it->last_name << ", " << it->first_name << ", " << it->score << "\n";
			outfile << it->last_name << ", " << it->first_name << ", " << it->score << "\n";
		}
		cout << "Finished: created " << filename << endl;
		outfile.close();
		return true;
	}
	catch (exception& ex)
	{
		cout << "Exception while writing file : " << ex.what() << endl;
	}
	return false;
}
Grader::~Grader()
{
    //dtor
}

void Grader::parseCommaSeperatedStr(string& input, vector<string>& output)
{
	char* context = NULL;
	char* charLine = const_cast<char*>(input.c_str());
	
	char* tok = strtok_s(charLine, ",", &context);
	while (tok != NULL)
	{
		string token(tok);
		//Remove spaces
		token.erase(remove(token.begin(), token.end(), ' '), token.end());

		output.push_back(token);
		tok = strtok_s(NULL, ",", &context);
	}
}