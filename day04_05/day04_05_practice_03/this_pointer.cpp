/*

this���÷�����ʽ���á�
Ȼ���������Լ������������޵�����ȥ��

*/



#include <iostream>


class Student_normal {
public:
	std::string name;
	int age;

	Student_normal() : Student_normal("unknown", 10) {
		std::cout << "..log::�޲ι��캯��...\n";
	}

	Student_normal(std::string name) : Student_normal(name, 10) {
		std::cout << "..log::һ�ι��캯��...\n";
	}

	Student_normal(std::string name, int age) : name{ name }, age{ age }{
		std::cout << "..log::���ι��캯��...\n";
	}

	~Student_normal() {
		std::cout << "..log::��������...\n";
	}


	void eat() {
		std::cout << "..ѧ���Է�...\n";
	}

	void run() {
		std::cout << "..ѧ���ܲ�...\n";
	}

	void sleep() {
		std::cout << "..ѧ��˯��...\n";
	}

};


class Student_this {
public:
	std::string name;
	int age;

	Student_this() : Student_this("unknown", 10) {
		std::cout << "..log::�޲ι��캯��...\n";
	}

	Student_this(std::string name) : Student_this(name, 10) {
		std::cout << "..log::һ�ι��캯��...\n";
	}


	Student_this(std::string name, int age) : name{ name }, age{ age } {
		std::cout << "..log::���ι��캯��...\n";
		this->name = name;
		this->age = age;
	}

	~Student_this() {
		std::cout << "..log::��������...\n";
	}

	// ���� Student ����
	Student_this eat() {
		std::cout << "..ѧ���Է�...\n";
		return *this;		// �����ã����������
	}

	Student_this run() {
		std::cout << "..ѧ���ܲ�...\n";
		return *this;
	}

	Student_this sleep() {
		std::cout << "..ѧ��˯��...\n";
		return *this;
	}

};



class Student_this_ptr {
public:
	std::string name;
	int age;

	Student_this_ptr() : Student_this_ptr("unknown", 10) {
		std::cout << "..log::�޲ι��캯��...\n";
	}

	Student_this_ptr(std::string name) : Student_this_ptr(name, 10) {
		std::cout << "..log::һ�ι��캯��...\n";
	}

	Student_this_ptr(std::string name, int age) : name{ name }, age{ age } {
		std::cout << "..log::���ι��캯��...\n";
		this->name = name;
		this->age = age;
	}

	~Student_this_ptr() {
		std::cout << "..log::��������...\n";
	}

	// ���� Student ����
	Student_this_ptr* eat() {
		std::cout << "..ѧ���Է�...\n";
		return this;		// �����ã����������
	}

	Student_this_ptr* run() {
		std::cout << "..ѧ���ܲ�...\n";
		return this;
	}

	Student_this_ptr* sleep() {
		std::cout << "..ѧ��˯��...\n";
		return this;
	}

};


int main() {

	std::cout << "..in this_pointer...\n";

	{	std::cout << "\n**********************************\n";

		Student_normal* stu = new Student_normal("jacob", 10);
		stu->eat();
		stu->run();
		stu->sleep();

		(*stu).eat();
		(*stu).run();
		(*stu).sleep();

		Student_normal stu_b("jacob_x", 10);
		stu_b.eat();
		stu_b.run();
		stu_b.sleep();
	}

	{	std::cout << "\n**********************************\n";
		
		Student_this* stu = new Student_this("raptor", 10);
		(*stu).eat().run().sleep();			// �����˺ܶ����
		
		delete stu;
	}

	{	std::cout << "\n**********************************\n";
		
		Student_this_ptr* stu = new Student_this_ptr("king", 10);
		stu->eat()->run()->sleep();			// ֻ������һ������

		delete stu;
	}

	return 0;
}



/*

..in this_pointer...

**********************************
..log::���ι��캯��...
..ѧ���Է�...
..ѧ���ܲ�...
..ѧ��˯��...
..ѧ���Է�...
..ѧ���ܲ�...
..ѧ��˯��...
..log::���ι��캯��...
..ѧ���Է�...
..ѧ���ܲ�...
..ѧ��˯��...
..log::��������...

**********************************
..log::���ι��캯��...
..ѧ���Է�...
..ѧ���ܲ�...
..ѧ��˯��...
..log::��������...
..log::��������...
..log::��������...
..log::��������...

**********************************
..log::���ι��캯��...
..ѧ���Է�...
..ѧ���ܲ�...
..ѧ��˯��...
..log::��������...

D:\W_workPlace\bxg_cpp\day04_05\build\Debug\day04_05_this_pointer.exe (process 4168) exited with code 0.
Press any key to close this window . . .

*/