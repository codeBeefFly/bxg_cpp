#include <iostream>


class Student {

public:
	std::string name;
	int age;

	// ����
	Student() : name{ name }, age{ 0 }{
		std::cout << "..log::���캯��...\n";
	}

	// ����
	Student(const Student& stu) {
		std::cout << "..log::��������...\n";
	}

	// ����
	~Student() {
		std::cout << "..log::��������...\n";
	}


};


class Student_move_constructor {

public:
	std::string name;
	int age;

	// ����
	Student_move_constructor() : name{ name }, age{ 0 }{
		std::cout << "..log::���캯��...\n";
	}

	// ����
	Student_move_constructor(const Student& stu) {
		std::cout << "..log::��������...\n";
		name = stu.name;
		age = stu.age;
	}

	// �ƶ������յ�����ֵ
	Student_move_constructor(const Student&& stu) {
		std::cout << "..log::�ƶ�����...\n";
		name = stu.name;
		age = stu.age;
	}

	// ����
	~Student_move_constructor() {
		std::cout << "..log::��������...\n";
	}


};


int main() {

	std::cout << "..in special_function_move_constructor...\n";

	{
		std::cout << "\n*******************\n";

		Student stu_a;

		Student stu_b = stu_a;
	}

	{
		
		std::cout << "\n*******************\n";

		Student_move_constructor stu_m_c_1;
		stu_m_c_1.name = "jacob";
		stu_m_c_1.age = 10;

		Student_move_constructor stu_m_c_2 = stu_m_c_1;


		//std::cout << "..stu_m_c_1 name:: " << stu_m_c_1.name << ", age:: " << stu_m_c_1.age << "\n";
		//std::cout << "..stu_m_c_2 name:: " << stu_m_c_2.name << ", age:: " << stu_m_c_2.age << "\n";
	}

	{
		
		std::cout << "\n*******************\n";
		
		Student_move_constructor stu_m_c_1;
		stu_m_c_1.name = "jacob";
		stu_m_c_1.age = 10;

		Student_move_constructor stu_m_c_2 = std::move(stu_m_c_1);


		//std::cout << "..stu_m_c_1 name:: " << stu_m_c_1.name << ", age:: " << stu_m_c_1.age << "\n";
		//std::cout << "..stu_m_c_2 name:: " << stu_m_c_2.name << ", age:: " << stu_m_c_2.age << "\n";
	}

	return 0;
}