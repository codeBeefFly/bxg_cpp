/*

����

���������������ʱ�ĳ�ʼ����ֻ��ʹ�ó�ʼ���б�ķ�ʽ������ʹ��ί�й��캯������ʽ��

�๹�캯��ֻ�ܳ�ʼ���Լ������Ա�����ܳ�ʼ���̳е����Ա

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

	//���к���������Ķ����Ա�����Ҫ��ʼ����ֻ��ʹ�ó�ʼ�����б�ʽ��
	Son() : a(0, "unknown_color") {
		std::cout << "..Son �޲ι��캯��...\n";
	}

	//Son(A a, std::string name) : a(0), name{ name }{	// �����ڹ��캯���в��ܳ�ʼ������ĳ�Ա
	Son(A a) : a(0, "unknown_color"){	// �����г�ʼ�������ķ�ʽ����ʼ�����������Ϊ�޲ι�����ʽ
		std::cout << "..Son �вι���...\n";
	}

	~Son() {
		std::cout << "..Son ��������...\n";
	}
};



int main() {

	std::cout << "..inherit_object_in_class...\n";

	Son s;

	return 0;
}



/*

..inherit_object_in_class...
..Father �вι���...   //��Ϊfather���޲ι���ί�����вι���
..Father �޲ι���...
..A �вι��캯��...
..Son �޲ι��캯��...
..Son ��������...
..A ��������...
..Father ��������...

*/