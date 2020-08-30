/*

需求：
输入运算符重载

1. 学生类，2个，姓名，年龄，分数vector
2. 使用全局以及friend 函数


*/


#include<iostream>


class Student;

std::istream& operator>>(std::istream& in, Student& stu);
std::ostream& operator<<(std::ostream& out, Student& stu);


class Student{

public:

	std::string name;
	int age;

	Student();
	Student(std::string name, int age);
	~Student();


};

Student::Student() : Student("unknown", 0)
{
	std::cout << "..无参构造...\n";
}

Student::Student(std::string name, int age) : name{ name }, age{ age }
{
	std::cout << "..有参构造...\n";
}

Student::~Student() {
	std::cout << "..析构函数...\n";
}


std::ostream& operator<<(std::ostream& out, Student& stu) {

	out << "..学生姓名::\t" << stu.name << ", 年龄::\t" << stu.age << "\n";

	return out;
}


std::istream& operator>>(std::istream& in, Student& stu) {

	in >> stu.name >> stu.age;
	
	return in;
}


int main() {

	std::cout << "..in operator_overload_in...\n";

	Student* stu = new Student;
	std::cout << "..输入学生姓名+年龄::\t";
	std::cin >> *stu;
	std::cout << *stu;

	return 0;
}