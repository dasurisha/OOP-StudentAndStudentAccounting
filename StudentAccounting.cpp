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
		cout << "Студент получает стипендию." << endl;
		return true;
	}
	else {
		cout << "Студент не получает стипендию." << endl;
		return false;
	}
}

void StudentAccounting::showStudentInfo(Student& student) {
	cout << "Имя: " << student.name << endl;
	cout << "Возраст: " << student.age << endl;
	cout << "Группа: " << student.group << endl;
	cout << "Факультет: " << student.faculty << endl;
	cout << "Все оценки: "; student.getGrades();
	cout << endl;
	cout << "Средний бал: " << calculateAverageScore(student) << endl;
	cout << "Стипендия: "; getScholarship(student);
}