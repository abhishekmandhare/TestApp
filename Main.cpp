// TestApp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Grader.h"

#include <iostream>
using namespace std;


int _tmain(int argc, char** argv)
{

	if (argc < 2)
	{
		cout << "Please provide name in command line argument";
		return 1;
	}
 
	Grader grader(argv[1]);
	grader.StartGrading();
	return 0;
}

