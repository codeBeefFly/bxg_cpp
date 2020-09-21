/*

需求：

模拟 班长，同学类，使用观察者模式

1. 创建 Subject 抽象类
2. 创建 Observer 抽象类

3. 班长 Monitor 类继承 Subject 类
4. 学生n Student 类继承 Observer 类

记着 notify 定义在类外，Observer 类后

*/


#include <iostream>
#include <Windows.h>
#include <vector>


class Subject;
class Observer;


class Subject {		// 被观察者抽象类

public:

	Subject() = default;

	~Subject() = default;

	virtual void addObserver(Observer* ob) = 0;

	virtual void notify() = 0;

};


class Observer {	// 观察者抽象类

private:

	//std::string name;
	//Subject* sub = nullptr;		// 父类的私有 不能被子类继承

public:

	Observer() = default;

	~Observer() = default;

	virtual void addSubject(Subject* sub) = 0;

	virtual void update() = 0;

};


class Monitor : public Subject {

private:

	std::vector<Observer*> ob_vector;

	std::string name;

public:

	Monitor(std::string name) : name{ name } {};

	void addObserver(Observer* ob) {
		this->ob_vector.push_back(ob);
	}

	void notify();		// 定义在类外

};


class ZS : public Observer {

private:

	std::string name;

	Subject* sub = nullptr;

public:

	ZS(std::string name) : name{ name } {};

	void addSubject(Subject* sub) {
		this->sub = sub;
	}

	void update() {
		std::cout << "..学生[" << name << "]接收到通知...\n";
	}

};


class LS : public Observer {

private:

	std::string name;

	Subject* sub = nullptr;

public:

	LS(std::string name) : name{ name } {};

	void addSubject(Subject* sub) {
		this->sub = sub;
	}

	void update() {
		std::cout << "..学生[" << name << "]接收到通知...\n";
	}

};


class WW : public Observer {

private:

	std::string name;

	Subject* sub = nullptr;

public:

	WW(std::string name) : name{ name } {};

	void addSubject(Subject* sub) {
		this->sub = sub;
	}

	void update() {
		std::cout << "..学生[" << name << "]接收到通知...\n";
	}

};


void Monitor::notify() {		// 定义在类外

	for (Observer* ob : this->ob_vector) {
		std::cout << "==老师来了，[" << this->name << "]通知开小差的同学们...\n";
		ob->update();
	}

}

int main() {

	Observer* ob_0 = new ZS("zs");
	Observer* ob_1 = new LS("ls");
	Observer* ob_2 = new WW("ww");

	Subject* monitor = new Monitor("monitor");
	//Monitor* monitor = new Monitor("monitor");

	ob_0->addSubject(monitor);
	ob_1->addSubject(monitor);
	ob_2->addSubject(monitor);

	monitor->addObserver(ob_0);
	monitor->addObserver(ob_1);
	monitor->addObserver(ob_2);

	for (int i = 0; i < 10; i++) {
		std::cout << "..i = " << i << "\n";
		if (i == 5) {
			monitor->notify();
		}
		Sleep(1000);
	}

	return 0;
}


/*

output

..i = 0
..i = 1
..i = 2
..i = 3
..i = 4
..i = 5
==老师来了，[monitor]通知开小差的同学们...
..学生[zs]接收到通知...
==老师来了，[monitor]通知开小差的同学们...
..学生[ls]接收到通知...
==老师来了，[monitor]通知开小差的同学们...
..学生[ww]接收到通知...
..i = 6
..i = 7
..i = 8
..i = 9

*/