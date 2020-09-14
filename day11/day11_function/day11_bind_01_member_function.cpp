/*

����

�����Ա����


����һ�� Student �࣬���Ա����  eat(string food)


����һ��ȫ�� printStudent ���������պ�������+�����


ʹ�� �������� + bind + ��������&&bind ��ʽ���� ���Ա����


*/


#include <iostream>
#include <functional>


class Student {

public:
	void eat(std::string food) {
		std::cout << "..jacob is eating " << food << "...\n";
	}

};


void printStudent(std::function<void()> f_eat) {
	f_eat();
}


// ���Ա�﷨  (��������+��+����, ��������, ��������);
void printStudent_2(std::function<void(Student, std::string)> f_eat, Student student, std::string food) {
	f_eat(student, food);
}


void printStudent_3(std::function<void(std::string)> f_eat) {
	f_eat("apple");
}



int main() {
	std::cout << "..in day11_bind_01_member_function...\n";

	// ʹ�� function ����������� ���Ա����
	std::function<void(Student, std::string)> f_stu_eat = &Student::eat;

	Student stu_jacob;

	f_stu_eat(stu_jacob, "banana");

	printStudent_2(f_stu_eat, stu_jacob, "apple");

	// ʹ��bind + auto �Զ��Ƶ� �� ���Ա����
	Student stu_raptor;
	auto p_stu_eat = std::bind(&Student::eat, stu_raptor, "orange");
	p_stu_eat();

	// ʹ�� printStudent �������Ա���� ����Ϊ function ����
	//printStudent(f_stu_eat(stu_jacob, "grape"));	// ���� �޲����͵�

	// ʹ�� printStudent �������Ա���� ����Ϊ bind ����
	std::function<void()> f_stu_eat_null = std::bind(&Student::eat, stu_raptor, "grape");
	printStudent(f_stu_eat_null);

	return 0;
}


/*

output

..in day11_bind_01_member_function...
..jacob is eating banana...
..jacob is eating apple...
..jacob is eating orange...
..jacob is eating grape...

*/
