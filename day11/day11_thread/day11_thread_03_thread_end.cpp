#include <iostream>
#include <thread>
#include <functional>
//#include <synchapi.h>
#include <Windows.h>
#include <processthreadsapi.h>

using namespace std;
/*
 *  结束线程
 *      一般来说，一个线程的结束应该是以线程内部的逻辑已经处理完毕作为结束的标准。
 *
 *      1.  线程内部的事情已经做完了，那么线程自动结束。
 *
 *      2. 如果不想等线程自然运行结束。
 *            a. 通过条件判断，然后直接return 函数。
 *
 *            b.
 *
 */

void print() {
    for (int i = 0; i < 10; ++i) {
        if (i == 5) {
            exit(0) ; // 结束进程    
        }
        cout << "i ==" << i << endl;
        this_thread::sleep_for(chrono::seconds(1));
    }

    cout << "print :: END" << endl;
}

int main() {

    thread t(print);

    t.join();

    //创建线程  msvc  visual studio  vc++
    //CreateThread();
    //TerminateThread( );


    cout << "main::END" << endl;


    return 0;
}


/*

output

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
print :: END
main::END


i ==0
i ==1
i ==2
i ==3
i ==4

*/