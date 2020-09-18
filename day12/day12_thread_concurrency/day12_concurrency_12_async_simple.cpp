
/*

����

ѧϰ async ����

���߳̽��շ���ֵ

һ����˵������������߳��ڲ�ִ�У�������ִ����Ϻ�
��Ҫ��ȡ�������ķ���ֵ���������߳�ִ�н�����ͨ���ı��м�����ķ�ʽ֮�⣬
û�и��õİ취�ˡ� 
async �������˼汸thread�Ĺ���֮�⣬�����Ի�ȡ�������ķ���ֵ��


async ���������� <future> ͷ�ļ���

*/


#include <iostream>
#include <thread>
#include <functional>
#include <future>
#include <Windows.h>


int add(int a, int b) {

	{
		std::cout << "..id = " << std::this_thread::get_id() << "\n";
		Sleep(3000);
	}
	return a + b;
}


int demo1() {

	std::thread t1(add, 3, 4);
	std::thread t2(std::bind(add, 3, 4));
	
	t1.join();
	t2.join();

	return 0;
}


int main() {

	// ʹ�� future<type> f = async(������������1��...) �õ��߳��к����ķ���ֵ
	
	{
		std::cout << "..in main::id = " << std::this_thread::get_id() << "\n";
	}
	
	std::future<int> f = std::async(add, 3, 4);
	int result = f.get();
	std::cout << "result2 = " << result << "\n";

	return 0;
}


/*

output:

..in main::id = 31736
..id = 34584
result2 = 7


*/