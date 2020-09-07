/*

����:

�� teacher, student ����ѧϰ shared_ptr

*/


#include <iostream>
#include <memory>

using  namespace std;

/*
 *  shared_ptr �Ļ������ã������������㣬�������� ��
 */
 //���ǰ��������
class stu;



//��ʦ��ѧ��һ��һ
class teacher {
    //��ʾ��ʦһ��һ���ĵ�ѧ����˭��
    shared_ptr<stu> sp;  //���д�����õ����ͣ���ͬ�� unique_ptr<stu> up;


public:
    void setStu(shared_ptr<stu> sp1) {
        sp = sp1;
    }
    teacher() {
        cout << "teacher����" << endl;
    }
    ~teacher() {
        cout << "teacher����" << endl;
    }
};

class stu {

    //��ʾѧ����һ��һ��ʦ��˭��

    //һ�㲻����ô��ʾ����Ϊ������ʾ���õ�����Ϣ���ɽ�ʦ�����ơ�
    // string teacher_name;

    //ͨ�õ�д����
    //teacher  t;
    //teacher  *tp;

    //ʹ������ָ������װԭʼָ�룬����ԭʼ��ָ�룬�����ͷ��ˡ�
    shared_ptr<teacher> sp;

public:
    void setTeacher(shared_ptr<teacher> sp1) {
        sp = sp1;
    }

    stu() {
        cout << "stu����" << endl;
    }
    ~stu() {
        cout << "stu����" << endl;
    }
};



int main() {


    //1. ����2��ԭʼָ��
    teacher* t = new teacher();
    stu* s = new stu();

    //2. ʹ��ԭʼָ���װ����
    shared_ptr <teacher> sp_teacher(t);
    shared_ptr <stu> sp_stu(s);


    //�ý�ʦ����ѧ����
    t->setStu(sp_stu);
    s->setTeacher(sp_teacher);



    return 0;
}



/*

teacher����
stu����

*/
