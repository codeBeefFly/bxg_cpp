/*

����

 * ����Ҫ�Ƚ�����ѧ���Ĵ�С�����԰������ֶ�������Ƚϡ�Ҳ���԰�������Ƚϡ�Ҳ���԰�����߱Ƚϡ�
����һ��ȫ�ֺ���compare , ������������������һ�Ͳ����� ΪҪ�Ƚϵ�ѧ�����󣬲�����Ϊlambda���ʽ

�������һ������Ƚ����䣬
�������һ�������ʾ������ȣ�
�����ӡ���˵Ĵ�С��


�ȽϺ�����

int compare(Student stu_1, Student stu_2, bool (*fun)(std::string name_1, std::string name_2))

ʹ�� lambda
[](){};	���غ���ָ��

[](){}(); ����ֵ


// ��д

*/




#include <iostream>


class Student {

public:
	std::string name;
	int age;

	Student() = default;
	Student(std::string name, int age) : name{ name }, age{ age }{}

};


int compare(Student stu_1, Student stu_2, int (*compare_student)(Student stu_1, Student stu_2));


int main() {

	std::cout << "..in day07_homework_compare_lambda...\n";

	Student stu_1("jacob", 10);
	Student stu_2("raptor", 20);

	int result = compare(
		stu_1, stu_2,
		[](Student stu_1, Student stu_2) {
			if (stu_1.name > stu_2.name) {
				return 1;
			}
			else if (stu_1.name == stu_2.name) {
				if (stu_1.age > stu_2.age) {
					return 1;
				}
				else if (stu_1.age == stu_2.age) {
					return 0;
				}
				else {
					return -1;
				}
			}
			else {
				return -1;
			}
		}
	);

	if (result > 0) {
		std::cout << "..stu1 bigger...\n";
	}
	else if (result == 0) {
		std::cout << "..both equal...\n";
	}
	else {
		std::cout << "..stu2 bigger...\n";
	}


	return 0;
}


int compare(Student stu_1, Student stu_2, int (*compare_student)(Student stu_1, Student stu_2)) {
	return compare_student(stu_1, stu_2);
}


/*

..in day07_homework_compare_lambda...
..stu2 bigger...


*/
