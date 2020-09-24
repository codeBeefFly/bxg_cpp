/*

需求，


1. 在观察者中加入 setSubject
2. 先写被观察者，再写观察者
3. 一个被观察者可以添加多个观察者


*/


#include <iostream>
#include <Windows.h>
#include <vector>


// 类前置声明
class Subject;	
class Observer;


class Subject {

private:

	//Observer* ob;
	std::vector<Observer*> ob_vector;

public:


	void addObserver(Observer* ob) {
		ob_vector.push_back(ob);
	}

	//void setObserver(Observer* ob) {
	//	this->ob = ob;
	//}

	//void notify() {			// 报错：use of undefined type 'Observer'，要把这个函数定义在类外
	//	std::cout << "..Subject 开始通知 Observers...\n";
	//	//this->ob->update();
	//	for (Observer* ob : this->ob_vector) {
	//		ob->update();
	//	}
	//}

	void notify();

};


class Observer {
	
private:

	Subject* sub;
	
	std::string name;

public:

	Observer() = default;

	Observer(std::string name, Subject* sub) : name{ name }, sub{ nullptr } {};
	Observer(std::string name) : name{ name } {
		this->sub = nullptr;
	};

	void setSubject(Subject* sub) {
		this->sub = sub;
	}

	void update() {
		std::cout << "..Observer " << name << " 接收到通知...\n";
	}

};


void Subject::notify() {			// 报错：use of undefined type 'Observer'，要把这个函数定义在类外，
	std::cout << "..Subject 开始通知 Observers...\n";	// 并且在 Observer 类后
	//this->ob->update();
	for (Observer* ob : this->ob_vector) {
		ob->update();
	}
}



int main() {

	Observer ob_0("ob_0");
	Observer ob_1("ob_1");
	Observer ob_2("ob_2");
	
	Subject sub;

	ob_0.setSubject(&sub);
	ob_1.setSubject(&sub);
	ob_2.setSubject(&sub);
	
	//sub.setObserver(&ob);

	sub.addObserver(&ob_0);
	sub.addObserver(&ob_1);
	sub.addObserver(&ob_2);


	for (int i = 0; i < 10; i++) {
		std::cout << "..i = " << i << "\n";
		if (i == 5) {
			sub.notify();
		}
		Sleep(1000);
	}



	return 0;
}


/*

output:

..i = 0
..i = 1
..i = 2
..i = 3
..i = 4
..i = 5
..Subject 开始通知 Observers...
..Observer ob_0 接收到通知...
..Observer ob_1 接收到通知...
..Observer ob_2 接收到通知...
..i = 6
..i = 7
..i = 8
..i = 9



*/