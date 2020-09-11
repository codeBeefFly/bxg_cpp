#pragma once

#include <iostream>
#include <vector>
#include "Teacher.h"

class Student
{
private:

	//friend std::istream& operator>>(std::istream& in, Student& student);	// TODO
	friend std::istream& operator>>(std::istream& in, Student& student);
	friend std::ostream& operator<<(std::ostream& out, Student& student);

public:
	std::string name;
	std::string id;

	Teacher* teacher = nullptr;

	Student();
	Student(std::string name, std::string id, Teacher* teacher);
	~Student();

};

