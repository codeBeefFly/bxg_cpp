/*

需求：

观察者		Observer，接收信息并更新，看书学生



被观察者		Subject，通知观察者，班长
需要设置通知对象 setObserver


*/


#include <iostream>
#include <Windows.h>


class Observer {
	
private:

	// 暂时不设置被观察者，目标对象，可以是任何通知他的目标

public:

	void update() {
		std::cout << "..观察者收到通知...\n";
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
		std::cout << "..被观察者开始通知观察者...\n";
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

