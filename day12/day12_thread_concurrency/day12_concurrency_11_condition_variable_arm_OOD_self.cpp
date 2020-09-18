/*

����

ʹ���������ķ�ʽ����������������
1. ����һ�� Box ��
2. ����һ�� WorkTable ��
	˽�г�Ա������
		1. ������
		2. ��������
		3. Box ����
	���г�Ա
		1. ����������ʼ��5������
		2. moveIn ������������ӣ�����ֻҪ�к��ӣ���֪ͨ�ȴ�����֪ͨ��Ĵ�ӡ������ҪΨһ��
		3. moveOut ������������ӣ�����ֻҪ Box ����û�к��ӣ��͵ȴ����к��ӣ�����Ψһ��
3. ����һ�� leftHand ��
	˽�г�Ա������
		1. WorkTable �����
	���г�Ա��
		1. ��������ʹ��������ʼ��
		2. moveIn ���������������� moveIn ���������Ҳ�ͣѭ��

3. ����һ�� rightHand ��
	˽�г�Ա������
		1. WorkTable �����
	���г�Ա��
		1. ��������ʹ��������ʼ��˽�г�Ա����
		2. moveOut ���������������� moveOut ���������Ҳ�ͣѭ��

*/


#include <iostream>
#include <Windows.h>	// Sleep()
#include <mutex>
#include <thread>
#include <condition_variable>
#include <queue>


class Box {};


class WorkTable {
private:

	std::mutex m;
	std::condition_variable cv;
	std::queue<Box> qBox;

public:

	WorkTable() {
		for (int i = 0; i < 5; i++) {
			Box new_box;
			qBox.push(new_box);
		}
	}

	//void moveIn() {
	//	while (true) {
	//		Box new_box;
	//		qBox.push(new_box);

	//		cv.notify_all();

	//		std::unique_lock<std::mutex> ul(m);
	//		std::cout << "..����һ�����ӣ���������: " << qBox.size() << "\n";
	//		ul.unlock();

	//		Sleep(3000);
	//	}
	//}


	//void moveOut() {
	//	while (true) {
	//		std::unique_lock<std::mutex> ul(m);
	//		if (qBox.empty()) {
	//			cv.wait(ul);
	//			continue;	// ����ѭ����������������
	//		}
	//		qBox.pop();
	//		std::cout << "*****�ó�һ�����ӣ���������: " << qBox.size() << "\n";
	//		
	//		Sleep(1000);
	//	}
	//}

	void moveIn() {
		
		Box new_box;
		qBox.push(new_box);

		cv.notify_all();

		std::unique_lock<std::mutex> ul(m);
		std::cout << "..����һ�����ӣ���������: " << qBox.size() << "\n";
		ul.unlock();

		Sleep(3000);

	}

	void moveOut() {
		
		std::unique_lock<std::mutex> ul(m);

		/*
	
		template <class _Predicate>
		void wait(unique_lock<mutex>& _Lck, _Predicate _Pred) { // wait for signal and test predicate
			while (!_Pred()) {
				wait(_Lck);
			}
		}
		
		*/
		////�������̨�к��ӣ��򲻽���ȴ�״̬��
		//���lambda���ʽ����true�� �������ȴ���
		//���lambda���ʽ����false �������ȴ���
		cv.wait(ul, [&] {
			//std::cout << "=====�ȴ���...\n";		// ������
			//return qBox.size() > 0;				// ������
			if (qBox.size() > 0) {
				return true;
			}
			else {
				std::cout << "=====�ȴ���...\n";
				return false;
			}
		});

		//if (qBox.empty()) {
		//	std::cout << "=====�ȴ���...\n";
		//	cv.wait(ul);
		//}

		qBox.pop();
		std::cout << "=====���ְ���һ�����ӣ���ʣ: " << qBox.size() << "\n";

		ul.unlock();

		Sleep(1000);


	}

};


class LeftArm {
private:
	
	WorkTable* wt;		// ΪʲôҪ����ָ��

public:

	LeftArm(WorkTable* wt) : wt(wt) {}

	void moveIn() {
		
		while (true) {
			wt->moveIn();
		}
	
	}
};


