/*
* function
*  1. �����൱�еľ�̬��Ա����
*      function<����ֵ <���������Ĳ�������>> = ����::������
*      f(����);
*
*  2. �����൱�е���ͨ��Ա����
*      a. ������Ҫע��ĵط������յĺ�����ʱ����Ҫʹ��  &����:: ��������ָ��������λ��
*
*      b. �����Ĳ�����һ����һ����������͡�
*
*      function<����ֵ <��������� , ���������Ĳ�������>> f = &����::������
*      f(���� �� ����);
*
*
*/

#include <iostream>
#include <functional>

using namespace std;


class stu {

public:
    static void read() {
        cout << "ѧ���ڿ���" << endl;
    }

    void eat(string name) {
        cout << "ѧ���ڳ� " << name << endl;
    }

    void play(string where, string sport) {
        cout << "ѧ����" << where << " ��" << sport << endl;
    }

};



int main() {

    // ���þ�̬��Ա����
    function<void()> f_static = stu::read;
    f_static();

    // ������ͨ��Ա����
    stu s_eat;
    function<void(stu, string)> f_eat = &stu::eat;
    f_eat(s_eat, "jacob");


    stu s_play;
    function<void(stu&, string, string)> f_play = &stu::play;
    f_play(s_play, "here", "baseball");

}


/*

output

ѧ���ڿ���
ѧ���ڳ� jacob
ѧ����here ��baseball


*/