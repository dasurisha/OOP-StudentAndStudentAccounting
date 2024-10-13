#include "Student.h"
#include "StudentAccounting.h"

double StudentAccounting::calculateAverageScore(Student& student) {
	if (student.grades.empty()) {
		return 0.0;
	}
	double sum{};
	for (int grade : student.grades) {
		sum += grade;
	}
	return sum / student.grades.size();
}

bool StudentAccounting::getScholarship(Student& student) {
	if (StudentAccounting::calculateAverageScore(student) > 4.2) {
		cout << "������� �������� ���������." << endl;
		return true;
	}
	else {
		cout << "������� �� �������� ���������." << endl;
		return false;
	}
}

void StudentAccounting::showStudentInfo(Student& student) {
	cout << "���: " << student.name << endl;
	cout << "�������: " << student.age << endl;
	cout << "������: " << student.group << endl;
	cout << "���������: " << student.faculty << endl;
	cout << "��� ������: "; student.getGrades();
	cout << endl;
	cout << "������� ���: " << calculateAverageScore(student) << endl;
	cout << "���������: "; getScholarship(student);
}