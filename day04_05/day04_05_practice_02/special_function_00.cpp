/*
C++ ��һ�����⺯�������캯��
*/

#include<iostream>


class Student {
public:
	std::string name;
	int age;

	Student() {						// �޲ι��캯��
		std::cout << "..�޲ι��캯��...\n";
	}

	Student(std::string name_val) {
		std::cout << "..�вι��캯��...\n";
	}
};


int main() {

	std::cout << "..in special_function_00...\n";

	Student stu;					// ��ջ�ڴ濪�ٿռ�
	stu.name = "jacob";

	Student* stu_b = new Student;	// �ڶ��ڴ濪�ٿռ䣬����һ��Studentָ��ָ��˿ռ�
	//Student* stu_b = new Student();	// �ڶ��ڴ濪�ٿռ䣬����һ��Studentָ��ָ��˿ռ䣬��������д����һ��С����
	//stu_b->name = "jacob";
	(*stu_b).name = "raptor";		// ָ������õõ��ڴ��ַ
	(*stu_b).age = 18;


	Student* stu_c = new Student("king");
	(*stu_c).age = 18;


	Student stu_d();

	return 0;
}