/*

需求：

 * 观察者模式，
 * 自习课的时候，班里除了班长认真学习之外，有的同学玩游戏，有的同学看NBA，
 * 有的同学聊微信，此时大家想了一个法子，让班长看到班主任来的时候，通知他们，别被班主任抓到。
 *
 * 班主任来（3）， 教导主任来（5）  ， 校长也来（10）。
 *
 * 李四，不想冒险了。班长通知他一次之后，就告诉班长，以后不要通知啦。我从良~~~~我专心学习了。
 *


 在 Subject 中 定义 removeObserver(Observer* ob), 如果 ob 等于 vector 中的 ob，则使用 vector
 函数 erase

 在 Observer 中 定义 removeSubject(Subject* sub), 在函数中使用 sub->removeObserver 请求
 Subject 移除对象

*/


#include <iostream>
#include <Windows.h>
#include <vector>


class Subject;
class Observer;

class Subject {

public:

	Subject() = default;

	// 父类析构必须是虚函数，父类指针接收子类对象，删除的是子类对象，调用的是子类析构
	//~Subject() = default;
	// 虚函数（非纯虚函数）要写 default
	virtual ~Subject() = default;		

	virtual void addObserver(Observer* ob) = 0;

	virtual void removeObserver(Observer* ob) = 0;
	
	virtual void notify() = 0;

};


class Observer {

public:

	Observer() = default;

	// 父类析构必须是虚函数，父类指针接收子类对象，删除的是子类对象，调用的是子类虚构
	//~Observer() = default;
	// 虚函数（非纯虚函数）要写default
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
				std::cout << "==Monitor执行移除操作...\n";
				i = ob_vector.erase(i);

				//if (i == ob_vector.end()) {
				//	i--;
				//}

				if (i == ob_vector.end()) {	// 游标到end，不能再增加
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
			std::cout << "..*同学[" << this->name << "]通知 Monitor 移除自己...\n";
			this->sub->removeObserver(this);
			this->sub = nullptr;
		}
	}

	void update() override {
		std::cout << "..同学[" << this->name << "]收到 Monitor 通知...\n";
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
			std::cout << "..*同学[" << this->name << "]通知 Monitor 移除自己...\n";
			this->sub->removeObserver(this);
			this->sub = nullptr;
		}
	}

	void update() override {
		std::cout << "..同学[" << this->name << "]收到 Monitor 通知...\n";
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
			std::cout << "..*同学[" << this->name << "]通知 Monitor 移除自己...\n";
			this->sub->removeObserver(this);
			this->sub = nullptr;
		}
	}

	void update() override {
		std::cout << "..同学[" << this->name << "]收到 Monitor 通知...\n";
	}
};


int main() {

	Subject* monitor = new Monitor("班长");

	Observer* zs = new ZS("张三");
	Observer* ls = new LS("李四");
	Observer* ww = new WW("王五");

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
..同学[张三]收到 Monitor 通知...
..同学[李四]收到 Monitor 通知...
..同学[王五]收到 Monitor 通知...
..i = 4
..i = 5
..i = 6
..同学[张三]收到 Monitor 通知...
..同学[李四]收到 Monitor 通知...
..同学[王五]收到 Monitor 通知...
..i = 7
..同学[张三]收到 Monitor 通知...
..同学[李四]收到 Monitor 通知...
..同学[王五]收到 Monitor 通知...
..*同学[李四]通知 Monitor 移除自己...
==Monitor执行移除操作...
..i = 8
..i = 9
..同学[张三]收到 Monitor 通知...
..同学[王五]收到 Monitor 通知...
..i = 10
..i = 11
..同学[张三]收到 Monitor 通知...
..同学[王五]收到 Monitor 通知...
..*同学[王五]通知 Monitor 移除自己...
==Monitor执行移除操作...
..i = 12
..同学[张三]收到 Monitor 通知...
..i = 13
..i = 14
..同学[张三]收到 Monitor 通知...
..i = 15
..同学[张三]收到 Monitor 通知...
..i = 16
..i = 17
..i = 18
..同学[张三]收到 Monitor 通知...
..i = 19
..i = 20
..i = 21
..同学[张三]收到 Monitor 通知...
..i = 22
..同学[张三]收到 Monitor 通知...
..i = 23
..i = 24
..同学[张三]收到 Monitor 通知...
..i = 25
..i = 26
..i = 27
..同学[张三]收到 Monitor 通知...
..i = 28
..同学[张三]收到 Monitor 通知...
..i = 29
..i = 30
..同学[张三]收到 Monitor 通知...
..i = 31
..i = 32

*/
