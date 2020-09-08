/*

����

�ɱ����ģ�庯���Ĳ����ݹ���

����һ��ͬ�������հ���

����һ���ɱ����ģ�庯��


�Ҿ��ÿɱ乹�캯����ʡ�Է�ʽ�ܲ���

*/


#include <iostream>


void get_element() {}


template <typename T, typename ... K>	// �� ... ������һ������
void get_element(T elem_0, K ... elem_n) {
	std::cout << "..element = " << elem_0 << "\n";
	get_element(elem_n ...);
}


int main() {

	get_element(1, 2, 3, 4, 5);

	return 0;
}


/*

output:

..element = 1
..element = 2
..element = 3
..element = 4
..element = 5

*/