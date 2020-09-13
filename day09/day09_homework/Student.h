#pragma once

#include <iostream>
#include "Human.h"
#include "Teacher.h"

class Student : public Human
{

public:
	//std::string name;	// 父类中有定义，可以不用再次定义了
	int age;
	Gender gender;
	
	std::shared_ptr<Teacher> sp_teacher;

	Student();
	Student(std::string name, int age, Gender gender);
	~Student();

	void setTeacher(std::shared_ptr<Teacher> sp_t);

};

