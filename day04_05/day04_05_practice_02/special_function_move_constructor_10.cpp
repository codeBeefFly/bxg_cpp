/*

��ָ����ʹ���ƶ����캯��

*/

#include <iostream>


class Student {

public:
	std::string* item;

	
	// ����
	Student() : Student("ipad3") {
		std::cout << "..�޲ι��캯��...\n";
	}


	// �вι���
	Student(std::string name) : item{ new std::string("ipad3") }{
		std::cout << "..���ι��캯��...\n";
	}


	// �������캯����ǳ����
	Student(const Student& stu) {
		std::cout << "..�������캯��...\n";
		item = stu.item;
	}


	// �ƶ����캯��
	Student(Student&& stu) {
		std::cout << "..�ƶ����캯��...\n";
		item = stu.item;
		stu.item = nullptr;			// ������������������Ȩ
	}


};


Student createStu() {
	std::cout << "..��������...\n";
	Student stu;
	stu.item = new std::string("ipad3");
	return stu;
}


int main() {

	std::cout << "..in special_function_move_constructor_10...\n";

	Student stu = createStu();

	return 0;
}
