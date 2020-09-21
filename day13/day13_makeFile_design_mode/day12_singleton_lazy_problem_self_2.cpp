/*

需求：

单例模式中的懒汉模式



static成员变量需要在类定义体外进行初始化与定义，
因为static数据成员独立该类的任意对象存在，
它是与类关联的对象，不与类对象关联。

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
	
	static std::mutex* m;		// 在静态空间中创建

	static int count_instance;	// static成员变量需要在类定义体外进行初始化与定义
	static int count_access;

	//3. 定义 静态 函数用来创建类对象 返回类对象指针
	//4. 为了避免多线程同时并发获取对象，使用类互斥锁
	static Bank* getInstance() {

		count_access++;
		
		m->lock();				// 创建对象前加锁
		std::cout << "..上锁...\n";

		if (bank == nullptr) {
			bank = new Bank();
			std::cout << "第 " << count_access << " 次创建对象...\n";
			count_instance++;
		}

		Sleep(1000);

		m->unlock();			// 创建对象后解锁
		std::cout << "..解锁...\n";
	
		return bank;
	}

};


// 在类外部初始化类对象
int Bank::count_instance = 0;
int Bank::count_access = 0;
std::mutex* Bank::m = new std::mutex();
Bank* Bank::bank = nullptr;


// 定义一个全局的不停创建函数对象的函数
void createBank() {
	while (true) {
		std::cout << std::this_thread::get_id() << " 第 " << Bank::count_access << " 次尝试创建新对象...\n";
		Bank* new_bank = Bank::getInstance();
		if (Bank::count_access == 20) {
			break;
		}
	}
}


int main() {

	//{
	//	// 创建类对象指针
	//	//在多个线程同时并发获取对象的情况下，
	//	//还是有可能出现创建多实例的情况。
	//	Bank* bank_1 = Bank::getInstance();
	//	Bank* bank_2 = Bank::getInstance();
	//}


	//{
	//	// 使用线程
	//	Bank* bank_1 = Bank::getInstance();
	//	Bank* bank_2 = Bank::getInstance();
	//	Bank* bank_3 = Bank::getInstance();
	//	Bank* bank_4 = Bank::getInstance();
	//}


	{
		std::thread t1(createBank);
		std::thread t2(createBank);

		t1.join();
		t2.join();

	}



	return 0;
}



/*

output:


..上锁...
..创建对象...
..上锁...
..解锁...
..解锁...
..第 2 次尝试创建新对象...
..上锁...
..解锁...
..第 2 次尝试创建新对象...
..上锁...
..解锁...
..第 3 次尝试创建新对象...
..上锁...
..解锁...
..第 4 次尝试创建新对象...
..上锁...
..解锁...
..第 5 次尝试创建新对象...
..上锁...
..解锁...
..第 6 次尝试创建新对象...
..上锁...
..解锁...
..第 7 次尝试创建新对象...
..上锁...
..解锁...
..第 8 次尝试创建新对象...
..上锁...
..解锁...
..第 10 次尝试创建新对象...
..上锁...
..解锁...
..第 10 次尝试创建新对象...
..上锁...
..解锁...
..第 11 次尝试创建新对象...
..上锁...
..解锁...
..第 12 次尝试创建新对象...
..上锁...
..解锁...
..第 13 次尝试创建新对象...
..上锁...
..解锁...
..第 14 次尝试创建新对象...
..上锁...
..解锁...
..第 15 次尝试创建新对象...
..上锁...
..解锁...
..第 16 次尝试创建新对象...
..上锁...
..解锁...





*/




