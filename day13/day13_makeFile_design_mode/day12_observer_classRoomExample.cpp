#include <iostream>
//#include <synchapi.h>
#include <Windows.h>
#include <vector>
using namespace std;

/*
 * �۲���ģʽ��
 * ��ϰ�ε�ʱ�򣬰�����˰೤����ѧϰ֮�⣬�е�ͬѧ����Ϸ���е�ͬѧ��NBA��
 * �е�ͬѧ��΢�ţ���ʱ�������һ�����ӣ��ð೤��������������ʱ��֪ͨ���ǣ��𱻰�����ץ����
 */

class subject;
class obsever {
public:
    //���캯���������麯��
    obsever() = default;

    //��Ҫ֪���۲�˭
    virtual void setSubject(subject* sj) = 0;

    //��Ҫ�õ�֪ͨ
    virtual void update(string msg) = 0;

    //���������������麯������Ϊ����ָ����������������ɾ�������������ҲҪ�������������
    virtual  ~obsever() = default;
};

class subject {

public:
    //�����ڸ���д���д��룬��Ϊ�������е�Ŀ�������һȺ�˹۲��ߡ�
    //vector <obsever*> vo;
    //���캯���������麯��
    subject() = default;

    //��Ҫ֪����˭�۲졣
    virtual void addObsever(obsever* ob) = 0;

    //Ҫȥ֪ͨ�۲���
    virtual void notify(string msg) = 0;

    //���������������麯������Ϊ����ָ����������������ɾ�������������ҲҪ�������������
    virtual  ~subject() = default;
};


//�೤�� : ���۲��ߡ�

class  Monitor : public subject {
    vector<obsever*> vo;

public:
    void addObsever(obsever* ob) override {
        vo.push_back(ob);
    }

    void notify(string msg) override {
        cout << "�೤�Ѿ�������ĳ��״̬��Ҫȥ֪ͨ�۲�����" << endl;
        for (obsever* ob : vo) {
            ob->update(msg);
        }
    }
};

//
class ZS : public obsever {

    subject* sj = nullptr;
public:
    //��Ҫ֪���۲�˭
    void setSubject(subject* sj) {
        this->sj = sj;
    }

    //��Ҫ�õ�֪ͨ
    void update(string msg) {
        cout << "�����յ�֪ͨ��" << msg << "  ����Ҫ����Ϸ��!" << endl;
    }
};


class LS : public obsever {

    subject* sj = nullptr;
public:
    //��Ҫ֪���۲�˭
    void setSubject(subject* sj) {
        this->sj = sj;
    }

    //��Ҫ�õ�֪ͨ
    void update(string msg) {
        cout << "�����յ�֪ͨ��" << msg << "  ����Ҫ��С˵��!" << endl;
    }
};

class WW : public obsever {
    subject* sj = nullptr;
public:
    //��Ҫ֪���۲�˭
    void setSubject(subject* sj) {
        this->sj = sj;
    }

    //��Ҫ�õ�֪ͨ
    void update(string msg) {
        cout << "�����յ�֪ͨ��" << msg << "  ����Ҫ������!" << endl;
    }
};

int main() {


    //1. ����Ŀ�����
    subject* s = new Monitor();

    //2. �����۲���
    obsever* zs = new ZS();
    obsever* ls = new LS();
    obsever* ww = new WW();

    //3. ����Ŀ�����˭�۲�
    s->addObsever(zs);
    s->addObsever(ls);
    s->addObsever(ww);

    //4. ���ù۲��߹۲��ĸ�Ŀ�����
    zs->setSubject(s);
    ls->setSubject(s);
    ww->setSubject(s);

    //5. ģ����������ˡ�
    for (int i = 1; i < 20; ++i) {

        cout << "i ----> " << i << endl;
        if (i % 5 == 0) {
            s->notify("���������ˣ�");
        }

        Sleep(1000);
    }

    return 0;
}

/*

output:


i ----> 1
i ----> 2
i ----> 3
i ----> 4
i ----> 5
�೤�Ѿ�������ĳ��״̬��Ҫȥ֪ͨ�۲�����
�����յ�֪ͨ�����������ˣ�  ����Ҫ����Ϸ��!
�����յ�֪ͨ�����������ˣ�  ����Ҫ��С˵��!
�����յ�֪ͨ�����������ˣ�  ����Ҫ������!
i ----> 6
i ----> 7
i ----> 8
i ----> 9
i ----> 10
�೤�Ѿ�������ĳ��״̬��Ҫȥ֪ͨ�۲�����
�����յ�֪ͨ�����������ˣ�  ����Ҫ����Ϸ��!
�����յ�֪ͨ�����������ˣ�  ����Ҫ��С˵��!
�����յ�֪ͨ�����������ˣ�  ����Ҫ������!
i ----> 11
i ----> 12
i ----> 13
i ----> 14
i ----> 15
�೤�Ѿ�������ĳ��״̬��Ҫȥ֪ͨ�۲�����
�����յ�֪ͨ�����������ˣ�  ����Ҫ����Ϸ��!
�����յ�֪ͨ�����������ˣ�  ����Ҫ��С˵��!
�����յ�֪ͨ�����������ˣ�  ����Ҫ������!
i ----> 16
i ----> 17
i ----> 18
i ----> 19


*/
