#include <iostream>
#include <thread>
#include <functional>
//#include <synchapi.h>
#include <Windows.h>

using namespace std;
/*
 * join detach
 */


void print() {
    for (int i = 0; i < 5; i++) {
        cout << "i == " << i << endl;
        Sleep(1000);
    }
}



int main() {

    //让线程去执行这个print函数。 5s
    thread t(print);    // explicit thread(_Fn&& _Fx, _Args&&... _Ax)



    //让主线程进入等待状态，等子线程执行结束之后，主线程才能执行。
    //t.join();

    //让子线程剖离出去，自己运行， 主线程也不耽误，也可以运行。
    //主线程走完了，子线程没走完，程序停止了，也不会报异常。
    t.detach();

    for (int i = 0; i < 5; i++) {
        cout << "main:: i == " << i << endl;
        Sleep(300);
    }


    //因为当main函数的代码执行结束之后，整个主线程就执行结束了，
    //主线程执行结束，那么就直接把程序停止了。但是在停止西程序的时候，
    //发现还有一个子线程没走完了。所以就报错
    // terminate called without an active exception

    cout << "main::: 最后打印的语句" << endl;

    return 0;
}


/*

output:

main:: i == 0
i == 0
main:: i == 1
main:: i == 2
main:: i == 3
i == 1
main:: i == 4
main::: 最后打印的语句

*/