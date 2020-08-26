/*

����

�ϼ�ѧ��a��ѧ��b������Ǯ֮�ͣ�ʹ�����������

���

1. + ��������غ���Ϊ���Ա����

2. - ���������Ϊȫ�ֺ���


*/

#include <iostream>


class Student {

public:

	int money;


	Student() : Student(money) {
		std::cout << "..�޲ι��캯��...\n";
	}


	Student(int money) : money{ money } {
		std::cout << "..�вι��캯��...\n";
	}


	// operator+
	Student& operator+(Student& b) {
		return Student(this->money + b.money);		// ����һ��ѧ���������ѧ�������е� money Ϊ��������ѧ������� money��
	}

	// operator*������д��
	//int& operator*(Student& b) {					// &�������ã�Ӧ����һ����ֵ
	//	return this->money * b.money;				// ����һ����ֵ
	//}

	int&& operator*(Student& b) {					// &�������ã�Ӧ����һ����ֵ
		return this->money * b.money;				// ����һ����ֵ
	}

	float operator/(Student& b) {
		return this->money / b.money;
	}
};


Student& operator-(Student& a, Student& b) {
	return Student(a.money - b.money);
}


int main(){

	std::cout << "..in student_money_operator_overload...\n";

	Student a(20), b(30);
	Student c = a + b;
	Student d = a - b;

	std::cout << "c has money :: " << c.money << "\n";
	std::cout << "d has money :: " << d.money << "\n";

	
	return 0;
}



/*

..in student_money_operator_overload...
..�вι��캯��...
..�вι��캯��...
..�вι��캯��...
..�вι��캯��...
c has money :: 50
d has money :: -10

*/