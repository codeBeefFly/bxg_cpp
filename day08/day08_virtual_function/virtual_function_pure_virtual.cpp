/*

需求：

纯虚函数

纯虚函数是一种特殊的虚函数，C++中包含纯虚函数的类，被称为是“抽象类”。
抽象类不能使用new出对象，只有实现了这个纯虚函数的子类才能new出对象。
C++中的纯虚函数更像是“只提供声明，没有实现”，是对子类的约束。


**纯虚函数就是没有函数体，同时在定义的时候，其函数名后面要加上“= 0”**。

*/





#include <iostream>
#include <string>

using namespace std;

/**
 *   纯虚函数
 *      1. 一个虚函数的后面跟上 =0 就表示这个函数是纯虚函数。没有函数体。
 *      2. 纯虚函数位于的类，是抽象类 ， 抽象类禁止创建对象。
 *          如果允许创建对象，那么假设来调用这个纯虚函数，那么该执行什么代码呢？所以禁止创建对象。
 *      3. 如果子类继承了纯虚函数的类，但是子类没有实现这个纯虚函数，那么该类也是抽象类。
 */

class Animal {
public:

    //每一种动物都有吃的行为，并且每一种动物吃的东西都不太一样。
    //所以，这个函数就不应该在写函数体了。而是交给每一种动物去实现自己的吃的方法。
    // 一个虚函数的后面跟上 =0 就表示这个函数是纯虚函数。没有函数体。
    virtual void eat() = 0;/*{
        cout << "动物在吃饭" <<endl;
    }*/
};

class fish : public Animal {

};

class Cat :public Animal {
public:
    void eat() {
        cout << "猫吃鱼" << endl;
    }
};

class rabbit :public Animal {
public:
    void eat() {
        cout << "兔子在吃萝卜" << endl;
    }
};


int main() {
    Animal* cp = new Cat();
    cp->eat();

    Animal* rp = new rabbit();
    rp->eat();

    return 0;
}


/*

猫吃鱼
兔子在吃萝卜

*/
