#include <iostream>
//#include <synchapi.h>
#include <Windows.h>
#include <thread>
#include <queue>
#include <condition_variable>

using namespace std;

/*
 * ���ֱ�ÿ��3���ӣ����԰����һ�����ӣ����ֱ�ÿ��1���ӿ��԰���һ�����ӡ�
 * �������̨��û���˺��ӣ���ô���ֱ�Ӧ��Ҫ�������ߵ�״̬��
 * ��Ȼ���߿��Խ������ֱ���ѯ���еĴ�����������Ȼ�޷��ﵽ����
 *
 * ʹ�����������������
 */

class Box {};

queue<Box> q;

mutex m;

condition_variable cv;

void init() {
    for (int i = 0; i < 10; ++i) {
        Box b;
        q.push(b);
    }
}

void leftHand() {
    while (true) {

        // lock_guard<mutex> lg(m);

        Box b;
        q.push(b);

        //ֻҪ���ְ�����һ�����ӣ�������֪ͨ����
        cv.notify_all();            // һ��Ҫ��֪ͨ����ִ����
        unique_lock<mutex> ul(m);   // Ψһ������ lock_guard ���й��ܲ��ҿ����ֶ��ͷ���
        cout << "���ְ����һ�����ӣ�����̨�ĺ���������" << q.size() << endl;
        ul.unlock();
        Sleep(3000);
    }
}


void rightHand() {
    while (true) {

        unique_lock<mutex> ul(m);
        //����ȥ����̨����ӣ��������̨�ǿյģ���ô����Ӧ�ý���ȴ�״̬��
        if (q.empty()) {
            cout << "����̨Ϊ�գ����ֽ���ȴ�״̬" << endl;
            cv.wait(ul);
        }

        //������ǿվ�Ҫ�����
        q.pop();
        cout << "���ְ�����һ�����ӣ���ʣ�� " << q.size() << endl;

        Sleep(1000);

    }
}



int main() {

    init();

    thread t1(leftHand);
    thread t2(rightHand);


    t1.join();
    t2.join();

    return 0;
}
