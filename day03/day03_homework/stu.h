#pragma once

#include <string>
#include <vector>

// �����ṹ��
struct student {
	std::string name{ "" };
	std::string id{ "" };
	std::vector<int> scores;
};


// ��������
int initScore(std::vector<student*> & stu_vector);
int updateScore(std::vector<student*> & stu_vector);
int printScore(std::vector<student*> & stu_vector);