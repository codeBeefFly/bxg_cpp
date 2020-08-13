#pragma once

#include <string>
#include <vector>

// 声明结构体, declare a structure
struct student {
	std::string name{ "" };
	std::string id{ "" };
	std::vector<int> scores;
};


// 声明函数, declare functions
int initScore(std::vector<student*> & stu_vector);
int updateScore(std::vector<student*> & stu_vector);
int printScore(std::vector<student*> & stu_vector);