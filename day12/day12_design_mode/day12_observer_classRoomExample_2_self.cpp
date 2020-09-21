/*

����

 * �۲���ģʽ��
 * ��ϰ�ε�ʱ�򣬰�����˰೤����ѧϰ֮�⣬�е�ͬѧ����Ϸ���е�ͬѧ��NBA��
 * �е�ͬѧ��΢�ţ���ʱ�������һ�����ӣ��ð೤��������������ʱ��֪ͨ���ǣ��𱻰�����ץ����
 *
 * ����������3���� �̵���������5��  �� У��Ҳ����10����
 *
 * ���ģ�����ð���ˡ��೤֪ͨ��һ��֮�󣬾͸��߰೤���Ժ�Ҫ֪ͨ�����Ҵ���~~~~��ר��ѧϰ�ˡ�
 *


 �� Subject �� ���� removeObserver(Observer* ob), ��� ob ���� vector �е� ob����ʹ�� vector
 ���� erase

 �� Observer �� ���� removeSubject(Subject* sub), �ں�����ʹ�� sub->removeObserver ����
 Subject �Ƴ�����

*/


#include <iostream>
#include <Windows.h>
#include <vector>


class Subject;
class Observer;

class Subject {

public:

	Subject() = default;

	// ���������������麯��������ָ������������ɾ������������󣬵��õ�����������
	//~Subject() = default;
	// �麯�����Ǵ��麯����Ҫд default
	virtual ~Subject() = default;		

	virtual void addObserver(Observer* ob) = 0;

	virtual void removeObserver(Observer* ob) = 0;
	
	virtual void notify() = 0;

};


class Observer {

public:

	Observer() = default;

	// ���������������麯��������ָ������������ɾ������������󣬵��õ��������鹹
	//~Observer() = default;
	// �麯�����Ǵ��麯����Ҫдdefault
	virtual ~Observer() = default;

	virtual void addSubject(Subject* sub) = 0;

	virtual void removeSubject() = 0;

	virtual void update() = 0;

};


class Monitor : public Subject {

private:

	std::string name;

	//Observer* ob = nullptr;

	std::vector<Observer*> ob_vector;

public:

	Monitor(std::string name) : name{ name } {}

	~Monitor() = default;

	void addObserver(Observer* ob) override {
		//this->ob_vector;
		ob_vector.push_back(ob);
	}

	void removeObserver(Observer* ob) override {
		for (auto i = ob_vector.begin(); i != ob_vector.end(); i++) {
			if (*i == ob) {
				std::cout << "==Monitorִ���Ƴ�����...\n";
				i = ob_vector.erase(i);

				//if (i == ob_vector.end()) {
				//	i--;
				//}

				if (i == ob_vector.end()) {	// �α굽end������������
					break;
				}
			}
		}
	}

	void notify() override {
		for (Observer* ob : this->ob_vector) {
			ob->update();
		}
		
		//for (auto i = ob_vector.begin(); i < ob_vector.end(); i++) {
		//	(*i)->update();
		//}
	}

};


class ZS : public Observer{

private:

	std::string name;

	Subject* sub = nullptr;

public:

	ZS(std::string name) : name{ name } {}

	~ZS() = default;

	void addSubject(Subject* sub) override {
		this->sub = sub;
	}

	void removeSubject() override {
		if (this->sub != nullptr) {
			std::cout << "..*ͬѧ[" << this->name << "]֪ͨ Monitor �Ƴ��Լ�...\n";
			this->sub->removeObserver(this);
			this->sub = nullptr;
		}
	}

	void update() override {
		std::cout << "..ͬѧ[" << this->name << "]�յ� Monitor ֪ͨ...\n";
	}
};


class WW : public Observer {

private:

	std::string name;

	Subject* sub = nullptr;

public:

	WW(std::string name) : name{ name } {}

	~WW() = default;

	void addSubject(Subject* sub) override {
		this->sub = sub;
	}

