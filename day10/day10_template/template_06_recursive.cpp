/*

����

�ݹ�

�ݹ�����  1 �ӵ� 10 �ĺ�

*/



#include <iostream>


// �ݹ麯��
int sum(int n) {
	if (n == 1) {				// ��ֹ����
		return 1;
	}
	else {
		return n + sum(n - 1);	// �ݹ� 
	}
}


int main() {

	std::cout << "..in template_06_recursive...\n";

	std::cout << ".. sum(10) = " << sum(10) << "\n";

	return 0;
}


/*

..in template_06_recursive...
.. sum(10) = 55

*/