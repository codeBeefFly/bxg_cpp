/*

ָ�뷽ʽ���ú���

����
1. ʹ��ָ�뷽ʽ���ú���
2. �ֿ�ʽд����ʵ�ּӷ���������ͨ��ʽ����

*/


// ����һ����ͨ��add����
#include <iostream>


int add(int a, int b);


// ��ں���
int main() {

	std::cout << "..enter a and b for addition ::\t";
	int a, b;
	std::cin >> a >> b;


	// ����һ������ָ�� 
	// ������������ (*�Զ����ָ������)(������������1, ������������2, ...) = Ŀ�꺯������
	int (*add_ptr)(int, int) = add;


	// ��ͨ��ʽ���ú���
	// ����  
	// int a = 8;
	// int *ptr = &a;
	// ���Կ��ɣ�����������ʵ���Ǻ�����ַ
	int result_function_normal_call = add(a, b);
	std::cout << "..function normal call resualt :: " << a << " + " << b << " = " << result_function_normal_call << "\n";

	// ����ָ�뷽ʽ���ú���
	int result_function_pointer_call = add_ptr(a, b);
	std::cout << "..function pointer call resualt :: " << a << " + " << b << " = " << result_function_pointer_call << "\n";




	return 0;
}


// ���������ĺ���
int add(int a, int b) {

	return a + b;

}

