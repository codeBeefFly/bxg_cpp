#include <iostream>
#include <string>
#include "teacher.h"
#include "stu.h"
#include <vector>

using namespace std;

//����teacher�����������
void operator >>(istream &in , teacher *t){
    //teacher����������С���ݡ����Բ���ֱ��д�� in >> t;
    in >> t->name >> t->age >> t->subject;
}

void initTeacher(vector<teacher *> &teacher_vector){
    for (int i = 0; i < 3; ++i) {
        /*string name;
        cin >>name;

        int age ;
        cin >> age ;

        string subject ;
        cin >> subject;

        //Ҫ����������������
        teacher *t  = new teacher(name , age , subject);*/

        teacher *t = new teacher();
        cout <<"������� "<< i+1 <<" ����ʦ�����������䡢ѧ��" <<endl;
        cin >> t;

        //���һ�����������ָ�룬��ôҪ�ǳ�С�ģ�������ָ�룬���������¶����ڱ�ĵط��õ�
        teacher_vector.push_back(t);
    }
    cout <<"��ʼ����ʦ�ĺ��������ˣ���ʦ��������С�Ǽ�����" << teacher_vector.size() <<endl;
}

//ѧ�����

void operator >>(istream& in , stu &s){
    in >> s.name >> s.no ;
}

void initStu(vector<stu > &stu_vector ,  vector<teacher *> &teacher_vector) {
    for(int i = 0 ; i < 3 ; i++){
        stu s;
         //��ֵ =  ȡֵ
           // ��������������ж�����
           //ȡ�����ǲ���Խ���ˣ�
           //���������ǲ���û�Ե��ϣ�
           //��Ϊ�������������涼û��ֵ�������������Կ�����
           cout <<"��ʦ�Ĵ�С��" <<teacher_vector.size() <<endl;
           cout <<"aaaa" <<endl;
           s.t =  teacher_vector[i];

        cout <<"������� "<< i+1 <<" ��ѧ����������ѧ��" <<endl;
        cin >> s;

        stu_vector.push_back(s);
    }
}

//�������޸ĵĲ�����
void updateStu( vector<stu > &stu_vector){
    for(stu &s: stu_vector){
        if(s.no == "10088"){
            //�ҵ���ʦ
            teacher *t = s.t;
            t->subject  = "�ߵ���ѧ";

            //����ѭ���� ��Ϊ�п������������10��ѧ����������Ǳ����˵�һ�ξ��ҵ����ѧ���ˣ������9�α�������Ҫ���ˡ�
            break;
        }
    }
}

void printStu(vector<stu > &stu_vector, void(*op)(vector<stu > stu_vector)){
    op(stu_vector);
}


int main() {

    //��ʦ����
    vector<teacher *> teacher_vector;

    //ѧ������
    vector<stu > stu_vector;

    //1. ��ʼ����ʦ
    cout <<"***** ��ʼ����ʦ��Ϣ****" <<endl;
    initTeacher(teacher_vector);
    cout <<"��main��������initTeacher֮���ִ�ӡһ�᣺" << teacher_vector.size() <<endl;

    //2 ��ʼ��ѧ����
    cout <<"***** ��ʼ��ѧ����Ϣ****" <<endl;
    initStu(stu_vector , teacher_vector);

    //3. ����ѧ��
    cout <<"***** ����ѧ����Ϣ****" <<endl;
    updateStu(stu_vector);

    //4. ��ӡѧ��
   /* void(*op)(vector<stu > stu_vector)  = [](vector<stu > stu_vector){
        for(stu s: stu_vector){
            cout << s.name << "\t" << s.no <<endl;
            //����һ��һ��һ�Ľ�ʦָ��
            teacher *t = s.t;
            cout << t->name << "\t" << t->age << "\t" << t->subject <<endl;
        }
    };
    printStu(stu_vector , op);*/

   cout <<"***** ��ӡѧ����Ϣ****" <<endl;
    printStu(stu_vector , [](vector<stu > stu_vector){
        for(stu s: stu_vector){
            cout << s.name << "\t" << s.no <<endl;
            //����һ��һ��һ�Ľ�ʦָ��
            teacher *t = s.t;
            cout << t->name << "\t" << t->age << "\t" << t->subject <<endl;
        }
    });

    return 0;
}



/*

***** ��ʼ����ʦ��Ϣ****
teacher�޲ι���
������� 1 ����ʦ�����������䡢ѧ��
a 1 aaa
teacher�޲ι���
������� 2 ����ʦ�����������䡢ѧ��
b 2 bbb
teacher�޲ι���
������� 3 ����ʦ�����������䡢ѧ��
c 3 ccc
��ʼ����ʦ�ĺ��������ˣ���ʦ��������С�Ǽ�����3
��main��������initTeacher֮���ִ�ӡһ�᣺3
***** ��ʼ��ѧ����Ϣ****
stu�޲ι���
��ʦ�Ĵ�С��3
aaaa
������� 1 ��ѧ����������ѧ��
aa 10086
stu����
stu�޲ι���
��ʦ�Ĵ�С��3
aaaa
������� 2 ��ѧ����������ѧ��
bb 10087
stu����
stu����
stu�޲ι���
��ʦ�Ĵ�С��3
aaaa
������� 3 ��ѧ����������ѧ��
cc 10088
stu����
stu����
stu����
***** ����ѧ����Ϣ****
***** ��ӡѧ����Ϣ****
aa      10086
a       1       aaa
stu����
bb      10087
b       2       bbb
stu����
cc      10088
c       3       �ߵ���ѧ
stu����
stu����
stu����
stu����
stu����
stu����
stu����

*/