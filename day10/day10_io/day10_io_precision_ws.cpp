/*

����

��ϰ
1. ���ø���������
2. ������β��� �հ׷�


Ĭ������£���ȡ���̵���������ʱ���Զ����Կհ׷����ո�� ���Ʊ�������з����س����� �� 
��������Կ���ʹ�� `noskipws` ��ֹ���Կհ׷��� ʹ�� `skipws` ��ԭ���Լ��ɡ�

*/


#include <iostream>
#include <iomanip>

using namespace std;

/*
 *  �����������
 *
 */
int main() {


    //1. ���������
    double pi = 3.14159265312123124532;

    //cout .precision(80);
    cout << setprecision(15) << "pi -= " << pi << endl;

    //2. ��ֹ���Կհ׷�
    char c;
    //cin >> noskipws;
    //while (cin >> c) {
    //    if (c == 'q') break;
    //    cout << "c =" << c << endl;
    //}
    
    cin >> skipws;
    while (cin >> c) {
        if (c == 'q') break;
        cout << "c =" << c << endl;
    }

    return 0;
}


/*

output

pi -= 3.14159265312123
a bd hello, !123
c =a
c =
c =b
c =d
c =
c =h
c =e
c =l
c =l
c =o
c =,
c =
c =!
c =1
c =2
c =3
c =

q

q


pi -= 3.14159265312123
a bd h191,23
c =a
c =b
c =d
c =h
c =1
c =9
c =1
c =,
c =2
c =3


*/