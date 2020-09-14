#include <iostream>
#include <thread>
#include <functional>
//#include <synchapi.h>
#include <Windows.h>

using namespace std;
/*
 *  线程的 ID  和 线程休眠
 */

void print() {

    //namespace this_thread {
    //_NODISCARD thread::id get_id() noexcept;
    
    cout << "print函数打印的线程ID：" << this_thread::get_id() << endl;
    for (int i = 0; i < 10; ++i) {
        cout << "i ==" << i << endl;
        //Sleep(1000);  windows系统专用的
        // uSleep();  linux 系统用的。

        //不区分操作系统的。
        this_thread::sleep_for(chrono::seconds(1));

        //this_thread::sleep_for(chrono::hours(1));
    }
}

int main() {

    cout << "main函数运行的线程： " << this_thread::get_id() << endl;

    thread t(print);
    cout << "线程t的ID： " << t.get_id() << endl;

    t.join();

    cout << "main:: 最后打印的语句" << endl;
    return 0;
}


/*

output:

main函数运行的线程： 30068
线程t的ID： 2768
print函数打印的线程ID：2768
i ==0
i ==1
i ==2
i ==3
i ==4
i ==5
i ==6
i ==7
i ==8
i ==9
main:: 最后打印的语句

*/