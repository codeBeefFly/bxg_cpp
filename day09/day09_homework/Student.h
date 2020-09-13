#pragma once

#include <iostream>
#include "Human.h"
#include "Teacher.h"

class Student : public Human
{

public:
	//std::string name;	// �������ж��壬���Բ����ٴζ�����
	int age;
	Gender gender;
	
	std::shared_ptr<Teacher> sp_teacher;

	Student();
	Student(std::string name, int age, Gender gender);
	~Student();

	void setTeacher(std::shared_ptr<Teacher> sp_t);

};

