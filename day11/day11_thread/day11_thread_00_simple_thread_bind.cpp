/*

����

�򵥵�
�߳�
�߳�+bind



֪ʶ�㣺





*/





#include <iostream>
#include <thread>
#include <functional>
//#include <synchapi.h>
#include <Windows.h>    // Sleep ʹ��������� 

using namespace std;
/*
 * �̵߳ļ�ʹ��
 */

void printI() {
    for (int i = 0; i < 10; ++i) {
        cout << "i = " << i << endl;
        // usleep(΢�� ) 1����  = 1000΢��

        Sleep(1000);
    }
}

void printI02(int total) {
    for (int i = 0; i < total; ++i) {
        cout << "i = " << i << endl;
        // usleep(΢�� ) 1����  = 1000΢��
        Sleep(1000);
    }
}


int main() {
    cout << "====" << endl;
    cout << "====" << endl;
    cout << "====" << endl;
    cout << "====" << endl;

    thread t1;

    //����һ���߳�  t
    thread t(printI);   //���߳�t����printI ������
    t.join();           //join ����˼�������̵߳ȴ����߳�ִ�н������ڽ�����һ������˼�������̹߳���


    thread t2(bind(printI02, 5)); //���߳�t����printI ������
    t2.join();

    return 0;
}


/*

output

====
====
====
====
i = 0
i = 1
i = 2
i = 3
i = 4
i = 5
i = 6
i = 7
i = 8
i = 9
i = 0
i = 1
i = 2
i = 3
i = 4

*/