/*

����

ʹ�ÿɱ亯��ģ��ʵ�ּӷ�

��������ܲ���

*/



#include <iostream>


// �ݹ麯����ֹ
int add() {
	std::cout << "..�ݹ���ֹ...\n";
	return 0;
}
//void add() {}	// �����  elem_0 + add()������ add() �����з���ֵ

template <typename T, typename ... K>
T add(T elem_0, K ... elem_n) {
	return elem_0 + add(elem_n ...);	// �����  elem_0 + add()������ add() �����з���ֵ
}


int main() {

	std::cout << "..in template_07_recursive_unpack_add...\n";

	std::cout << "..sum of 1, 2, 3, 4, 5 = " << add(1, 2, 3, 4, 5) << "\n";

	return 0;
}


/*

output

..in template_07_recursive_unpack_add...
..�ݹ���ֹ...
..sum of 1, 2, 3, 4, 5 = 15

*/