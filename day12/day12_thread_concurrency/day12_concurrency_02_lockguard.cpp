/*

需求：

lock_guard 学习

c++ 提供了一个模板类 **lock_guard** ，可以对**mutex**进行包装，
在执行**lock_guard**的构造时进行加锁操作，
执行**lock_guard**析构时进行解锁操作

*/		


#include <iostream>
#include <mutex>
#include <thread>
#include <Windows.h>

std::mutex m;	// 全局互斥锁

void fun() {

	for (int i = 0; i < 10; i++) {
		std::lock_guard<std::mutex> lg(m);
		std::cout << std::this_thread::get_id() << " 号线程打印到了: " << i << "\n";
		Sleep(100);
	}


}


int main() {
	std::cout << "..in day12_concurrency_02_lock_guard...\n";

	std::thread t1(fun);
	std::thread t2(fun);

	t1.join();
	t2.join();


	return 0;
}



/*

output

..in day12_concurrency_02_lock_guard...
20968 号线程打印到了: 0
20968 号线程打印到了: 1
20968 号线程打印到了: 2
20968 号线程打印到了: 3
20968 号线程打印到了: 4
20968 号线程打印到了: 5
20968 号线程打印到了: 6
20968 号线程打印到了: 7
20968 号线程打印到了: 8
20968 号线程打印到了: 9
27824 号线程打印到了: 0
27824 号线程打印到了: 1
27824 号线程打印到了: 2
27824 号线程打印到了: 3
27824 号线程打印到了: 4
27824 号线程打印到了: 5
27824 号线程打印到了: 6
27824 号线程打印到了: 7
27824 号线程打印到了: 8
27824 号线程打印到了: 9


*/