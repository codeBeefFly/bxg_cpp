/*

需求:

在 teacher, student 类中学习 shared_ptr

*/


#include <iostream>
#include <memory>

using  namespace std;

/*
 *  shared_ptr 的环形引用，即：我中有你，你中有我 。
 */
 //类的前置声明。
class stu;



//教师和学生一对一
class teacher {
    //表示教师一对一关心的学生是谁。
    shared_ptr<stu> sp;  //如果写了引用的类型，等同于 unique_ptr<stu> up;


public:
    void setStu(shared_ptr<stu> sp1) {
        sp = sp1;
    }
    teacher() {
        cout << "teacher构造" << endl;
    }
    ~teacher() {
        cout << "teacher析构" << endl;
    }
};

class stu {

    //表示学生的一对一教师是谁。

    //一般不会这么表示，因为这样表示，得到的信息是由教师的名称。
    // string teacher_name;

    //通用的写法。
    //teacher  t;
    //teacher  *tp;

    //使用智能指针来包装原始指针，担心原始的指针，忘记释放了。
    shared_ptr<teacher> sp;

public:
    void setTeacher(shared_ptr<teacher> sp1) {
        sp = sp1;
    }

    stu() {
        cout << "stu构造" << endl;
    }
    ~stu() {
        cout << "stu析构" << endl;
    }
};



int main() {


    //1. 创建2个原始指针
    teacher* t = new teacher();
    stu* s = new stu();

    //2. 使用原始指针包装他们
    shared_ptr <teacher> sp_teacher(t);
    shared_ptr <stu> sp_stu(s);


    //让教师关联学生。
    t->setStu(sp_stu);
    s->setTeacher(sp_teacher);



    return 0;
}



/*

teacher构造
stu构造

*/
