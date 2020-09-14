#include <iostream>
#include <thread>
#include <functional>
//#include <synchapi.h>
#include <Windows.h>

#include <mutex>  //mingw  �Լ���װ�ġ�

using namespace std;
/*
 *  ʹ��mutex������̲߳������ʵ�����
 */

mutex m;


void print(string name, int time) {
    for (int i = 0; i < 10; ++i) {
        m.lock();
        cout << name << " ��ӡ���ˣ�" << i << endl;
        m.unlock(); //������߳̽�����֮��������һ�ᡣ ��������̻߳��������ϳ�������
        Sleep(time);
    }
}


void print_2(string name, int time) {
    for (int i = 0; i < 10; ++i) {
        //m.lock();
        cout << name << " ��ӡ���ˣ�" << i << endl;
        //m.unlock(); //������߳̽�����֮��������һ�ᡣ ��������̻߳��������ϳ�������
        Sleep(time);
    }
}


int main() {

    /*
    
    c++ 11�Ƴ���һ�׻���`bind` ��������Ԥ�Ȱ�ָ���ɵ���ʵ���ĳЩ�����󶨵����еı�����
    ����һ���µĿɵ���ʵ�壬���ֻ��Ƴ��������ڻص������С�˵�ļ򵥵���ǣ�
    ��һ������ֱ�ӵ��õ�ʵ�壬���ǿ��Զ����ʵ�����һ�°�װ����װ������ʵ�壬
    Ҳ���Ե��ã���ô���������װ��ʵ�壬��ͬ�ڵ���ԭ����ʵ�塣
    
    */
    
    thread t1(bind(print, "�߳�1", 100));
    thread t2(bind(print, "�߳�2", 300));

    t1.join();
    t2.join();



    std::cout << "\n*******************************\n";


    thread t3(bind(print, "�߳�3", 100));
    thread t4(bind(print, "�߳�4", 300));

    t3.join();
    t4.join();


    return 0;
}