/*

����

ģ�� �೤��ͬѧ�࣬ʹ�ù۲���ģʽ

1. ���� Subject ������
2. ���� Observer ������

3. �೤ Monitor ��̳� Subject ��
4. ѧ��n Student ��̳� Observer ��

���� notify ���������⣬Observer ���

*/


#include <iostream>
#include <Windows.h>
#include <vector>


class Subject;
class Observer;


class Subject {		// ���۲��߳�����

public:

	Subject() = default;

	~Subject() = default;

	virtual void addObserver(Observer* ob) = 0;

	virtual void notify() = 0;

};


class Observer {	// �۲��߳�����

private:

	//std::string name;
	//Subject* sub = nullptr;		// �����˽�� ���ܱ�����̳�

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

	void notify();		// ����������

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
		std::cout << "..ѧ��[" << name << "]���յ�֪ͨ...\n";
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
		std::cout << "..ѧ��[" << name << "]���յ�֪ͨ...\n";
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
		std::cout << "..ѧ��[" << name << "]���յ�֪ͨ...\n";
	}

};


void Monitor::notify() {		// ����������

	for (Observer* ob : this->ob_vector) {
		std::cout << "==��ʦ���ˣ�[" << this->name << "]֪ͨ��С���ͬѧ��...\n";
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
==��ʦ���ˣ�[monitor]֪ͨ��С���ͬѧ��...
..ѧ��[zs]���յ�֪ͨ...
==��ʦ���ˣ�[monitor]֪ͨ��С���ͬѧ��...
..ѧ��[ls]���յ�֪ͨ...
==��ʦ���ˣ�[monitor]֪ͨ��С���ͬѧ��...
..ѧ��[ww]���յ�֪ͨ...
..i = 6
..i = 7
..i = 8
..i = 9

*/