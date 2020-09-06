#ifndef DAY07_HOMEWORK_STUDENT_H
#define DAY07_HOMEWORK_STUDENT_H


#include <iostream>
#include "teacher.h"

class Student {
public:

	std::string name;
	std::string id;
	Teacher* teacher = nullptr;

	Student() = default;
	Student(std::string name, std::string id, Teacher* teacher);
	~Student();

};



#endif // !DAY07_HOMEWORK_STUDENT_H