/*
����

�����̷ֱ߳��Ӧi��ֻҪ �߳�2 ��ӡ�������ܱ�5���������������״̬��ֻ�е� �߳�1
��ӡ�������ܱ� 10 �������Ż�֪ͨ �߳�2 ִ�С�

*/

#include <iostream>
//#include <synchapi.h>
#include <Windows.h>
#include <thread>
#include <mutex>
#include <condition_variable>   // ������������ͷ�ļ�

using namespace std;



/*
 * ��������
 *
 *      mutex :������ʾ����ġ�����߳���ռһ����Դ��
 *      ��֪ͨ���̺߳������棬
 *          cv.notify_all();
 *
 *
 *      ����Ҫ�ȴ����̺߳����У�ʹ�ã�
 *           unique_lock<mutex> ul(m)
 *
 *              cv.wait(ul);
 *
 */

mutex m;  //����Ԫ

condition_variable cv;  //��������

//�߳�1 ���е� �� ��ӡ����������10 ��֪ͨ�߳�2�������Ŵ�ӡ��
void func1() {
    for (int i = 1; i < 50; ++i) {
        lock_guard<mutex>  lg(m);
        cout << "�߳�1:: ��ӡ���� " << i << endl;
        if (i % 10 == 0) {
            //������֪ͨ����������Ҫ���ˡ� �ó��ڵȴ����߳̽��������ߡ�
            std::cout << "..fun1 i = " << i << "\n";
            //cv.notify_all();
            cv.notify_one();
        }
        Sleep(100);
    }
}

//�߳�2���У� ��ӡ����������5 �͵ȴ���
void  func2() {
    for (int i = 1; i < 50; ++i) {
        unique_lock<mutex> ul(m);
        cout << "�߳�2:: ��ӡ����-------> " << i << endl;
        if (i % 5 == 0) { //������5
            cv.wait(ul);
        }
        Sleep(100);
    }
}

int main() {

    thread t1(func1);
    thread t2(func2);

    t2.join();
    t1.join();

    return 0;
}
