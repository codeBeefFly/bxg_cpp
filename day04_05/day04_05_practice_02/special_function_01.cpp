/*
C++ ��һ�����⺯�������캯��
��ʼ���б�ʽ��ֵ

{} ��ֵ������������խ����ֹ���Ƚ���

*/

#include<iostream>


class Student {		// �����������������ϵĹ��캯�����вΣ��޲�  
public:
	std::string name;
	int age;

	Student() {
		std::cout << "..�޲ι��캯��...\n";
	}

	//Student(std::string name_val, int age_val) {	// ���ʵľͽ�ԭ��name=name; �����β�
	//	std::cout << "..�вι��캯��...\n";
	//	name = name_val;		// ����ʹ�� name = name; ������ָ �β� name
	//	age = age_val;			// ����ʹ�� age = age;																
	//}


	// ʹ�ó�ʼ���б�ķ�ʽ��� ���캯�����β������Աͬ�������
	Student(std::string name, int age) :name(name), age(age) {	// name(name):���name,���Ա����;�ڲ�name,�β�
		std::cout << "..�вι��캯������ʼ���б�������Ա��ʼ��...\n";
	}

};


int main() {

	std::cout << "..in special_function_01...\n";

	Student* stu_a = new Student("jacob", 18);
	std::cout << stu_a->name << " is " << stu_a->age << " years old.\n";

	return 0;
}