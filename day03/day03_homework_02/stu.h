#pragma once

#include <iostream>
#include <vector>


struct student {
	std::string name;
	std::string id;
	std::vector<int> score_vector;
};


void initStudent(
	std::string&& name,
	std::string&& id,
	std::vector<int>& score_vector,
	std::vector<student*>* stu_vector
);

void initScore(
	std::vector<student*>* student_vector,
	void (*initStudent_ptr)(
		std::string&& name,							// 需求：右值引用
		std::string&& id,							// 需求：右值引用
		std::vector<int>& score_vector,				// 需求：左值引用
		std::vector<student*>* student_vector
		)
);

void updateScore(std::vector<student*>*, void (*update_ptr)(int*));		// 传递容器+函数指针

void printScore(std::vector<student*>*, void (*print_ptr)(std::vector<student*>*));