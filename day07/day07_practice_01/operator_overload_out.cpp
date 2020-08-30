/*

����
������������

1. ѧ���࣬2�������������䣬����vector
2. ʹ��ȫ���Լ�friend ����

�����Ԫ�����Ƕ��������ⲿ������Ȩ�����������˽�У�private����Ա�ͱ�����protected����Ա��
������Ԫ������ԭ��������Ķ����г��ֹ���������Ԫ���������ǳ�Ա������

��Ԫ������һ���������ú�������Ϊ��Ԫ��������ԪҲ������һ���࣬���౻��Ϊ��Ԫ�࣬
����������£������༰�����г�Ա������Ԫ

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
	std::cout << "..�޲ι���...\n";
}


Student_A::Student_A(std::string name, int age, std::vector<int> score_vector)
	: name{ name }
	, age{ age }
	, score_vector{ score_vector }{
	std::cout << "..ȫ�ι��캯��...\n";
}


Student_A::~Student_A()
{
	std::cout << "..��������...\n";
}


std::string& Student_A::get_name() {
	return name;
}


int& Student_A::get_age() {
	return age;		// �������涨����ຯ�����Է������˽�г�Ա
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
	friend std::ostream& operator<<(std::ostream& out, Student_B& stu_b);	// ��Ԫ�����������Ա����������������һ��
};

Student_B::Student_B() : Student_B("unknown", 0, {})
{
	std::cout << "..�޲ι���b...\n";
}

Student_B::Student_B(std::string name, int age, std::vector<int> score_vector)
	: name{ name }
	, age{ age }
	, score_vector{ score_vector }{
	std::cout << "..ȫ�ι��캯��b...\n";
}

Student_B::~Student_B()
{
	std::cout << "..��������b...\n";
}


std::ostream& operator<<(std::ostream& out, Student_A& stu_b);	// ��Ԫ�����������Ա����������������һ��
std::ostream& operator<<(std::ostream& out, Student_B& stu_b);	// ��Ԫ�����������Ա����������������һ��


int main() {

	std::cout << "..in operator_overload_out.cpp...\n";

	Student_A* stu_a = new Student_A("jacob", 18, { 1, 2, 3, 4 });
	Student_B* stu_b = new Student_B("raptor", 20, { 8, 8, 8, 8 });
	std::cout << *stu_a << *stu_b;

	delete stu_a;
	delete stu_b;

	return 0;
}


// ȫ�� operator<< ���أ�ͨ���������ֱ�������������г�Ա
std::ostream& operator<<(std::ostream& out, Student_A& stu_a) {

	out << "..ѧ������::\t" << stu_a.get_name() << ", ����::\t" << stu_a.get_age() << "\n";
	out << "..ѧ������::\t";
	for (int score : stu_a.get_scores()) {
		out << score << "\t";
	}
	out << "\n";

	return out;
}
	
	// ȫ�� operator<< ���أ�ͨ���������ֱ�������������г�Ա
std::ostream& operator<<(std::ostream& out, Student_B& stu_b) {

	out << "..ѧ������::\t" << stu_b.name << ", ����::\t" << stu_b.age << "\n";
	out << "..ѧ������::\t";
	for (int score : stu_b.score_vector) {
		out << score << "\t";
	}
	out << "\n";

	return out;
}