/*
  
  需求：

  练习简单的观察者与被观察者

  观察者

思路

1. 创建一个观察者类 Observer
	1. 公共访问
		接收通知函数 update

2. 创建一个被观察者类 Subject
	1. 私有访问
		观察者对象变量

	2. 公共访问
		1. 设置观察者函数 setObserver
		2. 通知观察者函数 notify

3. 主函数
	1. 创建观察者对象
	2. 创建目标对象

	3. 目标对象绑定观察者对象

	4. 遍历20次，第五次时目标对象通知观察者，
		没遍历一次睡眠1秒

  
*/


#include <iostream>
#include <Windows.h>


class Observer {

private:

	// 暂时不写

public:

	// 接收信息，更新状态
	void update() {
		std::cout << "..Observer 收到通知了...\n";
	}

};


class Subject {

private:

	// 绑定的观察者
	Observer ob;

public:

	// 设置绑定的观察者对象
	void setObserver(Observer ob) {
		this->ob = ob;	// 为什么是 ->，因为 this == *subject
	}

	void notify() {
		std::cout << "..被观察者达到状态，要去通知观察者了...\n";
		this->ob.update();
	}
};



int main() {

	// 创建观察者与被观察者
	// 观察者，看小说的同学
	Observer ob;
	// 被观察者，班长
	Subject sb;

	// 被观察者绑定观察者
	sb.setObserver(ob);

	// 遍历20次，第五次通知观察者
	for (int i = 0; i < 20; i++) {
		std::cout << "==i = " << i << "\n";
		if (i == 5) {
			sb.notify();
		}
		Sleep(1000);
	}

	return 0;
}

/*

output:


==i = 0
==i = 1
==i = 2
==i = 3
==i = 4
==i = 5
..被观察者达到状态，要去通知观察者了...
..Observer 收到通知了...
==i = 6
==i = 7
==i = 8
==i = 9
==i = 10
==i = 11
==i = 12
==i = 13
==i = 14
==i = 15
==i = 16
==i = 17
==i = 18
==i = 19
*/