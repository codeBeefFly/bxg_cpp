/*

����
ʹ�� function ģ�� ���ú���
1. ȫ�ֺ���
2. lambda ����

*/


#include <functional>
#include <iostream>



int add(int a, int b) {
	return a + b;
}


int main() {

	std::cout << "..in day11_function_object_01_global_lambda...\n";

	// function ģ�� ����ȫ�ֺ���
	std::function<int(int, int)> f = add;
	std::cout << "...add(3, 4) = " << f(3, 4) << "\n";


	// function ģ�� ����lambda ����
	std::function<int(int, int)> f_lbd = [](int a, int b) { return a + b; };
	std::cout << "...add(3, 4)_lbd = " << f_lbd(3, 4) << "\n";



	return 0;
}



/*

output

..in day11_function_object_01_global_lambda...
...add(3, 4) = 7
...add(3, 4)_lbd = 7


*/