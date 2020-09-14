/*

需求：

简单的
线程
线程+bind



知识点：





*/





#include <iostream>
#include <thread>
#include <functional>
//#include <synchapi.h>
#include <Windows.h>    // Sleep 使用这个函数 

using namespace std;
/*
 * 线程的简单使用
 */

void printI() {
    for (int i = 0; i < 10; ++i) {
        cout << "i = " << i << endl;
        // usleep(微秒 ) 1毫秒  = 1000微秒

        Sleep(1000);
    }
}

void printI02(int total) {
    for (int i = 0; i < total; ++i) {
        cout << "i = " << i << endl;
        // usleep(微秒 ) 1毫秒  = 1000微秒
        Sleep(1000);
    }
}


int main() {
    cout << "====" << endl;
    cout << "====" << endl;
    cout << "====" << endl;
    cout << "====" << endl;

    thread t1;

    //创建一个线程  t
    thread t(printI);   //让线程t运行printI 函数。
    t.join();           //join 的意思是让主线程等待子线程执行结束后，在进行下一步，意思是让主线程挂起。


    thread t2(bind(printI02, 5)); //让线程t运行printI 函数。
    t2.join();

    return 0;
}


/*

output

====
====
====
====
i = 0
i = 1
i = 2
i = 3
i = 4
i = 5
i = 6
i = 7
i = 8
i = 9
i = 0
i = 1
i = 2
i = 3
i = 4

*/