/*

����

���������������ʱ�ĳ�ʼ��

*/


#include <iostream>


class A {

public:

	int number;
	std::string color;

	A() : A(0, "unknown_color") { 
		std::cout << "..A �޲ι��캯��...\n";  
	}
	A(int number, std::string color) : number{ number }, color{ color } {
		std::cout << "..A �вι��캯��...\n";
	}

	~A() {
		std::cout << "..A ��������...\n";
	}

};


class Father {

public:

	std::string name;

	Father() : Father("unknown") {
		std::cout << "..Father �޲ι���...\n";
	}
	Father(std::string name) : name{ name } {
		std::cout << "..Father �вι���...\n";
	}

	~Father() {
		std::cout << "..Father ��������...\n";
	}

};


class Son : public Father {
public:

	A a;


	//Son() : Son(a(0, "unknown_color", "unknwon") {
	//	std::cout << "..Son �޲ι��캯��...\n";
	//}

	//Son(A a, std::string name) : a(0), name{ name }{	// �����ڹ��캯���в��ܳ�ʼ������ĳ�Ա
	Son(A a, std::string name) : a(0, "unknown_color"){	// �����г�ʼ�������ķ�ʽ����ʼ�����������Ϊ�޲ι�����ʽ
		std::cout << "..Son �вι���...\n";
	}

	~Son() {
		std::cout << "..Son ��������...\n";
	}
};



int main() {

	std::cout << "..inherit_object_in_class...\n";



	return 0;
}