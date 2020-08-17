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
		std::string&& name,							// ������ֵ����
		std::string&& id,							// ������ֵ����
		std::vector<int>& score_vector,				// ������ֵ����
		std::vector<student*>* student_vector
		)
);

void updateScore(std::vector<student*>*, void (*update_ptr)(int*));		// ��������+����ָ��

void printScore(std::vector<student*>*, void (*print_ptr)(std::vector<student*>*));