/*

��ͨ��ʽ���ú���

����
1. ʹ����ͨ��ʽ���ú���
2. �ֿ�ʽд����ʵ�ּӷ���������ͨ��ʽ����

*/


#include <iostream>

int add(int a, int b);

int main() {

	std::cout << "..enter a and b for addition ::\t";
	int a, b;
	std::cin >> a >> b;
	std::cout << "..result :: " << a << " + " << b << " = " << add(a, b);

	return 0;
}

int add(int a, int b) {

	return a + b;
}





