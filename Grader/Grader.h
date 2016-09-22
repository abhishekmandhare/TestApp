#ifndef Grader_H
#define Grader_H

#include <string>
#include <set>
#include <vector>

struct StudentData
{
    std::string first_name;
    std::string last_name;
    int score;

};

struct comparatorFunc 
{
public:
	bool operator()(const StudentData& d1, const StudentData& d2) const
	{
		if (d1.score == d2.score)
		{
			if (d1.last_name == d1.last_name)
			{
				if (d1.first_name > d2.first_name)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			else if (d1.last_name > d2.last_name)
			{

				return true;
			}
			else
			{
				return false;
			}

		}
		else if (d1.score > d2.score)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};
typedef std::set<StudentData, comparatorFunc> studentList;
class Grader
{
    public:
        Grader(std::string filename);
        ~Grader();

		void StartGrading();
		bool ReadFile();
		bool WriteFile();

		const studentList& GetList()
		{
			return m_data;
		}
    private:

        std::string m_filename;
		
		studentList m_data;
		
		
		void parseCommaSeperatedStr(std::string& input, std::vector<std::string>& output);
};

#endif // Grader_H
