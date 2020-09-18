/*

需求：

使用面向对象的方式来处理左右手问题
1. 创建一个 Box 类
2. 创建一个 WorkTable 类
	私有成员变量：
		1. 互斥锁
		2. 条件变量
		3. Box 对列
	公有成员
		1. 构造器：初始化5个盒子
		2. moveIn 函数，搬入盒子（），只要有盒子，就通知等待对象，通知后的打印动作需要唯一锁
		3. moveOut 函数，搬出盒子（），只要 Box 队列没有盒子，就等待，有盒子，就用唯一锁
3. 创建一个 leftHand 类
	私有成员变量：
		1. WorkTable 类对象
	公有成员：
		1. 构造器：使用类对象初始化
		2. moveIn 函数，调用类对象的 moveIn 函数，并且不停循环

3. 创建一个 rightHand 类
	私有成员变量：
		1. WorkTable 类对象
	公有成员：
		1. 构造器：使用类对象初始化私有成员变量
		2. moveOut 函数，调用类对象的 moveOut 函数，并且不停循环

*/


#include <iostream>
#include <Windows.h>	// Sleep()
#include <mutex>
#include <thread>
#include <condition_variable>
#include <queue>


class Box {};


class WorkTable {
private:

	std::mutex m;
	std::condition_variable cv;
	std::queue<Box> qBox;

public:

	WorkTable() {
		for (int i = 0; i < 5; i++) {
			Box new_box;
			qBox.push(new_box);
		}
	}

	//void moveIn() {
	//	while (true) {
	//		Box new_box;
	//		qBox.push(new_box);

	//		cv.notify_all();

	//		std::unique_lock<std::mutex> ul(m);
	//		std::cout << "..推入一个箱子，箱子总数: " << qBox.size() << "\n";
	//		ul.unlock();

	//		Sleep(3000);
	//	}
	//}


	//void moveOut() {
	//	while (true) {
	//		std::unique_lock<std::mutex> ul(m);
	//		if (qBox.empty()) {
	//			cv.wait(ul);
	//			continue;	// 继续循环，跳过下面的语句
	//		}
	//		qBox.pop();
	//		std::cout << "*****拿出一个箱子，箱子总数: " << qBox.size() << "\n";
	//		
	//		Sleep(1000);
	//	}
	//}

	void moveIn() {
		
		Box new_box;
		qBox.push(new_box);

		cv.notify_all();

		std::unique_lock<std::mutex> ul(m);
		std::cout << "..推入一个箱子，箱子总数: " << qBox.size() << "\n";
		ul.unlock();

		Sleep(3000);

	}

	void moveOut() {
		
		std::unique_lock<std::mutex> ul(m);

		/*
	
		template <class _Predicate>
		void wait(unique_lock<mutex>& _Lck, _Predicate _Pred) { // wait for signal and test predicate
			while (!_Pred()) {
				wait(_Lck);
			}
		}
		
		*/
		////如果工作台有盒子，则不进入等待状态。
		//如果lambda表达式返回true， 则跳过等待。
		//如果lambda表达式返回false ，则进入等待。
		cv.wait(ul, [&] {
			//std::cout << "=====等待中...\n";		// 有问题
			//return qBox.size() > 0;				// 有问题
			if (qBox.size() > 0) {
				return true;
			}
			else {
				std::cout << "=====等待中...\n";
				return false;
			}
		});

		//if (qBox.empty()) {
		//	std::cout << "=====等待中...\n";
		//	cv.wait(ul);
		//}

		qBox.pop();
		std::cout << "=====右手搬走一个盒子，还剩: " << qBox.size() << "\n";

		ul.unlock();

		Sleep(1000);


	}

};


class LeftArm {
private:
	
	WorkTable* wt;		// 为什么要传递指针

public:

	LeftArm(WorkTable* wt) : wt(wt) {}

	void moveIn() {
		
		while (true) {
			wt->moveIn();
		}
	
	}
};


class RightArm {
private:

	WorkTable* wt;

public:

	RightArm(WorkTable* wt) : wt(wt) {}

	void moveOut() {

		while (true) {
			wt->moveOut();
		}

	}

};



int main() {

	WorkTable wt;
	
	LeftArm larm(&wt);
	RightArm rarm(&wt);

	std::thread t1(&LeftArm::moveIn, larm);		// 函数，类对象
	std::thread t2(&RightArm::moveOut, rarm);

	t1.join();
	t2.join();
	


	return 0;
}


/*

output

..推入一个箱子，箱子总数: 6
=====右手搬走一个盒子，还剩: 5
=====右手搬走一个盒子，还剩: 4
=====右手搬走一个盒子，还剩: 3
..推入一个箱子，箱子总数: 4
=====右手搬走一个盒子，还剩: 3
=====右手搬走一个盒子，还剩: 2
=====右手搬走一个盒子，还剩: 1
..推入一个箱子，箱子总数: 2
=====右手搬走一个盒子，还剩: 1
=====右手搬走一个盒子，还剩: 0
=====等待中...
..推入一个箱子，箱子总数: 1
=====右手搬走一个盒子，还剩: 0
=====等待中...
..推入一个箱子，箱子总数: 1
=====右手搬走一个盒子，还剩: 0
=====等待中...
..推入一个箱子，箱子总数: 1
=====右手搬走一个盒子，还剩: 0
=====等待中...
..推入一个箱子，箱子总数: 1
=====右手搬走一个盒子，还剩: 0
=====等待中...
..推入一个箱子，箱子总数: 1
=====右手搬走一个盒子，还剩: 0
=====等待中...
..推入一个箱子，箱子总数: 1
=====右手搬走一个盒子，还剩: 0
=====等待中...
..推入一个箱子，箱子总数: 1
=====右手搬走一个盒子，还剩: 0
=====等待中...
..推入一个箱子，箱子总数: 1
=====右手搬走一个盒子，还剩: 0
=====等待中...
..推入一个箱子，箱子总数: 1
=====右手搬走一个盒子，还剩: 0
=====等待中...

D:\W_workPlace\bxg_cpp\day12\build\Debug\day12_concurrency_11_condition_variable_arm_OOD_self.exe (process 34104) exited with code -1073741510.
Press any key to close this window . . .



*/

/*

output

..推入一个箱子，箱子总数: 6
=====右手搬走一个盒子，还剩: 5
=====右手搬走一个盒子，还剩: 4
=====右手搬走一个盒子，还剩: 3
..推入一个箱子，箱子总数: 4
=====右手搬走一个盒子，还剩: 3
=====右手搬走一个盒子，还剩: 2
=====右手搬走一个盒子，还剩: 1
..推入一个箱子，箱子总数: 2
=====右手搬走一个盒子，还剩: 1
=====右手搬走一个盒子，还剩: 0
=====等待中...
..推入一个箱子，箱子总数: 1
=====右手搬走一个盒子，还剩: 0
=====等待中...
..推入一个箱子，箱子总数: 1
=====右手搬走一个盒子，还剩: 0
=====等待中...
..推入一个箱子，箱子总数: 1
=====右手搬走一个盒子，还剩: 0
=====等待中...
..推入一个箱子，箱子总数: 1
=====右手搬走一个盒子，还剩: 0
=====等待中...
..推入一个箱子，箱子总数: 1
=====右手搬走一个盒子，还剩: 0
=====等待中...
..推入一个箱子，箱子总数: 1
=====右手搬走一个盒子，还剩: 0
=====等待中...

D:\W_workPlace\bxg_cpp\day12\build\Debug\day12_concurrency_11_condition_variable_arm_OOD_self.exe (process 25664) exited with code -1073741510.
Press any key to close this window . . .



*/