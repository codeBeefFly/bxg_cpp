#include <iostream>
#include <thread>
#include <functional>
//#include <synchapi.h>
#include <Windows.h>

using namespace std;
/*
 * join detach
 */


void print() {
    for (int i = 0; i < 5; i++) {
        cout << "i == " << i << endl;
        Sleep(1000);
    }
}



int main() {

    //���߳�ȥִ�����print������ 5s
    thread t(print);    // explicit thread(_Fn&& _Fx, _Args&&... _Ax)



    //�����߳̽���ȴ�״̬�������߳�ִ�н���֮�����̲߳���ִ�С�
    //t.join();

    //�����߳������ȥ���Լ����У� ���߳�Ҳ������Ҳ�������С�
    //���߳������ˣ����߳�û���꣬����ֹͣ�ˣ�Ҳ���ᱨ�쳣��
    t.detach();

    for (int i = 0; i < 5; i++) {
        cout << "main:: i == " << i << endl;
        Sleep(300);
    }


    //��Ϊ��main�����Ĵ���ִ�н���֮���������߳̾�ִ�н����ˣ�
    //���߳�ִ�н�������ô��ֱ�Ӱѳ���ֹͣ�ˡ�������ֹͣ�������ʱ��
    //���ֻ���һ�����߳�û�����ˡ����Ծͱ���
    // terminate called without an active exception

    cout << "main::: ����ӡ�����" << endl;

    return 0;
}


/*

output:

main:: i == 0
i == 0
main:: i == 1
main:: i == 2
main:: i == 3
i == 1
main:: i == 4
main::: ����ӡ�����

*/