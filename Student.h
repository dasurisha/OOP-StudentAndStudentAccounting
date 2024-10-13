#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Student
{
private:
	string name;
	int age;
	vector <int> grades;
	string group;
	string faculty;
	friend class StudentAccounting;
public:
	Student(const string& name, int age, const string& group, const string& faculty)
		: name(name), age(age), group(group), faculty(faculty) {}

	void addGrades(int grade);

	void getGrades();
};