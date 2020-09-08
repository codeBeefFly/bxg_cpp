/*

����


�һ��Ǹо� �� �ݹ�ȽϺã�ʲô�����õ�

�ݹ���Ҫ�õݹ�

ʹ�� initializer_list ʵ�ֿɱ����ģ�庯����Ҫ�� <initializer_list>

initializer_list ���Ҫ�õ���

*/


#include <iostream>
#include <initializer_list>


// ����һ����ӡԪ�صĿɱ����ģ�庯��
template <typename T>
void get_elem(std::initializer_list<T> list) {
	for (auto i = list.begin(); i < list.end(); i++) {
		std::cout << *i << "\t";
	}
}


template <typename T>
T sum(std::initializer_list<T> list) {
	T total{};	// ����Ҫ��ʼ����ʹ���޲γ�ʼ��
	for (auto i = list.begin(); i < list.end(); i++) {
		total += *i;
	}
	return total;
}



int main() {

	std::cout << "..in template_08_initialzier_list_self...\n";

	get_elem({ 1, 2, 3, 4, 5 });

	std::cout << "\n..total of 1, 2, 3, 4, 5 = " << sum({ 1, 2, 3, 4, 5 }) << "\n";

	return 0;
}


/*

output:

..in template_08_initialzier_list_self...
1       2       3       4       5
..total of 1, 2, 3, 4, 5 = 15


*/