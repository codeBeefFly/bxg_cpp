/*

需求：

父类对象调用子类继承的虚函数

*/


#include <iostream>
#include <string>

using namespace std;

/**
 * 虚函数
 */
class person {
public:
    string name = "无名氏";
    virtual void eat() {
        std::cout << "..父亲吃饭...\n";
    }
    virtual void sleep() = 0;   // 纯虚函数 need overrider
};

class stu : public person {
public:
    string school = "传智学院";
    virtual void eat() {    // 子类继承的函数也可以写成 virtual
        std::cout << "..学生吃饭...\n";
    }
    virtual void read() {
        std::cout << "..学生读书...\n";
    }

    virtual void sleep() override {     // 但是父类纯虚函数必须要在子类中定义
        std::cout << "..学生睡觉...\n";
    }
};

int main() {
    //父类的指针接收子类对象
    person* p = new stu();
    p->eat();
    return 0;
}


/*

output:

..学生吃饭...

*/