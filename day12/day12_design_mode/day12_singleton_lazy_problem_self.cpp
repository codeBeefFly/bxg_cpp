/*

����

����ģʽ�е�����ģʽ

*/


#include <iostream>
#include <mutex>
#include <condition_variable>
#include <thread>
#include <Windows.h>


class Bank {

private:

	//1. ����˽�й��캯��
	Bank() {}

public:

	//2. ���� ��̬ �����ָ��
	static Bank* bank;
	
	static std::mutex* m;	// �ھ�̬�ռ��д���

	//3. ���� ��̬ ����������������� ���������ָ��
	//4. Ϊ�˱�����߳�ͬʱ������ȡ����ʹ���໥����
	static Bank* getInstance() {

		m->lock();			// ��������ǰ����
		std::cout << "..����...\n";

		if (bank == nullptr) {
			bank = new Bank();
			std::cout << "..��������...\n";
		}
		
		m->unlock();		// ������������
		std::cout << "..����...\n";

		return bank;
	}

};


// �����ⲿ��ʼ�������
std::mutex* Bank::m = new std::mutex();
Bank* Bank::bank = nullptr;

int main() {

	//{
	//	// ���������ָ��
	//	//�ڶ���߳�ͬʱ������ȡ���������£�
	//	//�����п��ܳ��ִ�����ʵ���������
	//	Bank* bank_1 = Bank::getInstance();
	//	Bank* bank_2 = Bank::getInstance();
	//}


	{
		// ʹ���߳�
		Bank* bank_1 = Bank::getInstance();
		Bank* bank_2 = Bank::getInstance();
		Bank* bank_3 = Bank::getInstance();
		Bank* bank_4 = Bank::getInstance();

		/*
		
		output:
		
		..����...
		..��������...
		..����...
		..����...
		..����...
		..����...
		..����...
		..����...
		..����...

		*/
	}

	return 0;
}





