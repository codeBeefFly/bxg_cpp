/*

����

�۲���		Observer��������Ϣ�����£�����ѧ��



���۲���		Subject��֪ͨ�۲��ߣ��೤
��Ҫ����֪ͨ���� setObserver


*/


#include <iostream>
#include <Windows.h>


class Observer {
	
private:

	// ��ʱ�����ñ��۲��ߣ�Ŀ����󣬿������κ�֪ͨ����Ŀ��

public:

	void update() {
		std::cout << "..�۲����յ�֪ͨ...\n";
	}

};


class Subject {

private:
	
	Observer* ob;

public:

	void setObserver(Observer* ob) {
		this->ob = ob;
	}

	void notify() {
		std::cout << "..���۲��߿�ʼ֪ͨ�۲���...\n";
		this->ob->update();
	}

};



int main() {

	Observer ob;
	Subject sb;

	sb.setObserver(&ob);

	for (int i = 0; i < 10; i++) {
		std::cout << "..i = " << i << "\n";
		if (i % 5 == 0) {
			sb.notify();
		}
		Sleep(1000);
	}

	return 0;
}

