/*
�����⺯��--�������캯��[vip]
*/


#include<iostream>


class Student {

public:
	std::string name;
	int age;


	Student() : Student("unknown", 0) {};							// ʹ��ί�й��캯������ʽ��ʼ�����Ա

	Student(std::string name, int age) : name(name), age(age) {		// ί�й��캯���������б��ʼ����ʽ��ʼ�����Ա
		std::cout << "..�ж��ι��캯��...\n";
	}

};


int main() {
	std::cout << "..in special_function_04...\n";


	Student stu_a("jacob", 18);										// �ڴ���������ʱ���ʼ�����Ա��ֻ��һ�ι��캯��

	Student stu_b = stu_a;											// ʹ�ÿ������캯��������һ���µ������

	std::cout << "stu_a �ĵ�ַ:: " << &stu_a << ", ����:: " << stu_a.name << ", ����:: " << stu_a.age << "\n";
	std::cout << "stu_b �ĵ�ַ:: " << &stu_b << ", ����:: " << stu_b.name << ", ����:: " << stu_b.age << "\n";

	return 0;
}


/*

..in special_function_04...
..�ж��ι��캯��...
stu_a �ĵ�ַ:: 00000018BE0FFCC8, ����:: jacob, ����:: 18
stu_b �ĵ�ַ:: 00000018BE0FFD18, ����:: jacob, ����:: 18

*/