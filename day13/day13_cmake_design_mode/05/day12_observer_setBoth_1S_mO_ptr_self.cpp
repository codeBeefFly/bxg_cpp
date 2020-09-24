/*

����


1. �ڹ۲����м��� setSubject
2. ��д���۲��ߣ���д�۲���
3. һ�����۲��߿�����Ӷ���۲���


*/


#include <iostream>
#include <Windows.h>
#include <vector>


// ��ǰ������
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

	//void notify() {			// ����use of undefined type 'Observer'��Ҫ�������������������
	//	std::cout << "..Subject ��ʼ֪ͨ Observers...\n";
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
		std::cout << "..Observer " << name << " ���յ�֪ͨ...\n";
	}

};


void Subject::notify() {			// ����use of undefined type 'Observer'��Ҫ������������������⣬
	std::cout << "..Subject ��ʼ֪ͨ Observers...\n";	// ������ Observer ���
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
..Subject ��ʼ֪ͨ Observers...
..Observer ob_0 ���յ�֪ͨ...
..Observer ob_1 ���յ�֪ͨ...
..Observer ob_2 ���յ�֪ͨ...
..i = 6
..i = 7
..i = 8
..i = 9



*/