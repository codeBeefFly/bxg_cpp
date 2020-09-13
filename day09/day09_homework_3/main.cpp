#include <iostream>
#include <vector>
#include "stu.h"

using namespace std;

int main() {


    //1. ��ʦ������
    /*vector< shared_ptr<teacher> > teacher_vector;

    teacher *t1 = new teacher("����ʦ","����");
    teacher *t2 = new teacher("����ʦ","��ѧ");
    teacher *t3 = new teacher("����ʦ","Ӣ��");

    shared_ptr<teacher> sp_teacher1(t1);
    shared_ptr<teacher> sp_teacher2(t2);
    shared_ptr<teacher> sp_teacher3(t3);

    teacher_vector.push_back(sp_teacher1);
    teacher_vector.push_back(sp_teacher2);
    teacher_vector.push_back(sp_teacher3);*/

   /* vector< shared_ptr<teacher> > teacher_vector{
        shared_ptr<teacher>(new teacher("����ʦ", "����")),
        shared_ptr<teacher>(new teacher("����ʦ", "��ѧ")),
        shared_ptr<teacher>(new teacher("����ʦ", "Ӣ��")),
    };*/

    vector< shared_ptr<teacher> > teacher_vector{
        make_shared<teacher>("����ʦ", "����"),
        make_shared<teacher>("����ʦ", "��ѧ"),
        make_shared<teacher>("����ʦ", "Ӣ��")
    };

    //2. ѧ��������
    vector< shared_ptr<stu> > stu_vector{
            make_shared<stu>("10086","����"),
            make_shared<stu>("10087","����"),
            make_shared<stu>("10088","����")
    };

    //3 . ��ѧ��������ʦ����ʦ����ѧ��
    for(int i = 0 ; i < stu_vector.size() ; i++){

        //1. ȡ������ʦ
        shared_ptr<teacher> sp_t = teacher_vector[i];

        //2. ȡ����ѧ��
        shared_ptr<stu>  sp_s = stu_vector[i];

        //3. �໥����
        sp_t->setStu(sp_s);
        sp_s->setTeacher(sp_t);
    }

    //4. ��ӡѧ�� | ��ʦ
    for(shared_ptr<stu> & sp_s : stu_vector){
        sp_s->work();
    }


    return 0;
}
