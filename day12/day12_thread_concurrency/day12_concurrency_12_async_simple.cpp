
/*

需求：

学习 async 函数

用线程接收返回值

一般来说，函数如果在线程内部执行，当函数执行完毕后，
想要获取到函数的返回值。除了在线程执行结束后，通过改变中间变量的方式之外，
没有更好的办法了。 
async 函数除了兼备thread的功能之外，还可以获取到函数的返回值。


async 函数定义在 <future> 头文件中

*/


#include <iostream>
#include <thread>
#include <functional>
#include <future>
#include <Windows.h>


int add(int a, int b) {

	{
		std::cout << "..id = " << std::this_thread::get_id() << "\n";
		Sleep(3000);
	}
	return a + b;
}


int demo1() {

	std::thread t1(add, 3, 4);
	std::thread t2(std::bind(add, 3, 4));
	
	t1.join();
	t2.join();

	return 0;
}


int main() {

	// 使用 future<type> f = async(函数名，参数1，...) 得到线程中函数的返回值
	
	{
		std::cout << "..in main::id = " << std::this_thread::get_id() << "\n";
	}
	
	std::future<int> f = std::async(add, 3, 4);
	int result = f.get();
	std::cout << "result2 = " << result << "\n";

	return 0;
}


/*

output:

..in main::id = 31736
..id = 34584
result2 = 7


*/