/*

������Ҫ��ʽ��һ���ַ�������ͨ������֪����Ҫ���Ļ�������
Ϊ�˱��ճ�����������Ļ������Է�ֹ��������С����ַ����޷�ȫ���洢��
��ʱ���ǿ��Կ���ʹ��`ostringstream`�࣬
�����ܹ����������Զ������ڴ棬��������ڴ�Ĺ���Ҳ���൱�ĵ�λ��

*/


#include <iostream>
#include <sstream>

using namespace std;

/*
 *  �ַ����������
 *
 */
int main() {

    string data = "�����й���";
    int a = 3;
    double pi = 3.14;


    ostringstream os;
    os << data << a << " : pi << " << pi << endl;
    string result = os.str();
    cout << "result= " << result << endl;

     string pi2 = "3.1415926";
    //double pi3 =(double) pi2;
     ostringstream  os2;
     os2 << pi2 << endl;
     cout << "result2 = " << os2.str();

     //double pi4 ;
     //os2 >> pi4;


    return 0;
}

/*

result= �����й���3 : pi << 3.14

result2 = 3.1415926

*/