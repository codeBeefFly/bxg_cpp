/*

����ģʽ

�ص㣺
1. ��ֹ���˴���ʵ�� --> ���캯��˽��
2. �Լ�����ʵ��
3. ���Լ������õ�ʵ���׳�ȥ��������ʹ��
4. cpp�������Ƿ���ָ��


����������ģʽ�����ģʽ������
����ģʽʹ�����Ա��������ʵ�������׳�ʵ��ָ�룬�������ⲿ��ʼ��ʵ��ָ��
����ģʽʹ�����Ա�����׳�ʵ��ָ�룬�����ⲿ����ʵ��

����ʽ���ַ�ʽ��һ���඼ֻ�ᴴ��һ�������


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

	// 1. ����һ��˽�й���
	Bank() {}

public:
	
	// 2. ����һ�� ��̬ ��ָ��
	static Bank* bank;

	// 3. ����һ�� ��̬ ������ָ��ĺ���
	static Bank* getInstance() {
		return bank;
	}

};


// ���ⲿ���������
Bank* Bank::bank = new Bank();	// ���캯��˽�У�ʹ���ྲ̬����ָ��ָ���ھ�̬�ռ��д�����Ψһ����


int main() {

	// ����һ��Bank��ָ�룬ָ���Ѿ������Ķ���
	Bank* bank_1 = Bank::getInstance();
	// ����һ��Bank��ָ�룬ָ���Ѿ������Ķ���
	Bank* bank_2 = Bank::getInstance();

	//��ӡָ��ָ��Ķ���ĵ�ַ
	std::cout << "..bank_1 address: " << bank_1 << "\n";
	std::cout << "..bank_2 address: " << bank_2 << "\n";

	return 0;
}

/*

output

..bank_1 address: 000001833701A630
..bank_2 address: 000001833701A630

*/



