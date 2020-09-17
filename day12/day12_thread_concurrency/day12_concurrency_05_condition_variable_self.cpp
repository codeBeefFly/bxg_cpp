/*

��ϰ condition_variable





*/

#include <iostream>
#include <condition_variable>
#include <thread>
#include <mutex>
#include <Windows.h>


std::mutex m;
std::condition_variable cv;


void fun1() {
	for (int i = 0; i < 100; i++) {
		//std::lock_guard<std::mutex> lg(m);
		std::unique_lock<std::mutex> ul(m);	// ʹ�� unique_lock �� lock_guard ȫ�����ܲ��ҿ����ֶ�����
		std::cout << "fun1 -----> " << i << "\n";
		if (i % 10 == 0) {				// �������10��֪ͨ�ȴ��ĳ���
			cv.notify_all();			// �Ƚ�֪ͨ�Ĳ�ͬλ�õĽ��
			std::cout << "fun1 wait\n";
			//cv.notify_all();			// ֪ͨ
			ul.unlock();				// ����
			Sleep(100);					// ˯��
		}
		Sleep(100);
	}
}


void fun2() {
	for (int i = 0; i < 100; i++) {
		std::unique_lock<std::mutex> ul(m);		// ������Ψһ����Ȼ����
		std::cout << "..fun2 -----> " << i << "\n";
		if (i % 5 == 0) {
			std::cout << "..fun2 wait\n";
			cv.wait(ul);				// ������һֱ�ȴ�
			continue;
		}
		Sleep(100);
	}
}


int main() {

	std::cout << "..in day12_condtion_variable_self...\n";

	std::thread t1(fun1);
	std::thread t2(fun2);
	
	t1.join();
	t2.join();


	return 0;
}



/*

..in day12_condtion_variable_self...
..fun2 -----> 0
..fun2 wait
fun1 -----> 0
fun1 wait
..fun2 -----> 1
..fun2 -----> 2
..fun2 -----> 3
..fun2 -----> 4
..fun2 -----> 5
..fun2 wait
fun1 -----> 1
fun1 -----> 2
fun1 -----> 3
fun1 -----> 4
fun1 -----> 5
fun1 -----> 6
fun1 -----> 7
fun1 -----> 8
fun1 -----> 9
fun1 -----> 10
fun1 wait
..fun2 -----> 6
..fun2 -----> 7
..fun2 -----> 8
..fun2 -----> 9
..fun2 -----> 10
..fun2 wait
fun1 -----> 11
fun1 -----> 12
fun1 -----> 13
fun1 -----> 14
fun1 -----> 15
fun1 -----> 16
fun1 -----> 17
fun1 -----> 18
fun1 -----> 19
fun1 -----> 20
fun1 wait
..fun2 -----> 11
..fun2 -----> 12
..fun2 -----> 13
..fun2 -----> 14
..fun2 -----> 15
..fun2 wait
fun1 -----> 21
fun1 -----> 22
fun1 -----> 23
fun1 -----> 24
fun1 -----> 25
fun1 -----> 26
fun1 -----> 27
fun1 -----> 28
fun1 -----> 29
fun1 -----> 30
fun1 wait
..fun2 -----> 16
..fun2 -----> 17
..fun2 -----> 18
..fun2 -----> 19
..fun2 -----> 20
..fun2 wait
fun1 -----> 31
fun1 -----> 32
fun1 -----> 33
fun1 -----> 34
fun1 -----> 35
fun1 -----> 36
fun1 -----> 37
fun1 -----> 38
fun1 -----> 39
fun1 -----> 40
fun1 wait
..fun2 -----> 21
..fun2 -----> 22
..fun2 -----> 23
..fun2 -----> 24
..fun2 -----> 25
..fun2 wait
fun1 -----> 41
fun1 -----> 42
fun1 -----> 43
fun1 -----> 44
fun1 -----> 45
fun1 -----> 46
fun1 -----> 47
fun1 -----> 48
fun1 -----> 49
fun1 -----> 50
fun1 wait
..fun2 -----> 26
fun1 -----> 51
fun1 -----> 52
fun1 -----> 53
fun1 -----> 54
fun1 -----> 55
fun1 -----> 56
fun1 -----> 57
fun1 -----> 58
fun1 -----> 59
fun1 -----> 60
fun1 wait
..fun2 -----> 27
..fun2 -----> 28
..fun2 -----> 29
..fun2 -----> 30
..fun2 wait
fun1 -----> 61
fun1 -----> 62
fun1 -----> 63
fun1 -----> 64
fun1 -----> 65
fun1 -----> 66
fun1 -----> 67
fun1 -----> 68
fun1 -----> 69
fun1 -----> 70
fun1 wait
..fun2 -----> 31
..fun2 -----> 32
..fun2 -----> 33
..fun2 -----> 34
..fun2 -----> 35
..fun2 wait
fun1 -----> 71
fun1 -----> 72
fun1 -----> 73
fun1 -----> 74
fun1 -----> 75
fun1 -----> 76
fun1 -----> 77
fun1 -----> 78
fun1 -----> 79
fun1 -----> 80
fun1 wait
..fun2 -----> 36
..fun2 -----> 37
..fun2 -----> 38
..fun2 -----> 39
..fun2 -----> 40
..fun2 wait
fun1 -----> 81
fun1 -----> 82
fun1 -----> 83
fun1 -----> 84
fun1 -----> 85
fun1 -----> 86
fun1 -----> 87
fun1 -----> 88
fun1 -----> 89
fun1 -----> 90
fun1 wait
..fun2 -----> 41
..fun2 -----> 42
..fun2 -----> 43
..fun2 -----> 44
..fun2 -----> 45
..fun2 wait
fun1 -----> 91
fun1 -----> 92
fun1 -----> 93
fun1 -----> 94
fun1 -----> 95
fun1 -----> 96
fun1 -----> 97
fun1 -----> 98
fun1 -----> 99


*/