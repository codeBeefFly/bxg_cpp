/*

可以把某个函数A通过参数的方式传递给另一个函数B，
随后在函数B里面执行传递进来的函数A。函数虽然不能直接作为参数来进行传递，
但是函数指针可以。实际上在传递的时候，传递的是指针而已。

要想声明一个函数指针，只需要使用`指针`来替换`函数名`即可。


形参：在函数定义中出现
实参：在函数调用中出现

*/

// 声明一个将要被当作参数传递的函数
#include <iostream>


int add(int a, int b);
// 声明一个含有函数指针的函数
int calc(int a, int b, int (*fun_ptr)(int, int));


// 定义一个接口函数
int main() {
	
	// 创建一个函数指针
	int (*add_fun_ptr)(int, int) = add;
	std::cout << "..enter a and b for addition ::\t";
	int a, b;
	std::cin >> a >> b;
	
	// 第一种函数指针作为参数的方法，声明一个函数指针，在传递这个函数指针的解引用，也就是传递这个函数的地址
	std::cout << "..result_01 is " << a << " + " << b << " = " << calc(a, b, add_fun_ptr) << "\n";	// 这里需要传函数的地址，也就是函数指针的解引用

	// 第二中函数指针作为参数的方法，直接传递这个函数名称，因为函数名称就是函数的地址，相当于函数指针的解引用
	std::cout << "..result_02 is " << a << " + " << b << " = " << calc(a, b, add) << "\n";	


	return 0;
}


// 定义被当作参数传递的函数
int add(int a, int b) {
	return a + b;
}


// 定义含有函数指针的函数
// a, b 形参作为函数指针的形参 
int calc(int a, int b, int(*fun_ptr)(int, int)) {
	return fun_ptr(a, b);
}

