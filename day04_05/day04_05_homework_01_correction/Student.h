#pragma once

#include <iostream>
#include <vector>


class Student
{

public:
	std::string* name = nullptr;
	std::vector<int> score_vector;

	Student();
	Student(std::string name);
	Student(std::string name, std::vector<int> score_vector);
	~Student();

	Student(const Student& stu);

	void updateScore();
	void showInfo();

};

