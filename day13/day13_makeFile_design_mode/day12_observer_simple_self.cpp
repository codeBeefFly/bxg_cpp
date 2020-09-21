/*
  
  ����

  ��ϰ�򵥵Ĺ۲����뱻�۲���

  �۲���

˼·

1. ����һ���۲����� Observer
	1. ��������
		����֪ͨ���� update

2. ����һ�����۲����� Subject
	1. ˽�з���
		�۲��߶������

	2. ��������
		1. ���ù۲��ߺ��� setObserver
		2. ֪ͨ�۲��ߺ��� notify

3. ������
	1. �����۲��߶���
	2. ����Ŀ�����

	3. Ŀ�����󶨹۲��߶���

	4. ����20�Σ������ʱĿ�����֪ͨ�۲��ߣ�
		û����һ��˯��1��

  
*/


#include <iostream>
#include <Windows.h>


class Observer {

private:

	// ��ʱ��д

public:

	// ������Ϣ������״̬
	void update() {
		std::cout << "..Observer �յ�֪ͨ��...\n";
	}

};


class Subject {

private:

	// �󶨵Ĺ۲���
	Observer ob;

public:

	// ���ð󶨵Ĺ۲��߶���
	void setObserver(Observer ob) {
		this->ob = ob;	// Ϊʲô�� ->����Ϊ this == *subject
	}

	void notify() {
		std::cout << "..���۲��ߴﵽ״̬��Ҫȥ֪ͨ�۲�����...\n";
		this->ob.update();
	}
};



int main() {

	// �����۲����뱻�۲���
	// �۲��ߣ���С˵��ͬѧ
	Observer ob;
	// ���۲��ߣ��೤
	Subject sb;

	// ���۲��߰󶨹۲���
	sb.setObserver(ob);

	// ����20�Σ������֪ͨ�۲���
	for (int i = 0; i < 20; i++) {
		std::cout << "==i = " << i << "\n";
		if (i == 5) {
			sb.notify();
		}
		Sleep(1000);
	}

	return 0;
}

/*

output:


==i = 0
==i = 1
==i = 2
==i = 3
==i = 4
==i = 5
..���۲��ߴﵽ״̬��Ҫȥ֪ͨ�۲�����...
..Observer �յ�֪ͨ��...
==i = 6
==i = 7
==i = 8
==i = 9
==i = 10
==i = 11
==i = 12
==i = 13
==i = 14
==i = 15
==i = 16
==i = 17
==i = 18
==i = 19
*/