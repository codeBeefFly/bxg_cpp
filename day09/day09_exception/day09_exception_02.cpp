/*

throw

try catch �﷨


fun(){
    throw exception("excetpion type x");
}

main(){

    try{
        fun();
    }
    catch(exception e){
        cout << e.what() << "\n";   // e.what() ��ӡ exception �е���ʾ
    }

}


*/


#include <iostream>
#include <memory>
#include <vector>
using  namespace std;

/*
 *�쳣�Ĵ���
 *      �׳��쳣��
 */


int calc_div(int a, int b) {
    if (b == 0) {
        //�׳��쳣��throw ��
        //throw logic_error("��������Ϊ0��");   // ��Щ�쳣��Ҫ���׳������� try catch ����
        throw exception("��������Ϊ0��");         // ���д��̫ţ����
    }
    cout << "�����ڲ����׳��쳣֮��" << endl;
    return a / b;
}
int main() {

    try {
        calc_div(3, 0);
    }
    catch (bad_alloc e) { //�������дlogic_error Ҳ����д exectpion
        cout << e.what() << endl;
    }
    catch (exception e) {
        cout << e.what() << endl;
    }


    cout << "��������ӡ�����" << endl;
    return 0;

}


/*

output

��������Ϊ0��
��������ӡ�����

*/

