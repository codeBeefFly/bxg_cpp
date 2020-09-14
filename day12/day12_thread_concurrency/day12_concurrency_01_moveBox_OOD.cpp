#include <iostream>
#include <queue>
//#include <synchapi.h>
#include <Windows.h>
#include <thread>
#include <mutex>
#include <functional>

using namespace std;



/*
 * ��ʾ����  - ʹ�������������װ����
 *      ��ֻ��е�۴ӹ���̨�ϰ��ߺ��� �� ����̨�ϳ�ʼ��10�����ӡ�
 */

 //������
class Box {};

//����̨��
class worktable {

    mutex m; //������ |����Ԫ
    queue<Box> q;
public:
    worktable() {
        for (int i = 0; i < 10; ++i) {
            Box b;
            q.push(b);
        }
    }

    int moveOut(string name) {
        m.lock();
        if (!q.empty()) {
            Sleep(500);

            q.pop();

            cout << name << " ������һ������ �� ��ʣ�£�" << q.size() << endl;

            // m.unlock();
            m.unlock();
            return 1;
        }
        m.unlock();
        return 0;
    }


    ~worktable() {
        cout << "����̨������" << endl;
    }

};

//�ֱ���
class hand {

    string name;

    //��Ҫ֪��ȥ������ˡ�
    worktable* wt;
public:
    hand() {}
    hand(worktable* wt, string name) : wt(wt), name(name) {}

    void moveBox() {
        while (true) {
            int code = wt->moveOut(name);
            if (code == 0) break;
        }
    }

    ~hand() {}

};



int main() {

    worktable wt;

    hand h1(&wt, "����");
    hand h2(&wt, "����");

    thread t1(std::bind(&hand::moveBox, h1));       // bind �� functional ����
    thread t2(std::bind(&hand::moveBox, h2));

    t1.join();
    t2.join();

    return 0;
}



/*

output

���� ������һ������ �� ��ʣ�£�9
���� ������һ������ �� ��ʣ�£�8
���� ������һ������ �� ��ʣ�£�7
���� ������һ������ �� ��ʣ�£�6
���� ������һ������ �� ��ʣ�£�5
���� ������һ������ �� ��ʣ�£�4
���� ������һ������ �� ��ʣ�£�3
���� ������һ������ �� ��ʣ�£�2
���� ������һ������ �� ��ʣ�£�1
���� ������һ������ �� ��ʣ�£�0
����̨������


*/