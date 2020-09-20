#include <iostream>
//#include <synchapi.h>
#include <Windows.h>

using namespace std;

//�۲��ߣ�������۲��ߵ�״̬�����˸ı䣬��ô�����Ҫ�յ�֪ͨ��
class observer {

public:
    //���ڽ���֪ͨ��
    void update() {
        cout << "�۲����յ�֪ͨ��" << endl;
    }
};

//���۲���
//���۲��ߵ�״̬�����˸ı䣬��ô����Ҫȥ֪ͨ�۲���
class subject {
    //���۲���Ҫ֪�����ڱ�˭�۲��ߡ�
    observer ob;
public:
    //ͨ�����������ã�����subject��˭�۲�
    void setObserver(observer ob) {
        this->ob = ob;
    }

    //�Ժ�״̬���ˣ��͵����������������֪ͨ�۲��ߡ�
    void notify() {
        cout << "���۲��ߴﵽ��״̬��Ҫȥ֪ͨ�۲�����" << endl;
        ob.update();
    }
};

int main() {
    observer ob;
    subject sj;

    //����Ŀ�����˭�۲죬�Ա�һ�������״̬����֪ͨ�۲���
    sj.setObserver(ob);


    //ģ��һ�£������� ��ӡ����5���͵���Ŀ�����ﵽ��ĳ��״̬��
    for (int i = 0; i < 20; ++i) {
        cout << " i ===" << i << endl;
        if (i == 5) {
            //˭�۲����������˭�����յ�֪ͨ��
            sj.notify();
        }

        Sleep(1000);
    }


    return 0;
}

/*

output:


...getInstance �����߳�:: 32544
...���������˯��1000ms...
...getInstance �����߳�:: 28652
...���ض���ǰ˯��3000ms...
...���ض���ǰ˯��3000ms...
...async_bank instance address: 00000182000E5190
...getInstance �����߳�:: 28652
...���ض���ǰ˯��3000ms...
...concu_bank instance address: 00000182000E5190
...getInstance �����߳�:: 32544
...���ض���ǰ˯��3000ms...
...async_bank instance address: 00000182000E5190
...getInstance �����߳�:: 28652
...���ض���ǰ˯��3000ms...
...concu_bank instance address: 00000182000E5190
...getInstance �����߳�:: 32544
...���ض���ǰ˯��3000ms...
...async_bank instance address: 00000182000E5190
...getInstance �����߳�:: 28652
...���ض���ǰ˯��3000ms...
...concu_bank instance address: 00000182000E5190
...getInstance �����߳�:: 32544
...���ض���ǰ˯��3000ms...
...async_bank instance address: 00000182000E5190
...getInstance �����߳�:: 28652
...���ض���ǰ˯��3000ms...
...concu_bank instance address: 00000182000E5190
...getInstance �����߳�:: 32544
...���ض���ǰ˯��3000ms...
...async_bank instance address: 00000182000E5190
...getInstance �����߳�:: 28652
...���ض���ǰ˯��3000ms...
...concu_bank instance address: 00000182000E5190
...getInstance �����߳�:: 32544
...���ض���ǰ˯��3000ms...
...async_bank instance address: 00000182000E5190
...getInstance �����߳�:: 28652
...���ض���ǰ˯��3000ms...
...concu_bank instance address: 00000182000E5190
...getInstance �����߳�:: 32544
...���ض���ǰ˯��3000ms...
...async_bank instance address: 00000182000E5190
...getInstance �����߳�:: 28652
...���ض���ǰ˯��3000ms...
...concu_bank instance address: 00000182000E5190
...getInstance �����߳�:: 32544
...���ض���ǰ˯��3000ms...
...async_bank instance address: 00000182000E5190
...getInstance �����߳�:: 28652
...���ض���ǰ˯��3000ms...
...concu_bank instance address: 00000182000E5190
...getInstance �����߳�:: 32544
...���ض���ǰ˯��3000ms...
...async_bank instance address: 00000182000E5190
...getInstance �����߳�:: 28652
...���ض���ǰ˯��3000ms...
...concu_bank instance address: 00000182000E5190
...getInstance �����߳�:: 32544
...���ض���ǰ˯��3000ms...
...async_bank instance address: 00000182000E5190
...getInstance �����߳�:: 28652
...���ض���ǰ˯��3000ms...
...concu_bank instance address: 00000182000E5190
...getInstance �����߳�:: 32544
...���ض���ǰ˯��3000ms...
...async_bank instance address: 00000182000E5190
...getInstance �����߳�:: 28652
...���ض���ǰ˯��3000ms...
...concu_bank instance address: 00000182000E5190
...getInstance �����߳�:: 32544
...���ض���ǰ˯��3000ms...

D:\W_workPlace\bxg_cpp\day12\build\Debug\day12_designMode_singleton_lazy_problem_2_self.exe (process 32992) exited with code -1073741510.
Press any key to close this window . . .


*/