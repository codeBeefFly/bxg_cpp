/*


˼·

1. ����һ��ȫ�ֻ����� mutex m

2. ����һ�� Bank ��
˽�У�
	�̶���� int money = 1000

���У�
	int getMoney(����������Ǯ����Ϣ�೤ʱ��)

		����
		�ж����
			���� ---> ��Ϣһ��ʱ�䣬��Ǯ������������״̬
			���� ---> ����������״̬


3. ����һ�� Human ��
˽�У�
	Bank ����ָ�룬���ڽ��� main �д����� Bank ����
	�����ַ���

���У�
	�вι��캯����Bankָ�����ʹ��ʹ�ù��캯���������г�ʼ��

	void getMoney(����Ϣʱ��)��ѭ������ Bank �� getMoney���õ�����ֵ
		����ֵ == 1 ��ʾ����continue
		����ֵ == 0 ��ʾ����break


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
			std::cout << name << " ȡ���� " << money << " Ԫ����ʣ " << money_left << " Ԫ\n";
		
			m.unlock();

			return 1;	// ��ʾ�������
		}
		else {
			std::cout << name << " û��ȡ��Ǯ��û�������\n";

			m.unlock();

			return 0;	// ��ʾû�����
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

	Human h1("��ү", &bank);
	Human h2("����", &bank);

	std::thread t1(std::bind(&Human::getMoney, h1, 100, 300));
	std::thread t2(&Human::getMoney, h2, 50, 100);

	t1.join();
	t2.join();


	return 0;
}