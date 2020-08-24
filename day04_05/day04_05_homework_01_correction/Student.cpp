#include "Student.h"


Student::Student() : Student("unknown" , {}) {
	std::cout << "..log::无参构造函数...\n";
}


Student::Student(std::string name) : Student(name, {}) {
	std::cout << "..log::有一参构造函数...\n";
}


Student::Student(std::string name, std::vector<int> score_vector) : name{ new std::string(name) }, score_vector{ score_vector } {
	std::cout << "..log::有两参构造函数...\n";
}


Student::~Student() {
	std::cout << "..log::析构函数...\n";
	std::cout << name << "\n";
	delete name;		// 释放 类中的堆空间
	//name = nullptr;
}

//深拷贝
Student::Student(const Student& stu) {
	std::cout << "..log::拷贝构造函数...\n";
	//*name = *stu.name;	// name 是空指针，需要创建出来空间
	name = new std::string(*stu.name);
	score_vector = stu.score_vector;
}


void Student::updateScore() {
	std::cout << "..log::更新成绩...\n";
	for (int& score : score_vector) {
		if (score < 60) {
			score = 60;
		}
	}
}


void Student::showInfo() {
	std::cout << "\n..log::显示成绩...\n";
	std::cout << "...学生姓名::\t" << *name << "\n";
	std::cout << "...分数::\t";
	int score_index{ 0 };
	for (int score : score_vector) {
		std::cout << score << "\t";
		score_index++;
	}
}

