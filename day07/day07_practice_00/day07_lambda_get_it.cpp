/*

����
���� lambda �����Ľ���

lambda ���������﷨
[]()->return_type{}

1. ��һ�ֽ��շ�ʽ
auto fun = [](type_1 param_1, ...)->return_type{return ...;};

2. �ڶ��ֽ��շ�ʽ
type (*fun)(type_1, ...) = [](type_1 param_1, ...)->return_type{return ...;};

3. �����ֽ��շ�ʽ
type result = [](type_1 param_1, ...)->return_type{return ...}(argument_1, ...);


*/


#include <iostream>

int add_normal_fun_call (int&& a, int&& b) {
	return a + b;
}


int main() {

	std::cout << "..in day07_lambda_get_it...\n";

	// �������ú���
	std::cout << "..add_normal_fun_call(3, 4) = " << add_normal_fun_call(3, 4) << "\n";

	// ��һ�ַ�ʽ
	auto add_auto_1 = [](int a, int b) { return a + b; };
	std::cout << "..add_auto(3, 4) = " << add_auto_1(3, 4) << "\n";

	auto add_auto_2 = [](int&& a, int&& b) { return a + b; };
	std::cout << "..add_auto(3, 4) = " << add_auto_2(3, 4) << "\n";

	// �ڶ��ַ�ʽ
	int (*add_ptr)(int, int) = [](int a, int b) { return a + b; };
	std::cout << "..add_ptr(3, 4) = " << add_ptr(3, 4) << "\n";

	// �����ַ�ʽ
	int result;
	result = [](int a, int b) { return a + b; }(3, 4);	// ��() ����ֵ��û��() ���غ���ָ��
	std::cout << "..result = " << result << "\n";

	return 0;
}


/*

output

..in day07_lambda_get_it...
..add_normal_fun_call(3, 4) = -858993460   // ����� int&& �ͻ������ֵ��why��������ʹ��һ��&����Ϊ���ص�����ֵ������ֻ���� int
..add_auto(3, 4) = 7
..add_auto(3, 4) = 7
..add_ptr(3, 4) = 7
..result = 7


*/