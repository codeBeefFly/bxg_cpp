#include "Student.h"


Student::Student() : Student("unknown" , {}) {
	std::cout << "..log::�޲ι��캯��...\n";
}


Student::Student(std::string name) : Student(name, {}) {
	std::cout << "..log::��һ�ι��캯��...\n";
}


Student::Student(std::string name, std::vector<int> score_vector) : name{ new std::string(name) }, score_vector{ score_vector } {
	std::cout << "..log::�����ι��캯��...\n";
}


Student::~Student() {
	std::cout << "..log::��������...\n";
	std::cout << name << "\n";
	delete name;		// �ͷ� ���еĶѿռ�
	//name = nullptr;
}

//���
Student::Student(const Student& stu) {
	std::cout << "..log::�������캯��...\n";
	//*name = *stu.name;	// name �ǿ�ָ�룬��Ҫ���������ռ�
	name = new std::string(*stu.name);
	score_vector = stu.score_vector;
}


void Student::updateScore() {
	std::cout << "..log::���³ɼ�...\n";
	for (int& score : score_vector) {
		if (score < 60) {
			score = 60;
		}
	}
}


void Student::showInfo() {
	std::cout << "\n..log::��ʾ�ɼ�...\n";
	std::cout << "...ѧ������::\t" << *name << "\n";
	std::cout << "...����::\t";
	int score_index{ 0 };
	for (int score : score_vector) {
		std::cout << score << "\t";
		score_index++;
	}
}

