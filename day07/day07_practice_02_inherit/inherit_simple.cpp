/*

�򵥵ļ̳�
����һ�����࣬������ int money
����̳й�������
������ø��� int money

*/



#include <iostream>

// ������ôд��
//class Father;
//class Son;
class Father;
class Son;


class Father
{
public:

	int money = 1000;

	Father() {};
	~Father() {};

};


//class Son : public Father {
//	// ʲô����д��ֻ�̳о���
//};


int main() {

	std::cout << "..in inherit_simple...\n";

	Son son_a;
	std::cout << "..son_a has father's money :: " << son_a.money << "\n";

	return 0;
}

//class Father
//{
//public:
//
//	int money = 1000;
//
//	Father() {};
//	~Father() {};
//
//};
//
//д��Ͳ��� Ϊʲô
class Son : public Father {
	// ʲô����д��ֻ�̳о���
};