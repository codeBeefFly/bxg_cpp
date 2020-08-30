/*

需求：
输出运算符重载

1. 学生类，2个，姓名，年龄，分数vector
2. 使用全局以及friend 函数

类的友元函数是定义在类外部，但有权访问类的所有私有（private）成员和保护（protected）成员。
尽管友元函数的原型有在类的定义中出现过，但是友元函数并不是成员函数。

友元可以是一个函数，该函数被称为友元函数；友元也可以是一个类，该类被称为友元类，
在这种情况下，整个类及其所有成员都是友元

*/

#include<iostream>
#include <vector>

class Student_A;
class Student_B;




class Student_A
{
public:
	Student_A();
	Student_A(std::string name, int age, std::vector<int> score_vector);
	~Student_A();

	std::string& get_name();

	int& get_age();
	
	std::vector<int>& get_scores();
	

private:
	std::string name;
	int age;
	std::vector<int> score_vector;
};


Student_A::Student_A() : Student_A("unknown", 0, {})
{
	std::cout << "..无参构造...\n";
}


Student_A::Student_A(std::string name, int age, std::vector<int> score_vector)
	: name{ name }
	, age{ age }
	, score_vector{ score_vector }{
	std::cout << "..全参构造函数...\n";
}


Student_A::~Student_A()
{
	std::cout << "..析构构造...\n";
}


std::string& Student_A::get_name() {
	return name;
}


int& Student_A::get_age() {
	return age;		// 在类外面定义的类函数可以访问类的私有成员
}


std::vector<int>& Student_A::get_scores() {
	return score_vector;
}


class Student_B
{
public:
	Student_B();
	Student_B(std::string name, int age, std::vector<int> score_vector);
	~Student_B();

	std::string name;
	int age;
	std::vector<int> score_vector;

private:
	friend std::ostream& operator<<(std::ostream& out, Student_B& stu_b);	// 友元函数不是类成员函数。在类外重载一次
};

Student_B::Student_B() : Student_B("unknown", 0, {})
{
	std::cout << "..无参构造b...\n";
}

Student_B::Student_B(std::string name, int age, std::vector<int> score_vector)
	: name{ name }
	, age{ age }
	, score_vector{ score_vector }{
	std::cout << "..全参构造函数b...\n";
}

Student_B::~Student_B()
{
	std::cout << "..析构函数b...\n";
}


std::ostream& operator<<(std::ostream& out, Student_A& stu_b);	// 友元函数不是类成员函数。在类外重载一次
std::ostream& operator<<(std::ostream& out, Student_B& stu_b);	// 友元函数不是类成员函数。在类外重载一次


int main() {

	std::cout << "..in operator_overload_out.cpp...\n";

	Student_A* stu_a = new Student_A("jacob", 18, { 1, 2, 3, 4 });
	Student_B* stu_b = new Student_B("raptor", 20, { 8, 8, 8, 8 });
	std::cout << *stu_a << *stu_b;

	delete stu_a;
	delete stu_b;

	return 0;
}


// 全局 operator<< 重载，通过类对象名直接输出类对象所有成员
std::ostream& operator<<(std::ostream& out, Student_A& stu_a) {

	out << "..学生姓名::\t" << stu_a.get_name() << ", 年龄::\t" << stu_a.get_age() << "\n";
	out << "..学生分数::\t";
	for (int score : stu_a.get_scores()) {
		out << score << "\t";
	}
	out << "\n";

	return out;
}
	
	// 全局 operator<< 重载，通过类对象名直接输出类对象所有成员
std::ostream& operator<<(std::ostream& out, Student_B& stu_b) {

	out << "..学生姓名::\t" << stu_b.name << ", 年龄::\t" << stu_b.age << "\n";
	out << "..学生分数::\t";
	for (int score : stu_b.score_vector) {
		out << score << "\t";
	}
	out << "\n";

	return out;
}