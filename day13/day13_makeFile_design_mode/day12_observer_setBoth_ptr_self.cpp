/*

�����ڹ۲����м��� setSubject

*/


#include <iostream>
#include <Windows.h>

class Subject;	// ��ǰ������

class Observer {
	
private:

	Subject* sub;

public:

	void setSubject(Subject* sub) {
		this->sub = sub;
	}

//private:

	void update() {
		std::cout << "..Observer ���յ�֪ͨ...\n";
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
		std::cout << "..Subject ��ʼ֪ͨ Observer...\n";
		this->ob->update();
	}

};



int main() {

	Observer ob;
	Subject sub;

	ob.setSubject(&sub);
	sub.setObserver(&ob);

	for (int i = 0; i < 10; i++) {
		std::cout << "..i = " << i << "\n";
		if (i == 5) {
			sub.notify();
		}
		Sleep(1000);
	}



	return 0;
}
