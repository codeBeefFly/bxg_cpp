#include <iostream>
#include <thread>
#include <functional>
//#include <synchapi.h>
#include <Windows.h>
#include <processthreadsapi.h>

using namespace std;
/*
 *  �����߳�
 *      һ����˵��һ���̵߳Ľ���Ӧ�������߳��ڲ����߼��Ѿ����������Ϊ�����ı�׼��
 *
 *      1.  �߳��ڲ��������Ѿ������ˣ���ô�߳��Զ�������
 *
 *      2. ���������߳���Ȼ���н�����
 *            a. ͨ�������жϣ�Ȼ��ֱ��return ������
 *
 *            b.
 *
 */

void print() {
    for (int i = 0; i < 10; ++i) {
        if (i == 5) {
            exit(0) ; // ��������    
        }
        cout << "i ==" << i << endl;
        this_thread::sleep_for(chrono::seconds(1));
    }

    cout << "print :: END" << endl;
}

int main() {

    thread t(print);

    t.join();

    //�����߳�  msvc  visual studio  vc++
    //CreateThread();
    //TerminateThread( );


    cout << "main::END" << endl;


    return 0;
}


/*

output

i ==0
i ==1
i ==2
i ==3
i ==4
i ==5
i ==6
i ==7
i ==8
i ==9
print :: END
main::END


i ==0
i ==1
i ==2
i ==3
i ==4

*/