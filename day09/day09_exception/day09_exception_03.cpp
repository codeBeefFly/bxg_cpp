
#include <iostream>
#include <memory>
#include <vector>
using  namespace std;

/*
 *�쳣
 *      noexcept �����ڱ�ʾ��������쳣��
 *          һ������ڿ���������ƶ����졣
 */

int calc_div(int a, int b) noexcept {   // ��ʾ������������쳣�����Ժ������쳣�Ͳ�������

    if (b == 1) {
        throw logic_error("��������Ϊ1");    // ����û������
    }
    return a / b;
}

int main() {
    try {
        calc_div(3, 1);
    }
    catch (logic_error l) { //�߼�������쳣
        cout << "�����߼��쳣" << endl;
    }
    catch (bad_alloc b) { //����ռ������쳣���ڴ治���ա�
        cout << "��������ռ�ʧ�ܵ��쳣" << endl;
    }
    catch (exception e) { //���е��쳣�����Բ���
        cout << "�����쳣��2" << endl;
        cout << e.what() << endl;
    }
    cout << "��������ӡ�����" << endl;
    return 0;
}
