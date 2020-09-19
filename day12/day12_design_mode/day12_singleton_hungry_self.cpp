/*

单例模式

特点：
1. 静止别人创建实例 --> 构造函数私有
2. 自己创建实例
3. 把自己创建好的实例抛出去，给别人使用
4. cpp单例都是返回指针


单例的懒汉模式与饿汉模式的区别
懒汉模式使用类成员函数创建实例，并抛出实例指针，仅在类外部初始化实例指针
饿汉模式使用类成员函数抛出实例指针，在类外部创建实例

无论式何种方式，一个类都只会创建一个类对象


*/



#include <iostream>

//int test() {
//
//	std::cout << "..in day12_singleton_hungry_self...\n";
//
//	return 0;
//}


class Bank {

private:

	// 1. 创建一个私有构造
	Bank() {}

public:
	
	// 2. 定义一个 静态 类指针
	static Bank* bank;

	// 3. 定义一个 静态 返回类指针的函数
	static Bank* getInstance() {
		return bank;
	}

};


// 类外部创建类对象
Bank* Bank::bank = new Bank();	// 构造函数私有，使用类静态对象指针指向在静态空间中创建的唯一对象


int main() {

	// 创建一个Bank类指针，指向已经创建的对象
	Bank* bank_1 = Bank::getInstance();
	// 创建一个Bank类指针，指向已经创建的对象
	Bank* bank_2 = Bank::getInstance();

	//打印指针指向的对象的地址
	std::cout << "..bank_1 address: " << bank_1 << "\n";
	std::cout << "..bank_2 address: " << bank_2 << "\n";

	return 0;
}

/*

output

..bank_1 address: 000001833701A630
..bank_2 address: 000001833701A630

*/



