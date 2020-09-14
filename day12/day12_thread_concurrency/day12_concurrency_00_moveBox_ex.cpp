/*

����

�̵߳�ͬ����ϰ concurrency

�ٸ����ӣ������˵���ֻ�ֱ�ͬʱ�ӹ���̨�ϰ����ľ��
�����������ǰ�󽻴�ִ�У������п����ֱۻ�ȥ�������
������ʱҲ�ᷢ��һЩ���������������ʱ����̨��ֻʣ�����һ���ľ�ˣ�
��ֻ�ֱ�ͬʱִ�а���Ĳ�������ʱ�ͻ���һֻ�ֱۿ��Ż����ˡ����߳�ͬ������Ҫ����������⡣

Ϊ�˽��������̲߳��������⣬����ʹ��ͬ��������
��c++���泣�û������������̵߳�ͬ�����⣬���˻�����֮�⣬
����ʹ��`�ź���`��`�ٽ���`��`�¼�`�ȡ�


*/



#include <iostream>
#include <queue>
//#include <synchapi.h>
#include <Windows.h>
#include <thread>
#include <mutex>

using namespace std;



mutex m;    // ȫ�ֻ�����
/*
 * ��ʾ����
 *      ��ֻ��е�۴ӹ���̨�ϰ��ߺ���
 */
class Box {};

//���ǹ���̨
queue<Box> work_table;

//��ʼ������̨����10������
void init() {
    for (int i = 0; i < 10; ++i) {
        Box b;
        work_table.push(b);
    }
}

//����λ�ڹ���̨�ϣ����Ժ��ӵ��ƶ����ܣ�Ӧ�����ɹ���̨���ṩ
//�����е����Ҫ�ӹ���̨�ϰ��ߺ��ӣ���ôӦ�����ֱ������ù���̨���ƶ�������
//��ʵ������һ����������˼�롣
//void moveOut(string name) {
//    m.lock();
//    //cout << name << " ��Ҫȥ���˺��� , ���ӵ�������" << work_table.size() << endl;
//    if (!work_table.empty()) { //false�� ��ʾ���滹�С�  true :��ʾ���п��� û�к����ˡ�
//
//        Sleep(1);
//
//        work_table.pop(); // ���ߺ���
//
//        cout << name << " ������һ�����ӣ���ʣ�£�" << work_table.size() << endl;
//    }
//    //else if (work_table.empty()) {
//    //    std::cout << "������ĿΪ���� 0������...\n";
//    //    m.unlock();
//    //    //exit(0);
//    //    //return;
//    //    //ExitThread;
//    //    abort();
//    //}
//    m.unlock();
//}


bool moveOut(string name) {
    m.lock();

    if (!work_table.empty()) {
        Sleep(1);
        work_table.pop();
        cout << name << " ������һ�����ӣ���ʣ�£�" << work_table.size() << endl;
        m.unlock();
        return true;
    }
    std::cout << name << " ���ڲ�����û�к�����...\n";
    m.unlock();
    return false;
}

//���ֱ�
void leftHand() {
    //while (true) {
    //    moveOut("����");
    //}
    while(moveOut("����")){}
}

//���ֱ�
void rightHand() {
    //while (true) {
    //    moveOut("����");
    //}
    while(moveOut("����")){}
}


int main() {

    init();

    thread t1(leftHand);
    thread t2(rightHand);

    t1.join();
    t2.join();

    std::cout << "..finish...\n";

    return 0;
}


/*

output


���� ������һ�����ӣ���ʣ�£�9
���� ������һ�����ӣ���ʣ�£�8
���� ������һ�����ӣ���ʣ�£�7
���� ������һ�����ӣ���ʣ�£�6
���� ������һ�����ӣ���ʣ�£�5
���� ������һ�����ӣ���ʣ�£�4
���� ������һ�����ӣ���ʣ�£�3
���� ������һ�����ӣ���ʣ�£�2
���� ������һ�����ӣ���ʣ�£�1
���� ������һ�����ӣ���ʣ�£�0
���� ���ڲ�����û�к�����...
���� ���ڲ�����û�к�����...
..finish...




*/
