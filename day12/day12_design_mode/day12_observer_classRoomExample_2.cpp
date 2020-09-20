#include <iostream>
//#include <synchapi.h>
#include <Windows.h>
#include <vector>
using namespace std;

/*
 * �۲���ģʽ��
 * ��ϰ�ε�ʱ�򣬰�����˰೤����ѧϰ֮�⣬�е�ͬѧ����Ϸ���е�ͬѧ��NBA��
 * �е�ͬѧ��΢�ţ���ʱ�������һ�����ӣ��ð೤��������������ʱ��֪ͨ���ǣ��𱻰�����ץ����
 *
 * ����������3���� �̵���������5��  �� У��Ҳ����10����
 *
 * ���ģ�����ð���ˡ��೤֪ͨ��һ��֮�󣬾͸��߰೤���Ժ�Ҫ֪ͨ�����Ҵ���~~~~��ר��ѧϰ�ˡ�
 *
 */

class subject;
class obsever {
public:
    //���캯���������麯��
    obsever() = default;

    //��Ҫ֪���۲�˭
    virtual void setSubject(subject* sj) = 0;

    //��ʾ����۲����󶨵��Ǹ�Ŀ�����
    virtual void removeSubject() = 0;

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

    //�й۲��߲���۲�Ŀ������ˡ�
    virtual void removeObsever(obsever* ob) = 0;

    //Ҫȥ֪ͨ�۲���
    virtual void notify(string msg) = 0;

    //���������������麯������Ϊ����ָ����������������ɾ�������������ҲҪ�������������
    virtual  ~subject() = default;
};


//�೤�� : ���۲��ߡ�

class  Monitor : public subject {
    vector<obsever*> vo;

public:

    //��ӹ۲���
    void addObsever(obsever* ob) override {
        vo.push_back(ob);
    }

    //�Ƴ��۲���
    void removeObsever(obsever* ob) {
        for (auto i = vo.begin(); i != vo.end(); i++) {
            //*i �õ������Ԫ�أ� �������ǵ�������Ԫ�ش�ľ���ָ�롣
            if (*i == ob) {
                vo.erase(i);
            }
        }
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
    void removeSubject() {
        sj->removeObsever(this);
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

    void removeSubject() {
        sj->removeObsever(this);
    }

    //��Ҫ�õ�֪ͨ
    void update(string msg) {
        cout << "�����յ�֪ͨ��" << msg << "  ����Ҫ��С˵��!" << endl;
    }



    //��ȻҲ��һ�������������棬Ҳ�����Լ�дһ�������� removeSubject()
   /* ~LS(){
        //ֻҪ���ĵĶ��������ˣ��Ͳ����ܵ�֪ͨ�ˡ�
        sj->removeObsever(this);
    }*/
};

class WW : public obsever {

    subject* sj = nullptr;
public:
    //��Ҫ֪���۲�˭
    void setSubject(subject* sj) {
        this->sj = sj;
    }
    void removeSubject() {
        sj->removeObsever(this);
    }

    //��Ҫ�õ�֪ͨ
    void update(string msg) {
        cout << "�����յ�֪ͨ��" << msg << "  ����Ҫ������!" << endl;
    }
};

//int main() {
int demo() {
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
    for (int i = 1; i < 50; ++i) {

        cout << "i ----> " << i << endl;
        if (i % 3 == 0) {
            s->notify("���������ˣ�");
        }
        if (i % 7 == 0) {
            s->notify("�̵��������ˣ�");
            ls->removeSubject();
        }
        if (i % 10 == 0) {
            s->notify("У�����ˣ�");
        }

        Sleep(1000);
    }





    return 0;
}


class Stu {};

int main() {

    Stu* stu_0 = new Stu;
    Stu* stu_1 = new Stu;
    Stu* stu_2 = new Stu;
    Stu* stu_3 = new Stu;

    std::vector<Stu*> stu_vctor{ stu_0, stu_1, stu_2, stu_3 };

    for (Stu* stu : stu_vctor) {
        std::cout << ".. stu address:: " << stu << "\n";
    }

    int count = 0;
    for (auto i = stu_vctor.begin(); i != stu_vctor.end(); i++) {
        std::cout << "..count = " << count << "\n";
        count++;
        if (*i == stu_1) {
            i = stu_vctor.erase(i);     // erase(iter) ���� iter
        }
    }

    std::cout << "*********************************\n";

    for (Stu* stu : stu_vctor) {
        std::cout << ".. stu address:: " << stu << "\n";
    }

    std::cout << 1 % 11 << "\n";

}