/*

����

*/


#include <iostream>
#include <string>

using namespace std;

/**
 *   =delete
 *         =delete ��ʵ�Ǳ�ʾ��ֹ�ù��ܣ���ʾ������ܱ�ɾ�����ˡ�
 *         һ��ֻ�ڿ������� ���� �ƶ����캯������Ż�д��
 *
 *
 *   =default
 */

class stu {
public:
    stu(string ss) {

    }
    stu() = delete;/*{
        cout <<"����" << endl;
    }*/
    stu(const stu& s) = delete;/*{  // ��ֵ
        cout <<"��������" << endl;
    }*/
    stu(stu&& s) = delete;/*{       // ��ֵ
        cout <<"�ƶ�����" << endl;
    }*/
    //~stu() = delete;/*{
    //    cout <<"����" << endl;
    //}*/
    void operator=(const stu& s) = delete;/* {
        cout <<"������ֵ�����" <<endl;
    }*/
    void operator=(stu&& s) {
        cout << "�ƶ���ֵ�����" << endl;
    }

};

int main() {

    stu s1("aa");       //  function stu::~stu() be referenced has been deleted
    //stu s2=s1; //�������졣
    //stu s3 = move(s1);
    stu s4;

    s1 = s4;            // �ƶ�����

    return 0;
}
