/*

һ����˵����� ������һ���ģ�����������Ȼ����ʹ�ã�
�����ĳ�������涨������һ����Ķ��������
��ô������ǰ����ǰ�����������ܱ���ͨ����


Ŀǰ������������ʲô��

�ȳ�һ��

*/



#include <iostream>

class Father;	// ǰ����������


class Son {

public:
	Father* f_1;
	Father& f_2;

	Son(Father* f_1, Father& f_2) : f_1(f_1), f_2(f_2) { // �����һ����б��ʼ��

	}
};


class Father {

};


int main() {

	std::cout << "..inherit_pre_declare...\n";

	Father f1;
	Father f2;

	Son s(&f1, f2);

	return 0;
}