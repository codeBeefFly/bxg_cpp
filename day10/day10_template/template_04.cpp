/*

����

ģ����

ʹ�� initializer_list

������������ ��������(initializer_list<Ԫ������> list_����)

ʹ�õ�������ʽ list_����.begin(), list_����.end(), listָ��++

��һ��

���������ӷ����������Ի�ȡ����������

�ڶ����ӷ�������Ԫ��������ģ�壬��������������������ģ�廯

*/


#include <iostream>
#include <initializer_list>


int add(std::initializer_list<int> list) {

	// ���ԣ���ӡ�б�����
	//for (auto ptr = list.begin(); ptr < list.end(); ptr++) {
	//	std::cout << *ptr << "\t";
	//}
	// 1       3       5       7

	int sum{ 0 };
	for (auto ptr = list.begin(); ptr < list.end(); ptr++) {
		sum += *ptr;
	}

	return sum;
}



int main() {

	std::cout << "..in template_04...\n";

	std::cout << add({ 1, 3, 5, 7 });		//  ������� {}
	//std::cout << add( 1, 3, 5, 7 );		// ����


	return 0;
}


/*

output

16


*/