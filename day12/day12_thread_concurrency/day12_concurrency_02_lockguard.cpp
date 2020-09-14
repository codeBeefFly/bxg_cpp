/*

����

lock_guard ѧϰ

c++ �ṩ��һ��ģ���� **lock_guard** �����Զ�**mutex**���а�װ��
��ִ��**lock_guard**�Ĺ���ʱ���м���������
ִ��**lock_guard**����ʱ���н�������

*/		


#include <iostream>
#include <mutex>
#include <thread>
#include <Windows.h>

std::mutex m;	// ȫ�ֻ�����

void fun() {

	for (int i = 0; i < 10; i++) {
		std::lock_guard<std::mutex> lg(m);
		std::cout << std::this_thread::get_id() << " ���̴߳�ӡ����: " << i << "\n";
		Sleep(100);
	}


}


int main() {
	std::cout << "..in day12_concurrency_02_lock_guard...\n";

	std::thread t1(fun);
	std::thread t2(fun);

	t1.join();
	t2.join();


	return 0;
}



/*

output

..in day12_concurrency_02_lock_guard...
20968 ���̴߳�ӡ����: 0
20968 ���̴߳�ӡ����: 1
20968 ���̴߳�ӡ����: 2
20968 ���̴߳�ӡ����: 3
20968 ���̴߳�ӡ����: 4
20968 ���̴߳�ӡ����: 5
20968 ���̴߳�ӡ����: 6
20968 ���̴߳�ӡ����: 7
20968 ���̴߳�ӡ����: 8
20968 ���̴߳�ӡ����: 9
27824 ���̴߳�ӡ����: 0
27824 ���̴߳�ӡ����: 1
27824 ���̴߳�ӡ����: 2
27824 ���̴߳�ӡ����: 3
27824 ���̴߳�ӡ����: 4
27824 ���̴߳�ӡ����: 5
27824 ���̴߳�ӡ����: 6
27824 ���̴߳�ӡ����: 7
27824 ���̴߳�ӡ����: 8
27824 ���̴߳�ӡ����: 9


*/