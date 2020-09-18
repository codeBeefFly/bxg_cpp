/*


思路

1. 创建一个全局互斥锁 mutex m

2. 创建一个 Bank 类
私有：
	固定金额 int money = 1000

公有：
	int getMoney(人名，多少钱，休息多长时间)

		上锁
		判断余额
			充足 ---> 休息一段时间，扣钱，解锁，返回状态
			不足 ---> 解锁，返回状态


3. 创建一个 Human 类
私有：
	Bank 对象指针，用于接收 main 中创建的 Bank 对象
	姓名字符串

公有：
	有参构造函数，Bank指针对象使用使用构造函数参数进行初始化

	void getMoney(金额，休息时间)，循环调用 Bank 的 getMoney，得到返回值
		返回值 == 1 表示有余额，continue
		返回值 == 0 表示无余额，break


*/


#include <iostream>
#include <mutex>
#include <thread>
#include <Windows.h>
#include <functional>


std::mutex m;


class Bank {

private:

	int money_left = 1000;

public:

	int getMoney(std::string name, int money, int sleep_time) {
		m.lock();
		if (money_left >= money) {
			Sleep(sleep_time);

			money_left -= money;
			std::cout << name << " 取走了 " << money << " 元，还剩 " << money_left << " 元\n";
		
			m.unlock();

			return 1;	// 表示还有余额
		}
		else {
			std::cout << name << " 没有取到钱，没有余额了\n";

			m.unlock();

			return 0;	// 表示没有余额
		}
   }

};


class Human {
private:

	Bank* bank;
	std::string name;


public:

	Human(std::string name, Bank* bank) : name{ name }, bank{ bank }{}

	void getMoney(int money, int sleep_time) {
		while (true) {
			int rev = bank->getMoney(this->name, money, sleep_time);

			if (rev == 0) {
				break;
			}
			else if (rev == 1) {
				continue;
			}
			else {
				std::cout << "...error...\n";
				break;
			}
		}
	}

};


int main() {

	Bank bank;

	Human h1("大爷", &bank);
	Human h2("大妈", &bank);

	std::thread t1(std::bind(&Human::getMoney, h1, 100, 300));
	std::thread t2(&Human::getMoney, h2, 50, 100);

	t1.join();
	t2.join();


	return 0;
}