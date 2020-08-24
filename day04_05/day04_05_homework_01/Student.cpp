#include "Student.h"


// ���������๹�캯��
Student::Student() : Student(new std::string("unknown"), { 0 }) {	// �� vector<int> ��ʼ��Ϊ 0
	std::cout << "..�޲ι��캯��...\n";
}


Student::Student(std::string* name) : Student(name, { 0 }) {
	std::cout << "..һ�������Ĺ��캯��...\n";
}


Student::Student(std::string* name, std::vector<int> score_vector) : name{ name }, score_vector{ score_vector } {
	std::cout << "..����������ί�й��캯��...\n";
}


// ���忽�����캯�������
Student::Student(const Student& stu) {
	std::cout << "..�������캯��...\n";
	std::cout << &stu << "\n";
	std::cout << stu.name << "\n";			
	std::cout << *(stu.name) << "\n";
	
	name = new std::string;
	name = stu.name;
	score_vector = stu.score_vector;

}


// ����updateScore
//void Student::updateScore(std::vector<int> score_vector) {
//	std::cout << "..���·�������...\n";
//}


void Student::updateScore(void (*score_fun)()) {
	std::cout << "..���·���...\n";

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
	std::cout << "..��ʾѧ����Ϣ...\n";

	std::cout << "..ѧ������::\t" << *name << "\n";
	std::cout << "..ѧ������::\n";
	int score_index{ 0 };
	for (int score : score_vector) {
		std::cout << "..ѧ��[" << score_index + 1 << "]::\t" << score << "\n";
		score_index++;
	}
}
