/*

需求：

递归

递归计算从  1 加到 10 的和

*/



#include <iostream>


// 递归函数
int sum(int n) {
	if (n == 1) {				// 终止条件
		return 1;
	}
	else {
		return n + sum(n - 1);	// 递归 
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