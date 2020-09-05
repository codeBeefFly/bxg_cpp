/*

需求：
 
一旦定义了有参构造函数之后，编译器将不会替我们生成无参构造函数 。 
此时可以自己编写无参构造函数（哪怕函数体是空的），但是此举增加了程序员的编程工作量。

更值得一提的是，手动定义的无参构造函数的代码执行效率要低于编译器自动生成的无参构造函数。

*/


#include <iostream>
#include <string>

using namespace std;

/**
 *   =delete
 *         =delete 其实是表示禁止该功能，表示这个功能被删除掉了。
 *         一般只在拷贝构造 或者 移动构造函数里面才会写。
 *
 *
 *   =default
 */

class stu {
public:
    //stu() = default;  //表示使用编译器提供的那一套默认的无参构造函数。
    /*stu(){
        cout << "无参构造" <<endl;
    }*/

    //如果自己的无参构造函数里面，没有任何有效的代码，那么其实不用写出来函数体，而是
    //使用 =default 关键字来替代函数体。
    //stu() =default;

    stu() = default;

    stu(string name) {
        cout << "有参构造" << endl;
    }

};

int main() {

    stu s("张三");

    stu s2;

    return 0;
}
