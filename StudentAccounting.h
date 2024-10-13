#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Student;

class StudentAccounting
{
public:
	double calculateAverageScore(Student& student);
	void showStudentInfo(Student& student);
	bool getScholarship(Student& student);
};

