/*

需求：

练习单例-懒汉模式

*/



#include <iostream>


class Bank {

private:

	//1. 创建私有构造函数，不让他人创建对象
	Bank() {}

	//2. 创建一个静态的自己的类对象指针
	static Bank* bank;

public:

	//3. 定义一个创建自己类对象的函数，并将这个对象抛出去
	static Bank* getInstance() {
		if (bank == nullptr) {
			bank = new Bank();
		}

		return bank;	// bank 是一个类对象指针
	}

};


// 在类的外部进行类对象的初始化
Bank* Bank::bank = nullptr;


int main() {

	// 创建 Bank 对象，在堆中，通过 getInstance()
	Bank* bank_1 = Bank::getInstance();
	Bank* bank_2 = Bank::getInstance();

	std::cout << "bank_1 地址:: " << bank_1 << "\n";
	std::cout << "bank_2 地址:: " << bank_2 << "\n";


	return 0;

}


/*

output:

bank_1 地址:: 00000227C271FF30
bank_2 地址:: 00000227C271FF30

*/