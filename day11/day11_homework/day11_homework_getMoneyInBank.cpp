#include <iostream>
#include <thread>
//#include <synchapi.h>
//#include <unistd.h>
//#include <io.h>
#include <Windows.h>
#include <mutex>
#include <functional>

using namespace std;

/*
 * �����˻���û�п��ܳ��� -100 ???
 *  100 ��
 *      �Ű� ���趼ȥȡǮ��  100.
 *
 *      �Ű��ڹ�̨��ȡ100 �� ������Աһ����������100 ����ȡ�� ����100�������� --- ������ȥ����100��Ǯ  ��Ҫ5s
 *          5s�����Ű��ִӹ�̨ȡ����100�顣   �˻��ͱ䣺 -100
 *
 *      ����ȥATM ȡ100 ��ATM�����жϣ�������100 �� ��ȡ�� ���Űֵȴ�5���ʱ�������Ѿ���ATM ȡ��100��Ǯ�ˡ�
 *
 *
 */

mutex mt;


class bank {
    int money = 1000;
public:
    int getMoney(string name, int m, int sleep_time) {

        //�ж�����Ƿ����
        mt.lock();
        if (money >= m) {

            //��ν���̲߳������Ƕ���߳�����ռһ����Դ�� ����ֻ��һ�ݣ����������˺ܶࡣ
            //�������Ŷӣ�һ��һ�������Ѳ��б�ɴ��С������⴮һ������

            Sleep(sleep_time);
            //���˺ſ�Ǯ
            money -= m; //��Ϊmoney�ǹ��е���Դ��
            cout << name << " ȡ���� " << m << " ���˻���ʣ �� " << money << endl;
            mt.unlock();
            return 1;
        }
        else {
            cout << name << " ��ȡǮ���������㣡" << endl;
            mt.unlock();
            return 0;
        }


    }
};

class human {

    //�������еĶ���
    bank* b;
    string name;
public:
    human(bank* b, string name) : b(b), name(name) {

    }

    void getMoney(int money, int sleep_time) {
        while (true) {
            //�������е�ȡǮ����
            int result = b->getMoney(name, money, sleep_time);
            if (result == 0) {
                break;
            }

        }
    }

};

int main() {

    //1 �������ж���
    bank b;

    //2. �����ͻ�
    human h1(&b, "�Ű�");
    human h2(&b, "����");

    //3. ʹ���߳�ģ��������ȡǮ��
    thread t1(std::bind(&human::getMoney, h1, 100, 300));
    thread t2(std::bind(&human::getMoney, h2, 100, 200));


    t1.join();
    t2.join();

    return 0;
}


/*
output:


�Ű� ȡ���� 100 ���˻���ʣ �� 900
���� ȡ���� 100 ���˻���ʣ �� 800
���� ȡ���� 100 ���˻���ʣ �� 700
���� ȡ���� 100 ���˻���ʣ �� 600
�Ű� ȡ���� 100 ���˻���ʣ �� 500
���� ȡ���� 100 ���˻���ʣ �� 400
���� ȡ���� 100 ���˻���ʣ �� 300
�Ű� ȡ���� 100 ���˻���ʣ �� 200
�Ű� ȡ���� 100 ���˻���ʣ �� 100
�Ű� ȡ���� 100 ���˻���ʣ �� 0
���� ��ȡǮ���������㣡
�Ű� ��ȡǮ���������㣡

D:\W_workPlace\bxg_cpp\day11\build\Debug\day11_homework_getMoneyInBank.exe (process 28412) exited with code 0.
Press any key to close this window . . .


*/