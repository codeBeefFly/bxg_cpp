/*

����

���ø��๹����


����ֻ��ʹ�ó�ʼ���б�ķ�ʽ�����ʸ��๹��

+ ��ʼ�������Ա

*/


#include <iostream>


//class A {
//public:
//	A() {}
//	A(int number) : number{ number } {}
//	~A() {}
//
//	int number;
//};

class Father
{
public:
	Father();
	Father(std::string name) : name { name } {
		std::cout << "..�����вι���...\n";
	}
	~Father();

	std::string name;
	//A a;
};

Father::Father()
{
	std::cout << "..�����޲ι���...\n";
}

Father::~Father()
{
	std::cout << "..������������...\n";
}


class Son : public Father
{
public:
	Son();
	Son(std::string name) : Father(name) {
		std::cout << "..�����вι��캯��...\n";
	}
	~Son();

	//std::string name;		// �̳и���ĳ�Ա��������д��
};

Son :: Son()
{
	std::cout << "..�����޲ι���...\n";
}

Son :: ~Son()
{
	std::cout << "..������������...\n";
}


int main() {

	std::cout << "..in inherit_invoke_father_constructor...\n";

	Son s("jacob");
	
	std::cout << "..ѧ������::\t" << s.name << "\n";

	return 0;
}


/*

output

..in inherit_invoke_father_constructor...
..�����вι���...
..�����вι��캯��...
..ѧ������::    jacob
..������������...
..������������...

*/