/*

ʹ����������أ����������������ӣ��������ǵ������ܺ�

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

	int operator+(Student& stu) {
		return this->age + stu.age;
	}
};



int main() {

	std::cout << "..in operator_overloading_00...\n";

	Student s1(10), s2(20);
	std::cout << "..ѧ�� s1 �� s2 �����ܺ� :: " << s1 + s2 << "\n";	// ʹ�����������

	return 0;
}


/*

output

..in operator_overloading_00...
..�вι��캯��...
..�вι��캯��...
..ѧ�� s1 �� s2 �����ܺ� :: 30

*/