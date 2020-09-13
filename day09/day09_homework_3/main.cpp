#include <iostream>
#include <vector>
#include "stu.h"

using namespace std;

int main() {


    //1. 教师的容器
    /*vector< shared_ptr<teacher> > teacher_vector;

    teacher *t1 = new teacher("张老师","语文");
    teacher *t2 = new teacher("李老师","数学");
    teacher *t3 = new teacher("王老师","英语");

    shared_ptr<teacher> sp_teacher1(t1);
    shared_ptr<teacher> sp_teacher2(t2);
    shared_ptr<teacher> sp_teacher3(t3);

    teacher_vector.push_back(sp_teacher1);
    teacher_vector.push_back(sp_teacher2);
    teacher_vector.push_back(sp_teacher3);*/

   /* vector< shared_ptr<teacher> > teacher_vector{
        shared_ptr<teacher>(new teacher("张老师", "语文")),
        shared_ptr<teacher>(new teacher("李老师", "数学")),
        shared_ptr<teacher>(new teacher("往老师", "英语")),
    };*/

    vector< shared_ptr<teacher> > teacher_vector{
        make_shared<teacher>("张老师", "语文"),
        make_shared<teacher>("李老师", "数学"),
        make_shared<teacher>("王老师", "英语")
    };

    //2. 学生的容器
    vector< shared_ptr<stu> > stu_vector{
            make_shared<stu>("10086","张三"),
            make_shared<stu>("10087","李四"),
            make_shared<stu>("10088","王五")
    };

    //3 . 让学生关联教师，教师关联学生
    for(int i = 0 ; i < stu_vector.size() ; i++){

        //1. 取出来教师
        shared_ptr<teacher> sp_t = teacher_vector[i];

        //2. 取出来学生
        shared_ptr<stu>  sp_s = stu_vector[i];

        //3. 相互关联
        sp_t->setStu(sp_s);
        sp_s->setTeacher(sp_t);
    }

    //4. 打印学生 | 教师
    for(shared_ptr<stu> & sp_s : stu_vector){
        sp_s->work();
    }


    return 0;
}
