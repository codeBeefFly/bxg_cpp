#include "Student.h"


// 定义三个类构造函数
Student::Student() : Student(new std::string("unknown"), { 0 }) {	// 给 vector<int> 初始化为 0
	std::cout << "..无参构造函数...\n";
}


Student::Student(std::string* name) : Student(name, { 0 }) {
	std::cout << "..一个参数的构造函数...\n";
}


Student::Student(std::string* name, std::vector<int> score_vector) : name{ name }, score_vector{ score_vector } {
	std::cout << "..两个参数的委托构造函数...\n";
}


// 定义拷贝构造函数，深拷贝
Student::Student(const Student& stu) {
	std::cout << "..拷贝构造函数...\n";
	std::cout << &stu << "\n";
	std::cout << stu.name << "\n";			
	std::cout << *(stu.name) << "\n";
	
	name = new std::string;
	name = stu.name;
	score_vector = stu.score_vector;

}


// 定义updateScore
//void Student::updateScore(std::vector<int> score_vector) {
//	std::cout << "..更新分数函数...\n";
//}


void Student::updateScore(void (*score_fun)()) {
	std::cout << "..更新分数...\n";

	if (*score_fun != nullptr)
		score_fun();
	else {
		update2Sixty_default();
	}

}


void Student::update2Sixty_default() {
	for (int& score : score_vector) {
		if (score < 60) {
			score = 60;
		}
	}
}

// 
//void Student::showInfo(std::vector<int> score_vector) {
//
//}


void Student::showInfo() {
	std::cout << "..显示学生信息...\n";

	std::cout << "..学生姓名::\t" << *name << "\n";
	std::cout << "..学生分数::\n";
	int score_index{ 0 };
	for (int score : score_vector) {
		std::cout << "..学科[" << score_index + 1 << "]::\t" << score << "\n";
		score_index++;
	}
}
