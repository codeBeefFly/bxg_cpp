/*

����

����ڼ̳�״̬�£������еĳ�Ա�ֺ���������Ķ������ԣ���ô����֮��Ĺ������������˳����ѭ����ԭ��

a. �ȵ��ø���Ĺ��캯��,�ٵ�����϶���Ĺ��캯��,�������Լ��Ĺ��캯��;

b. �ȵ����Լ�����������,�ٵ�����϶������������,�����ø��������������


����һ��person��

����һ��A��

����һ��ѧ����̳�person��

�����඼ֻ�й���/��������

*/


#include <iostream>


class Person {

public:

	Person() {
		std::cout << "..Person���캯��...\n";
	}

	~Person() {
		std::cout << "..Person��������...\n";
	}

};


class A {

public:

	A() {
		std::cout << "..A���캯��...\n";
	}

	~A() {
		std::cout << "..A��������...\n";
	}

};


class Student : public Person{

public:

	Student() {
		std::cout << "..Student���캯��...\n";
	}

	~Student() {
		std::cout << "..Student��������...\n";
	}

public:
	A a;
};



int main() {

	std::cout << "..in inherit_combined...\n";

	Student stu;

	return 0;

}



/*

a. �ȵ��ø���Ĺ��캯��,�ٵ�����϶���Ĺ��캯��,�������Լ��Ĺ��캯��;

b. �ȵ����Լ�����������,�ٵ�����϶������������,�����ø��������������


..in inherit_combined...
..Person���캯��...
..A���캯��...
..Student���캯��...
..Student��������...
..A��������...
..Person��������...


*/