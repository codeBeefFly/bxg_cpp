/*

����

��ϰ����-����ģʽ

*/



#include <iostream>


class Bank {

private:

	//1. ����˽�й��캯�����������˴�������
	Bank() {}

	//2. ����һ����̬���Լ��������ָ��
	static Bank* bank;

public:

	//3. ����һ�������Լ������ĺ�����������������׳�ȥ
	static Bank* getInstance() {
		if (bank == nullptr) {
			bank = new Bank();
		}

		return bank;	// bank ��һ�������ָ��
	}

};


// ������ⲿ���������ĳ�ʼ��
Bank* Bank::bank = nullptr;


int main() {

	// ���� Bank �����ڶ��У�ͨ�� getInstance()
	Bank* bank_1 = Bank::getInstance();
	Bank* bank_2 = Bank::getInstance();

	std::cout << "bank_1 ��ַ:: " << bank_1 << "\n";
	std::cout << "bank_2 ��ַ:: " << bank_2 << "\n";


	return 0;

}


/*

output:

bank_1 ��ַ:: 00000227C271FF30
bank_2 ��ַ:: 00000227C271FF30

*/