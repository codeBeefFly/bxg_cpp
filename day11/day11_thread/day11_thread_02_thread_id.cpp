#include <iostream>
#include <thread>
#include <functional>
//#include <synchapi.h>
#include <Windows.h>

using namespace std;
/*
 *  �̵߳� ID  �� �߳�����
 */

void print() {

    //namespace this_thread {
    //_NODISCARD thread::id get_id() noexcept;
    
    cout << "print������ӡ���߳�ID��" << this_thread::get_id() << endl;
    for (int i = 0; i < 10; ++i) {
        cout << "i ==" << i << endl;
        //Sleep(1000);  windowsϵͳר�õ�
        // uSleep();  linux ϵͳ�õġ�

        //�����ֲ���ϵͳ�ġ�
        this_thread::sleep_for(chrono::seconds(1));

        //this_thread::sleep_for(chrono::hours(1));
    }
}

int main() {

    cout << "main�������е��̣߳� " << this_thread::get_id() << endl;

    thread t(print);
    cout << "�߳�t��ID�� " << t.get_id() << endl;

    t.join();

    cout << "main:: ����ӡ�����" << endl;
    return 0;
}


/*

output:

main�������е��̣߳� 30068
�߳�t��ID�� 2768
print������ӡ���߳�ID��2768
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
main:: ����ӡ�����

*/