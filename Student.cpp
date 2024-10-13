#include "Student.h"

void Student::addGrades(int grade) {
	if (grade < 1 || grade > 5) {
		throw invalid_argument("The user is trying to enter non-existent numbers.");
	}
	grades.push_back(grade);
}

void Student::getGrades() {
	for (int grade : grades) {
		cout << grade << " ";
	}
}
