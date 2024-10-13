//#include "Car.h"
//#include "CarService.h"
//using namespace std;
//
//int main() {
//	setlocale(0, "ru");
//
//	string name; cout << "Введите Название своей машины: "; cin >> name;
//	Car car1 = Car(name);
//	cout << "Сумма за ремонт: " << CarService::getRepairCost(car1) << endl;
//
//	string name2; cout << "Введите Название своей машины: "; cin >> name2;
//	Car car2 = Car(name2);
//	cout << "Сумма за ремонт: " << CarService::getRepairCost(car2) << endl;
//
//	cout << boolalpha << (car1 < car2);
//}


#pragma once

#include "StudentAccounting.h"
#include "Student.h"
#include <iostream>
#include <gtest/gtest.h>
using namespace std;
TEST(StudentAccountingTest, calculateAverageScoreTest) {
	//Arrange
	Student student1("Bob", 18, "319IT-22", "IT");
	StudentAccounting accounting;
	//Act
	student1.addGrades(4);
	student1.addGrades(5);
	student1.addGrades(4);
	student1.addGrades(5);
	student1.addGrades(5);
	student1.addGrades(4);
	//Assert
	ASSERT_EQ(accounting.calculateAverageScore(student1), 4.5);
}

TEST(StudentAccountingTest, addGradesGetException) {
	//Arrange
	Student student1("Mike", 20, "401IT-20", "IT");
	//Act
	try {
		student1.addGrades(0);
	}
	catch (invalid_argument& ex) {
		//Assert
		ASSERT_STREQ("The user is trying to enter non-existent numbers.", ex.what());
	}
}

TEST(StudentAccountingTest, studentNotGetScholarshipTest) {
	//Arrange
	Student student1("Mike", 20, "401IT-20", "IT");
	StudentAccounting accounting;
	//Act
	student1.addGrades(4);
	student1.addGrades(4);
	student1.addGrades(5);
	student1.addGrades(5);
	student1.addGrades(3);
	student1.addGrades(3);
	student1.addGrades(2);
	accounting.calculateAverageScore(student1);
	//Assert
	ASSERT_FALSE(accounting.getScholarship(student1));
}

TEST(StudentAccountingTest, studentGetScholarshipTest) {
	//Arrange
	Student student1("Mike", 20, "401IT-20", "IT");
	StudentAccounting accounting;
	//Act
	student1.addGrades(4);
	student1.addGrades(4);
	student1.addGrades(5);
	student1.addGrades(5);
	student1.addGrades(5);
	student1.addGrades(5);
	student1.addGrades(5);
	accounting.calculateAverageScore(student1);
	//Assert
	ASSERT_TRUE(accounting.getScholarship(student1));
}

#define ACTIONS 1

int main(int argc, char* argv[])
{
#if ACTIONS == 1
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
#endif

#if ACTIONS == 2
	setlocale(0, "ru");
	string name; cout << "Введите имя студента:"; cin >> name;
	int age; cout << "Введите возраст студента:"; cin >> age;
	string group; cout << "Введите группу студента:"; cin >> group;
	string faculty; cout << "Введите факультет студента:"; cin >> faculty;
	Student student1 = Student(name, age, group, faculty);
	student1.addGrades(4);
	student1.addGrades(4);
	student1.addGrades(5);
	student1.addGrades(5);
	student1.addGrades(3);
	student1.addGrades(3);
	student1.addGrades(2);
	StudentAccounting accounting;
	cout << endl;
	accounting.showStudentInfo(student1);
#endif
}
