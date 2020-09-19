/*

����

����ģʽ�е�����ģʽ



static��Ա������Ҫ���ඨ��������г�ʼ���붨�壬
��Ϊstatic���ݳ�Ա������������������ڣ�
������������Ķ��󣬲�������������

*/


#include <iostream>
#include <mutex>
#include <condition_variable>
#include <thread>
#include <Windows.h>
#include <future>


class Bank {

private:

	//1. ����˽�й��캯��
	Bank() {}

public:

	//2. ���� ��̬ �����ָ��
	static Bank* bank;
	
	static std::mutex* m;		// �ھ�̬�ռ��д���

	static int count_instance;	// static��Ա������Ҫ���ඨ��������г�ʼ���붨��
	static int count_access;

	//3. ���� ��̬ ����������������� ���������ָ��
	//4. Ϊ�˱�����߳�ͬʱ������ȡ����ʹ���໥����
	static Bank* getInstance() {

		count_access++;
		
		if (bank == nullptr) {

			m->lock();				// ��������ǰ����
			std::cout << "..����...\n";

			if (bank == nullptr) {
				bank = new Bank();
				std::cout << "�� " << count_access << " �δ�������...\n";
				count_instance++;
			}

			Sleep(1000);

			m->unlock();			// ������������
			std::cout << "..����...\n";
	
		}
		
		return bank;

	}

};


// �����ⲿ��ʼ�������
int Bank::count_instance = 0;
int Bank::count_access = 0;
std::mutex* Bank::m = new std::mutex();
Bank* Bank::bank = nullptr;


// ����һ��ȫ�ֵĲ�ͣ������������ĺ���
void createBank() {
	while (true) {
		std::cout << std::this_thread::get_id() << " �� " << Bank::count_access << " �γ��Դ����¶���...\n";
		Bank* new_bank = Bank::getInstance();
		if (Bank::count_access == 20) {
			break;
		}
	}
}

void createBank_2() {
	while (true) {
		std::future<Bank*> f = std::async(&Bank::getInstance);
	}
}


int main() {

	//{
	//	// ���������ָ��
	//	//�ڶ���߳�ͬʱ������ȡ���������£�
	//	//�����п��ܳ��ִ�����ʵ���������
	//	Bank* bank_1 = Bank::getInstance();
	//	Bank* bank_2 = Bank::getInstance();
	//}


	//{
	//	// ʹ���߳�
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


880014152 �� 0 ��  �γ��Դ����¶���...
0..����...
 �γ��Դ����¶���...
8800�� 2 �δ�������...
 �� 2 �γ��Դ����¶���...
8800 �� 3 �γ��Դ����¶���...
8800 �� 4 �γ��Դ����¶���...
8800 �� 5 �γ��Դ����¶���...
8800 �� 6 �γ��Դ����¶���...
8800 �� 7 �γ��Դ����¶���...
8800 �� 8 �γ��Դ����¶���...
8800 �� 9 �γ��Դ����¶���...
8800 �� 10 �γ��Դ����¶���...
8800 �� 11 �γ��Դ����¶���...
8800 �� 12 �γ��Դ����¶���...
8800 �� 13 �γ��Դ����¶���...
8800 �� 14 �γ��Դ����¶���...
8800 �� 15 �γ��Դ����¶���...
8800 �� 16 �γ��Դ����¶���...
8800 �� 17 �γ��Դ����¶���...
8800 �� 18 �γ��Դ����¶���...
8800 �� 19 �γ��Դ����¶���...
..����...




*/




