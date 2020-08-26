/*

ʹ����������أ����������������ӣ��������ǵ������ܺ�

��δ��뽫Ҫ������������ص�������ʽ
1. ��������غ��������Ա����  operator+()
2. ��������غ�����ȫ�ֶ��庯�� operator-()

*/



#include<iostream>
#include<vector>

class Student {

public:

	int age;

	std::vector<int> scores{ 1, 2, 4, 8 };

	Student() : Student(0) {
		std::cout << "..�޲ι��캯��...\n";
	}

	Student(int age) : age{ age } {
		std::cout << "..�вι��캯��...\n";
	}

	int operator+(Student& stu) {				// +��������أ����Ա������ʽ	
		return this->age + stu.age;
	}


	//std::ostream& operator<<(std::ostream& out, std::vector<int>& scores) {
	//	for (int score : scores) {
	//		out << score << "\t";
	//	}
	//	return out;
	//}

};


// -��������أ�ȫ�ֺ���������ʽ
int operator-(Student& stu1, Student& stu2) {	// ������������ &
	return stu1.age - stu2.age;
}


// <<��������أ�ȫ�ֺ���������ʽ�����������������ô��ݣ��������ã���������
std::ostream& operator<<(std::ostream& out, std::vector<int>& scores) {
	for (int score : scores) {
		out << score << "\t";
	}

	return out;
}

// *��������أ�ȫ�ֺ���������ʽ
Student operator*(Student& stu1, Student& stu2) {
	Student stu3;
	stu3.age = stu1.age * stu2.age;

	return stu3;
}

int main() {

	std::cout << "..in operator_overloading_00...\n";

	Student s1(10), s2(20);
	std::cout << "..ѧ�� s1 �� s2 �����ܺ� :: " << s1 + s2 << "\n";	// ʹ����������أ����Ա������ʽ
	std::cout << "..ѧ�� s1 �� s2 ����֮�� :: " << s1 - s2 << "\n";	// ʹ����������أ�ȫ�ֺ���������ʽ

	Student s3 = s1 * s2;
	std::cout << "..ѧ�� s3 ������ = s1 �� * s2 �� :: " << s3.age << "\n";	// ʹ����������أ�ȫ�ֺ���������ʽ

	//std::cout << s1.scores << "\n";
	
	std::vector<int> scores{ 1, 2, 4, 8 };
	std::cout << scores << "\n";


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