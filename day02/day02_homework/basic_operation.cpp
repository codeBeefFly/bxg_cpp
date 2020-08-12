#include <iostream>
#include "basic_operation.h"

void initScore(std::vector<std::vector<int>> & score_vector) {
	/// 使用角标的 for 进行值的录入
	std::cout << "..in initScore..\n";
	int tmp_mark{ 0 };
	std::vector<int> mark_line;		// empty vector of ints
	for (int i = 0; i < 3; i++) {
		std::cout << "..for student [" << i + 1 << "], enter marks...\n";
		mark_line.clear();			// Removes all elements from the vector (which are destroyed), leaving the container with a size of 0.
		for (int j = 0; j < 6; j++) {
			std::cout << "..enter subject [" << j + 1 << "] mark :: ";
			std::cin >> tmp_mark;
			mark_line.push_back(tmp_mark);
		}
		score_vector.push_back(mark_line);
	}
}

void updateScore(std::vector<std::vector<int>> & score_vector) {
	/// 使用范围 for 遍历，并用 & 修改
	std::cout << "..in updateScore..\n";
	for (std::vector<int> & mark_line : score_vector) {
		for (int & mark : mark_line) {
			if (mark < 60) {
				mark = 60;
			}
		}
	}
}

void printScore(std::vector<std::vector<int>> & score_vector) {
	std::cout << "..in printScore..\n";
	int student_index{ 0 };
	for (std::vector<int> mark_line : score_vector) {
		student_index++;
		std::cout << "..for student [" << student_index << "], marks are :: ";
		for (int mark : mark_line) {
			std::cout << mark << "\t";
		}
		std::cout << "\n";
	}
}
