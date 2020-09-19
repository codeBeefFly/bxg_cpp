/*

需求：

单例模式中的懒汉模式

*/


#include <iostream>
#include <mutex>
#include <condition_variable>
#include <thread>
#include <Windows.h>


class Bank {

private:

	//1. 创建私有构造函数
	Bank() {}

public:

	//2. 定义 静态 类对象指针
	static Bank* bank;
	
	static std::mutex* m;	// 在静态空间中创建

	//3. 定义 静态 函数用来创建类对象 返回类对象指针
	//4. 为了避免多线程同时并发获取对象，使用类互斥锁
	static Bank* getInstance() {

		m->lock();			// 创建对象前加锁
		std::cout << "..上锁...\n";

		if (bank == nullptr) {
			bank = new Bank();
			std::cout << "..创建对象...\n";
		}
		
		m->unlock();		// 创建对象后解锁
		std::cout << "..解锁...\n";

		return bank;
	}

};


// 在类外部初始化类对象
std::mutex* Bank::m = new std::mutex();
Bank* Bank::bank = nullptr;

int main() {

	//{
	//	// 创建类对象指针
	//	//在多个线程同时并发获取对象的情况下，
	//	//还是有可能出现创建多实例的情况。
	//	Bank* bank_1 = Bank::getInstance();
	//	Bank* bank_2 = Bank::getInstance();
	//}


	{
		// 使用线程
		Bank* bank_1 = Bank::getInstance();
		Bank* bank_2 = Bank::getInstance();
		Bank* bank_3 = Bank::getInstance();
		Bank* bank_4 = Bank::getInstance();

		/*
		
		output:
		
		..上锁...
		..创建对象...
		..解锁...
		..上锁...
		..解锁...
		..上锁...
		..解锁...
		..上锁...
		..解锁...

		*/
	}

	return 0;
}