class RightArm {
private:

	WorkTable* wt;

public:

	RightArm(WorkTable* wt) : wt(wt) {}

	void moveOut() {

		while (true) {
			wt->moveOut();
		}

	}

};



int main() {

	WorkTable wt;
	
	LeftArm larm(&wt);
	RightArm rarm(&wt);

	std::thread t1(&LeftArm::moveIn, larm);		// �����������
	std::thread t2(&RightArm::moveOut, rarm);

	t1.join();
	t2.join();
	


	return 0;
}


/*

output

..����һ�����ӣ���������: 6
=====���ְ���һ�����ӣ���ʣ: 5
=====���ְ���һ�����ӣ���ʣ: 4
=====���ְ���һ�����ӣ���ʣ: 3
..����һ�����ӣ���������: 4
=====���ְ���һ�����ӣ���ʣ: 3
=====���ְ���һ�����ӣ���ʣ: 2
=====���ְ���һ�����ӣ���ʣ: 1
..����һ�����ӣ���������: 2
=====���ְ���һ�����ӣ���ʣ: 1
=====���ְ���һ�����ӣ���ʣ: 0
=====�ȴ���...
..����һ�����ӣ���������: 1
=====���ְ���һ�����ӣ���ʣ: 0
=====�ȴ���...
..����һ�����ӣ���������: 1
=====���ְ���һ�����ӣ���ʣ: 0
=====�ȴ���...
..����һ�����ӣ���������: 1
=====���ְ���һ�����ӣ���ʣ: 0
=====�ȴ���...
..����һ�����ӣ���������: 1
=====���ְ���һ�����ӣ���ʣ: 0
=====�ȴ���...
..����һ�����ӣ���������: 1
=====���ְ���һ�����ӣ���ʣ: 0
=====�ȴ���...
..����һ�����ӣ���������: 1
=====���ְ���һ�����ӣ���ʣ: 0
=====�ȴ���...
..����һ�����ӣ���������: 1
=====���ְ���һ�����ӣ���ʣ: 0
=====�ȴ���...
..����һ�����ӣ���������: 1
=====���ְ���һ�����ӣ���ʣ: 0
=====�ȴ���...
..����һ�����ӣ���������: 1
=====���ְ���һ�����ӣ���ʣ: 0
=====�ȴ���...

D:\W_workPlace\bxg_cpp\day12\build\Debug\day12_concurrency_11_condition_variable_arm_OOD_self.exe (process 34104) exited with code -1073741510.
Press any key to close this window . . .



*/

/*

output

..����һ�����ӣ���������: 6
=====���ְ���һ�����ӣ���ʣ: 5
=====���ְ���һ�����ӣ���ʣ: 4
=====���ְ���һ�����ӣ���ʣ: 3
..����һ�����ӣ���������: 4
=====���ְ���һ�����ӣ���ʣ: 3
=====���ְ���һ�����ӣ���ʣ: 2
=====���ְ���һ�����ӣ���ʣ: 1
..����һ�����ӣ���������: 2
=====���ְ���һ�����ӣ���ʣ: 1
=====���ְ���һ�����ӣ���ʣ: 0
=====�ȴ���...
..����һ�����ӣ���������: 1
=====���ְ���һ�����ӣ���ʣ: 0
=====�ȴ���...
..����һ�����ӣ���������: 1
=====���ְ���һ�����ӣ���ʣ: 0
=====�ȴ���...
..����һ�����ӣ���������: 1
=====���ְ���һ�����ӣ���ʣ: 0
=====�ȴ���...
..����һ�����ӣ���������: 1
=====���ְ���һ�����ӣ���ʣ: 0
=====�ȴ���...
..����һ�����ӣ���������: 1
=====���ְ���һ�����ӣ���ʣ: 0
=====�ȴ���...
..����һ�����ӣ���������: 1
=====���ְ���һ�����ӣ���ʣ: 0
=====�ȴ���...

D:\W_workPlace\bxg_cpp\day12\build\Debug\day12_concurrency_11_condition_variable_arm_OOD_self.exe (process 25664) exited with code -1073741510.
Press any key to close this window . . .



*/