/*

ʹ����������أ����������������ӣ��������ǵ������ܺ�

��δ��뽫Ҫ������������ص�������ʽ
1. ��������غ��������Ա����  operator+()
2. ��������غ�����ȫ�ֶ��庯�� operator-()

*/



#include<iostream>

class Student {

public:

	int age;

	Student() : Student(0) {
		std::cout << "..�޲ι��캯��...\n";
	}

	Student(int age) : age{ age } {
		std::cout << "..�вι��캯��...\n";
	}

	int operator+(Student& stu) {				// +��������أ����Ա������ʽ	
		return this->age + stu.age;
	}

};


// -��������أ�ȫ�ֺ���������ʽ
int operator-(Student stu1, Student stu2) {

	return stu1.age - stu2.age;

}


int main() {

	std::cout << "..in operator_overloading_00...\n";

	Student s1(10), s2(20);
	std::cout << "..ѧ�� s1 �� s2 �����ܺ� :: " << s1 + s2 << "\n";	// ʹ����������أ����Ա������ʽ
	std::cout << "..ѧ�� s1 �� s2 ����֮�� :: " << s1 - s2 << "\n";	// ʹ����������أ�ȫ�ֺ���������ʽ

	return 0;
}


/*

output

..in operator_overloading_00...
..�вι��캯��...
..�вι��캯��...
..ѧ�� s1 �� s2 �����ܺ� :: 30



..in operator_overloading_00...
..�вι��캯��...
..�вι��캯��...
..ѧ�� s1 �� s2 �����ܺ� :: 30
..ѧ�� s1 �� s2 ����֮�� :: -10

*/