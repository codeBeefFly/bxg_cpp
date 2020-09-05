/*

需求：

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
    stu(string ss) {

    }
    stu() = delete;/*{
        cout <<"构造" << endl;
    }*/
    stu(const stu& s) = delete;/*{  // 左值
        cout <<"拷贝构造" << endl;
    }*/
    stu(stu&& s) = delete;/*{       // 右值
        cout <<"移动构造" << endl;
    }*/
    //~stu() = delete;/*{
    //    cout <<"析构" << endl;
    //}*/
    void operator=(const stu& s) = delete;/* {
        cout <<"拷贝赋值运算符" <<endl;
    }*/
    void operator=(stu&& s) {
        cout << "移动赋值运算符" << endl;
    }

};

int main() {

    stu s1("aa");       //  function stu::~stu() be referenced has been deleted
    //stu s2=s1; //拷贝构造。
    //stu s3 = move(s1);
    stu s4;

    s1 = s4;            // 移动构造

    return 0;
}
