#pragma once

#include <iostream>
#include <vector>

class Student
{
public:
	std::string* name = nullptr;
	std::vector<int> score_vector;

	Student();
	Student(std::string* name);
	Student(std::string* name, std::vector<int> score_vector);	// 这是什么问题

	//拷贝构造函数，写成深拷贝
	Student(const Student& stu);

	//void putScore(std::vector<int> score_vector);

	// 一步到位，通过构造函数的方式来创建学生

	//void updateScore(std::vector<int> score_vector);
	void updateScore(void (*score_fun)());
	//void showInfo(std::vector<int> score_vector);
	void showInfo();

private:
	void update2Sixty_default();

};

