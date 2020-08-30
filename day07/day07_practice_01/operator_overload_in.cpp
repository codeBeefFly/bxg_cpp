/*

����
�������������

1. ѧ���࣬2�������������䣬����vector
2. ʹ��ȫ���Լ�friend ����


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
	std::cout << "..�޲ι���...\n";
}

Student::Student(std::string name, int age) : name{ name }, age{ age }
{
	std::cout << "..�вι���...\n";
}

Student::~Student() {
	std::cout << "..��������...\n";
}


std::ostream& operator<<(std::ostream& out, Student& stu) {

	out << "..ѧ������::\t" << stu.name << ", ����::\t" << stu.age << "\n";

	return out;
}


std::istream& operator>>(std::istream& in, Student& stu) {

	in >> stu.name >> stu.age;
	
	return in;
}


int main() {

	std::cout << "..in operator_overload_in...\n";

	Student* stu = new Student;
	std::cout << "..����ѧ������+����::\t";
	std::cin >> *stu;
	std::cout << *stu;

	return 0;
}