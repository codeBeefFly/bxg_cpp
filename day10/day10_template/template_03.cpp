/*

需求：

可变参数函数模板出处理

省略号的方式


要处理省略号方式的可变参数，
使用四个宏的宏`va_start`、`va_arg`、`va_end` 、 `va_list`

包含头文件 <cstdarg>


抄一遍

*/


#include <iostream>
#include <cstdarg>
#include <iomanip>


int add(int count, ...) {	// count：可变参数个数
	
	va_list vaList;

	va_start(vaList, count);

	int sum{ 0 };
	for (int i = 0; i < count; i++) {
	
		//// 打印数据
		//int result = va_arg(vaList, int);	// 每一次在list中取出一个值，相当于 pop
		//std::cout << "...接收值为::\t" << result << "\n";

		// 计算总和
		sum += va_arg(vaList, int);

	}



	va_end(vaList);			// 清理工作

	return sum;

}


int main() {

	std::cout << "..in template_03...\n";

	std::cout << add(5, 1, 2, 3, 4, 5) << "\n";

	return 0;
	
}



