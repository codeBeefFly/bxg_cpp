/*

����

��д ����ģʽ˫��
+ ���߳� + async

*/



#include <iostream>
#include <thread>
#include <future>
#include <Windows.h>



class Bank {

private:

	Bank() {}

public:

	static Bank* bank;

	static std::mutex* m;

	static Bank* getInstance() {

		std::cout << "...getInstance �����߳�:: " << std::this_thread::get_id() << "\n";

		if (bank == nullptr) {

			m->lock();

			if (bank == nullptr) {
				bank = new Bank();
			}

			std::cout << "...���������˯��1000ms...\n";
			Sleep(1000);

			m->unlock();

		}

		std::cout << "...���ض���ǰ˯��3000ms...\n";
		Sleep(3000);

		return bank;

	}

};



std::mutex* Bank::m = new std::mutex();
Bank* Bank::bank = nullptr;



void async_fun() {
	while (true) {
		std::future<Bank*> f = std::async(&Bank::getInstance);
		std::cout << "...async_bank instance address: " << f.get() << "\n";
	}
}



void concurrency_fun() {
	while (true) {
		Bank* bank = Bank::getInstance();
		std::cout << "...concu_bank instance address: " << bank << "\n";
	}
}



int main() {


	std::thread t1(async_fun);
	std::thread t2(concurrency_fun);

	t1.join();
	t2.join();


	return 0;
}


/*

output:


...getInstance �����߳�:: 23252
...���������˯��1000ms...
...getInstance �����߳�:: 26864
...���ض���ǰ˯��3000ms...
...���ض���ǰ˯��3000ms...
...async_bank instance address: 000001E0D1593580
...getInstance �����߳�:: 26864
...���ض���ǰ˯��3000ms...
...concu_bank instance address: 000001E0D1593580
...getInstance �����߳�:: 23252
...���ض���ǰ˯��3000ms...
...async_bank instance address: 000001E0D1593580
...getInstance �����߳�:: 26864
...���ض���ǰ˯��3000ms...
...concu_bank instance address: 000001E0D1593580
...getInstance �����߳�:: 23252
...���ض���ǰ˯��3000ms...
...async_bank instance address: 000001E0D1593580
...getInstance �����߳�:: 26864
...���ض���ǰ˯��3000ms...
...concu_bank instance address: 000001E0D1593580
...getInstance �����߳�:: 23252
...���ض���ǰ˯��3000ms...
...async_bank instance address: 000001E0D1593580
...getInstance �����߳�:: 26864
...���ض���ǰ˯��3000ms...
...concu_bank instance address: 000001E0D1593580
...getInstance �����߳�:: 23252
...���ض���ǰ˯��3000ms...
...async_bank instance address: 000001E0D1593580
...getInstance �����߳�:: 26864
...���ض���ǰ˯��3000ms...

*/