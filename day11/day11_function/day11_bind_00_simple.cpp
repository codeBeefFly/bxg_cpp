/*

����

�������Ϊ�Ѻ��� ��������ʵ���Լ����ú����Ķ������󶨵�һ��
Ȼ����һ�����������������������Ҳ������Щ������õ����塣


1. ʹ�� bind ��ȫ�ֺ���
2. ʹ�ú���������� bind �󶨵ĺ���


����������﷨

std::function<������������(��������)> �������� = ȫ�ֺ�����;


bind �󶨺����﷨��ʹ�� 

*/



#include <iostream>
#include <functional>


int add(int a, int b) {

	return a + b;

}


int main() {

	std::cout << "..in day11_bind_00_simple...\n";

	// ʹ�ú����������ȫ�ֺ���
	std::function<int(int, int)> f_add = add;
	std::cout << "..f_add(3, 4) = " << f_add(3, 4) << "\n";


	// ʹ�� bind ��ȫ�ֺ�����ʹ���Զ��ƶ�����
	auto p_add = std::bind(add, 3, 4);
	std::cout << "..p_add() = " << p_add() << "\n";


	// ʹ�� �������� ���հ󶨵�ȫ�ֺ���
	std::function<int()> f_add_bind = std::bind(add, 3, 4);
	std::cout << "..f_add_bind() = " << f_add_bind() << "\n";


	return 0;

}


/*

output:

..in day11_bind_00_simple...
..f_add(3, 4) = 7
..p_add() = 7
..f_add_bind() = 7


*/