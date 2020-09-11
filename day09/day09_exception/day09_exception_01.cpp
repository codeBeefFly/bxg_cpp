#include <iostream>
#include <memory>
#include <vector>
using  namespace std;

/*
 *不抛出异常的处理：
 *
 */

 //举个例子：这个函数是我们开发的，想给别人调用。
 /*
  * 两个整数相除，  参数一 /  参数二
  * 注意： 如果参数二传递的是0 ，那么程序将会直接停止
  *      不会崩溃，而是返回错误的代码 500.
  */
int  calc_div(int a, int b) {
    if (b == 0) {
        //1. 直接终止程序。
       // exit(0);
       //abort();

       //2. 返回错误的代码。
        return 500;
    }
    return a / b;
}


int main() {

    calc_div(5, 0);
    cout << calc_div(4, 2) << endl;
    cout << calc_div(4, 0) << endl;

    cout << "这是最后打印的语句" << endl;


    return 0;
}


/*

output


2
500
这是最后打印的语句

*/
