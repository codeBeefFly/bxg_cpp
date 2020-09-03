/*

需求：

静态类型 与 动态类型

*/


#include <iostream>
#include <string>

using namespace std;

/*
 *  静态类型和动态类型
 *      只有继承关系下，才需要这么考虑。
 *
 */

class father {
public:

    father() {
        std::cout << "..父类无参构造...\n";
    }
    ~father() {
        std::cout << "..父类析构函数...\n";
    }

};

class son : public father {
public:

    son() {
        std::cout << "..子类无参构造...\n";
    }
    ~son() {
        std::cout << "..子类析构函数...\n";
    }

};


father* createObj() {
    return new son();
}

int main() {

    //编译阶段就已经明确了类型。

    std::cout << "..1..\n";
    int a = 3;
    string b = "bb";
    son s;

    //真正运行的时候才知晓数据的类型是什么。

    std::cout << "..2..\n";

    father* f = createObj();

    std::cout << "..3..\n";

    return 0;
}



/*

..1..
..父类无参构造...
..子类无参构造...
..2..
..父类无参构造...
..子类无参构造...
..3..
..子类析构函数...
..父类析构函数...

*/