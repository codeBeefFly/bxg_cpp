//
// Created by xiaomi on 2020/3/18.
//

#include "stu.h"
#include <iostream>
using namespace std;

stu::stu(){
    cout <<"stu�޲ι���" <<endl;

}



stu::stu(string no , string name):no{no}{
    this-> name = name;
    //this->name = name;
    cout <<"stu�вι���" <<endl;
}

//�������涨����ĳ�Ա��Ӧ���ڸ���Ĺ��캯���ϳ�ʼ����
/*stu::stu(string no , string name):human(name),no{no}{
    //this->name = name;
    cout <<"stu�вι���" <<endl;
}*/
stu::~stu(){
    cout <<"stu����" <<endl;
}

//����ֱ��д���Ǹ���ĺ�������֪���л��ǲ��У�
void stu::work(){
//    ������ʦ���ڵ�ѧ����Ӣ�ģ��������ѧ����������,
//            ��ͬѧ��ѧ����10086 ��������ѧӢӢ�
    cout << endl;
    cout << " ************************ " <<endl;
    cout << endl;
    cout << "��ʦ����Ϣ��" <<endl;
    cout<< sp_teacher->name << " : "<< sp_teacher->subject << endl;


    cout << "ѧ������Ϣ��" <<endl;
    cout<< name << " : "<< no << endl;
}
void stu::setTeacher(shared_ptr<teacher> sp1){
    sp_teacher = sp1;
}