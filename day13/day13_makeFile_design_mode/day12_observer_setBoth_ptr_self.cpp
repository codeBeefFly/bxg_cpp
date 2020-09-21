/*

需求，在观察者中加入 setSubject

*/


#include <iostream>
#include <Windows.h>

class Subject;	// 类前置声明

class Observer {
	
private:

	Subject* sub;

public:

	void setSubject(Subject* sub) {
		this->sub = sub;
	}

//private:

	void update() {
		std::cout << "..Observer 接收到通知...\n";
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
		std::cout << "..Subject 开始通知 Observer...\n";
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
