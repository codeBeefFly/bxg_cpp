/*

需求：

使用 条件变量，在有箱子的情况下通知右手

使用条件变量模式修改搬运盒子的条件变量情况

1. 全局，互斥锁
2. 全局，条件变量
3. 全局，队列Box
4. 初始化队列
5. 左手，循环推入box，只要推入了就通知右手来拿，在通知之后使用唯一锁执行打印，解锁，睡眠
6. 右手，循环抓取box，如果队列中没有box，就等待，cv.wait()


*/


#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <windows.h>	// Sleep
#include <queue>


std::mutex m;
std::condition_variable cv;

class Box {};
std::queue<Box> qBox;


void initQueue() {
	for (int i = 0; i < 10; i++) {
		Box new_box;
		qBox.push(new_box);
	}
}


void leftArm() {
	while (true) {
		Box new_box;
		qBox.push(new_box);

		cv.notify_all();

		std::unique_lock<std::mutex> ul(m);
		std::cout << "..左手推入一个盒子，盒子总数: " << qBox.size() << "\n";
		ul.unlock();

		Sleep(3000);
	}
}


void rightArm() {
	while (true) {
		std::unique_lock<std::mutex> ul(m);		// 自然解锁
		
		if (qBox.empty()) {
			std::cout << "..没有盒子了，等待中...\n";
			cv.wait(ul);

			continue;	//
		}

		qBox.pop();
		std::cout << "====右手拿出一个盒子，盒子总数: " << qBox.size() << "\n";
		Sleep(1000);
	}
}


int main() {

	initQueue();

	std::thread t1(leftArm);
	std::thread t2(rightArm);
	
	t1.join();
	t2.join();


	return 0;
}


/*

output


====右手拿出一个盒子，盒子总数: 9
====右手拿出一个盒子，盒子总数: 9
====右手拿出一个盒子，盒子总数: 8
====右手拿出一个盒子，盒子总数: 7
====右手拿出一个盒子，盒子总数: 6
====右手拿出一个盒子，盒子总数: 5
====右手拿出一个盒子，盒子总数: 4
..左手推入一个盒子，盒子总数: 4
====右手拿出一个盒子，盒子总数: 3
====右手拿出一个盒子，盒子总数: 2
====右手拿出一个盒子，盒子总数: 1
====右手拿出一个盒子，盒子总数: 1
====右手拿出一个盒子，盒子总数: 0
..没有盒子了，等待中...
..左手推入一个盒子，盒子总数: 0
..左手推入一个盒子，盒子总数: 1
====右手拿出一个盒子，盒子总数: 0
..没有盒子了，等待中...
..左手推入一个盒子，盒子总数: 1
====右手拿出一个盒子，盒子总数: 0
..没有盒子了，等待中...
..左手推入一个盒子，盒子总数: 1
====右手拿出一个盒子，盒子总数: 0
..没有盒子了，等待中...
..左手推入一个盒子，盒子总数: 1
====右手拿出一个盒子，盒子总数: 0
..没有盒子了，等待中...
..左手推入一个盒子，盒子总数: 1
====右手拿出一个盒子，盒子总数: 0
..没有盒子了，等待中...
..左手推入一个盒子，盒子总数: 1
====右手拿出一个盒子，盒子总数: 0
..没有盒子了，等待中...
..左手推入一个盒子，盒子总数: 1
====右手拿出一个盒子，盒子总数: 0
..没有盒子了，等待中...
..左手推入一个盒子，盒子总数: 1
====右手拿出一个盒子，盒子总数: 0
..没有盒子了，等待中...
..左手推入一个盒子，盒子总数: 1
====右手拿出一个盒子，盒子总数: 0
..没有盒子了，等待中...
..左手推入一个盒子，盒子总数: 1
====右手拿出一个盒子，盒子总数: 0
..没有盒子了，等待中...
..左手推入一个盒子，盒子总数: 1
====右手拿出一个盒子，盒子总数: 0

D:\W_workPlace\bxg_cpp\day12\build\Debug\day12_concurrency_08_condition_variable_arm_self.exe (process 15080) exited with code -1073741510.
Press any key to close this window . . .



*/