#pragma once

#include <string>
#include <vector>

// �����ṹ��, declare a structure
struct student {
	std::string name{ "" };
	std::string id{ "" };
	std::vector<int> scores;
};


// ��������, declare functions
int initScore(std::vector<student*> & stu_vector);
int updateScore(std::vector<student*> & stu_vector);
int printScore(std::vector<student*> & stu_vector);