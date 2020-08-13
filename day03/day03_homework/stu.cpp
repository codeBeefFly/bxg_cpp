#include <iostream>
#include "stu.h"

int initScore(std::vector<student*> & stu_vector) {
	
	std::cout << "..in initScore()...\n";
	
	// ʹ�ýű�for���гɼ�����
	for (int i = 0; i < 3; i++) {
		student* stu = new student;		// �ڶ��ڴ洴��һ��student���Ͷ��󣬲���*stuָ��ָ������ڴ�ռ�
		
		std::cout << "..enter student [" << i + 1 << "]'s name :: ";
		std::cin >> (*stu).name;		// ָ������ã��õ�student���󣬶���.�����Ա

		std::cout << "...enter student [" << i + 1 << "]'s id :: ";
		std::cin >> (*stu).id;

		//std::vector<int> tmp_line_mark;
		for (int j = 0; j < 6; j++) {
			std::cout << "...enter subject [" << j + 1 <<"]'s mark :: ";
			int tmp_mark;
			std::cin >> tmp_mark;
			(*stu).scores.push_back(tmp_mark);
		}
		stu_vector.push_back(stu);
	}
	return 0;
}


int updateScore(std::vector<student*> & stu_vector) {

	std::cout << "..in updateScore()...\n";

	for (student* stu : stu_vector) {
		for (int& mark : (*stu).scores) {
			if (mark < 60)
				mark = 60;
		}
	}

	return 0;
}


int printScore(std::vector<student*> & stu_vector) {

	std::cout << "..in printScore()...\n";

	int student_index{ 0 };
	for (student* stu : stu_vector) {
		student_index++;
		std::cout << "..student [" << student_index << "] mark list ::\t";
		for (int mark : (*stu).scores) {
			std::cout << mark << "\t";
		}
		std::cout << "\n";
	}

	return 0;
}