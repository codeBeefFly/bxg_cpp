#include <iostream>
//#include <synchapi.h>
#include <Windows.h>
#include <thread>
#include <queue>
#include <condition_variable>
#include <future>

using namespace std;

/*
 * async ����������
 *
 *  async�����ã�
 *      ����Ժ���һ���ָ��ӵ��߼�������������Ĺ��ܣ�
 *      ���ҵ���ִ�н���֮�󣬻����õ�����ֵ
 *      �ֲ��������������̵߳��������У���ô����ʹ��async������ʵ�֡�
 *
 *
 */

int add(int a, int b) {
    cout << "�������߳�id = " << this_thread::get_id() << endl;
    for (int i = 0; i < 10; ++i) {
        cout << "add������ӡ�ˣ�" << i << endl;
        Sleep(1000);
    }
    return a + b;
}



int main() {

    //������
    cout << (1 | 2) << endl;
    cout << "main���߳�id = " << this_thread::get_id() << endl;

    /*
     * enum class launch{
        async = 1,
        deferred = 2
      }
     * Ĭ�ϵ����������ǣ�  launch::async|launch::deferred   1 | 2
     * Ĭ������������3 �� �����߳�����ִ�У� Ȼ�����̻߳���������
     *
     * launch::async �� �Ὺ�����߳�
     * launch::deferred �� ���Ὺ�����̣߳��������߳����еĺ��������ӳ�ִ��
     *      �ӳٵ�ʲôʱ���أ��ӳٵ��� get�����ĵ��á�
     */
      //future<int> f = async(launch::async|launch::deferred, add , 3,4 );
    //future<int> f = async(launch::async, add, 3, 4);
    future<int> f = async(launch::deferred, add , 3,4 );

    for (int i = 0; i < 10; ++i) {
        cout << "main::������ӡ��--->��" << i << endl;
        Sleep(500);
    }
    cout << "async֮��~~ " << endl;
    cout << "async֮��~~ " << endl;
    cout << "async֮��~~ " << endl;
    cout << "async֮��~~ " << endl;

    // ʹ�� launch::deferred ģʽ�󣬲������⿪�����̣߳�ֻ�����̣߳�
    //����������ð󶨵ĺ����������߳���
    //����֮ǰ�����߳�����
    cout << "�����" << f.get() << endl;   


    return 0;
}

/*

output:     launch::async | launch::deferred

3
main���߳�id = 33040
main::������ӡ��--->��0
�������߳�id = 30624
add������ӡ�ˣ�0
main::������ӡ��--->��1
add������ӡ�ˣ�1
main::������ӡ��--->��2
main::������ӡ��--->��3
add������ӡ�ˣ�2
main::������ӡ��--->��4
main::������ӡ��--->��5
add������ӡ�ˣ�3
main::������ӡ��--->��6
main::������ӡ��--->��7
add������ӡ�ˣ�4
main::������ӡ��--->��8
main::������ӡ��--->��9
add������ӡ�ˣ�5
async֮��~~
async֮��~~
async֮��~~
async֮��~~
add������ӡ�ˣ�6
add������ӡ�ˣ�7
add������ӡ�ˣ�8
add������ӡ�ˣ�9
�����7

D:\W_workPlace\bxg_cpp\day12\build\Debug\day12_concurrency_13_async_simple_2.exe (process 24480) exited with code 0.
Press any key to close this window . . .



*/

/*

output:     launch::async

3
main���߳�id = 22696
main::������ӡ��--->��0
�������߳�id = 11340
add������ӡ�ˣ�0
main::������ӡ��--->��1
add������ӡ�ˣ�1
main::������ӡ��--->��2
main::������ӡ��--->��3
add������ӡ�ˣ�2
main::������ӡ��--->��4
main::������ӡ��--->��5
add������ӡ�ˣ�3
main::������ӡ��--->��6
main::������ӡ��--->��7
add������ӡ�ˣ�4
main::������ӡ��--->��8
main::������ӡ��--->��9
add������ӡ�ˣ�5
async֮��~~
async֮��~~
async֮��~~
async֮��~~
add������ӡ�ˣ�6
add������ӡ�ˣ�7
add������ӡ�ˣ�8
add������ӡ�ˣ�9
�����7

D:\W_workPlace\bxg_cpp\day12\build\Debug\day12_concurrency_13_async_simple_2.exe (process 12612) exited with code 0.
Press any key to close this window . . .



*/

/*

output:         launch::deferred

3
main���߳�id = 30104
main::������ӡ��--->��0
main::������ӡ��--->��1
main::������ӡ��--->��2
main::������ӡ��--->��3
main::������ӡ��--->��4
main::������ӡ��--->��5
main::������ӡ��--->��6
main::������ӡ��--->��7
main::������ӡ��--->��8
main::������ӡ��--->��9
async֮��~~
async֮��~~
async֮��~~
async֮��~~
�������߳�id = 30104
add������ӡ�ˣ�0
add������ӡ�ˣ�1
add������ӡ�ˣ�2
add������ӡ�ˣ�3
add������ӡ�ˣ�4
add������ӡ�ˣ�5
add������ӡ�ˣ�6
add������ӡ�ˣ�7
add������ӡ�ˣ�8
add������ӡ�ˣ�9
�����7

D:\W_workPlace\bxg_cpp\day12\build\Debug\day12_concurrency_13_async_simple_2.exe (process 25248) exited with code 0.
Press any key to close this window . . .


*/