	void removeSubject() override {
		if (this->sub != nullptr) {
			std::cout << "..*ͬѧ[" << this->name << "]֪ͨ Monitor �Ƴ��Լ�...\n";
			this->sub->removeObserver(this);
			this->sub = nullptr;
		}
	}

	void update() override {
		std::cout << "..ͬѧ[" << this->name << "]�յ� Monitor ֪ͨ...\n";
	}
};


class LS : public Observer {

private:

	std::string name;

	Subject* sub = nullptr;

public:

	LS(std::string name) : name{ name } {}

	~LS() = default;

	void addSubject(Subject* sub) override {
		this->sub = sub;
	}

	void removeSubject() override {
		if (this->sub != nullptr) {
			std::cout << "..*ͬѧ[" << this->name << "]֪ͨ Monitor �Ƴ��Լ�...\n";
			this->sub->removeObserver(this);
			this->sub = nullptr;
		}
	}

	void update() override {
		std::cout << "..ͬѧ[" << this->name << "]�յ� Monitor ֪ͨ...\n";
	}
};


int main() {

	Subject* monitor = new Monitor("�೤");

	Observer* zs = new ZS("����");
	Observer* ls = new LS("����");
	Observer* ww = new WW("����");

	monitor->addObserver(zs);
	monitor->addObserver(ls);
	monitor->addObserver(ww);

	zs->addSubject(monitor);
	ls->addSubject(monitor);
	ww->addSubject(monitor);

	for (int i = 1; i < 33; i++) {
		std::cout << "..i = " << i << "\n";
		if (i % 3 == 0) {
			monitor->notify();
		}
		else if (i % 7 == 0) {
			monitor->notify();
			ls->removeSubject();
		}
		else if (i % 11 == 0) {
			monitor->notify();
			ww->removeSubject();
		}

		Sleep(500);
	}

	return 0;
}


/*

output

..i = 1
..i = 2
..i = 3
..ͬѧ[����]�յ� Monitor ֪ͨ...
..ͬѧ[����]�յ� Monitor ֪ͨ...
..ͬѧ[����]�յ� Monitor ֪ͨ...
..i = 4
..i = 5
..i = 6
..ͬѧ[����]�յ� Monitor ֪ͨ...
..ͬѧ[����]�յ� Monitor ֪ͨ...
..ͬѧ[����]�յ� Monitor ֪ͨ...
..i = 7
..ͬѧ[����]�յ� Monitor ֪ͨ...
..ͬѧ[����]�յ� Monitor ֪ͨ...
..ͬѧ[����]�յ� Monitor ֪ͨ...
..*ͬѧ[����]֪ͨ Monitor �Ƴ��Լ�...
==Monitorִ���Ƴ�����...
..i = 8
..i = 9
..ͬѧ[����]�յ� Monitor ֪ͨ...
..ͬѧ[����]�յ� Monitor ֪ͨ...
..i = 10
..i = 11
..ͬѧ[����]�յ� Monitor ֪ͨ...
..ͬѧ[����]�յ� Monitor ֪ͨ...
..*ͬѧ[����]֪ͨ Monitor �Ƴ��Լ�...
==Monitorִ���Ƴ�����...
..i = 12
..ͬѧ[����]�յ� Monitor ֪ͨ...
..i = 13
..i = 14
..ͬѧ[����]�յ� Monitor ֪ͨ...
..i = 15
..ͬѧ[����]�յ� Monitor ֪ͨ...
..i = 16
..i = 17
..i = 18
..ͬѧ[����]�յ� Monitor ֪ͨ...
..i = 19
..i = 20
..i = 21
..ͬѧ[����]�յ� Monitor ֪ͨ...
..i = 22
..ͬѧ[����]�յ� Monitor ֪ͨ...
..i = 23
..i = 24
..ͬѧ[����]�յ� Monitor ֪ͨ...
..i = 25
..i = 26
..i = 27
..ͬѧ[����]�յ� Monitor ֪ͨ...
..i = 28
..ͬѧ[����]�յ� Monitor ֪ͨ...
..i = 29
..i = 30
..ͬѧ[����]�յ� Monitor ֪ͨ...
..i = 31
..i = 32

*/
