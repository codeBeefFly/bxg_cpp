#include <iostream>
#include <memory>
#include <vector>
using  namespace std;

/*
 * �쳣�Ĳ���
 *
 *      �ܲ�����쳣��ʵ����Ҳ�����ó����ߡ�
 *      ���� ֱ�Ӿ���ֹ��
 */
 /*
 class teacher{
 public:
     int age ;
     teacher(int age) {

     }
 };

 class stu{

     int age =18; //  int age;  //0
     teacher t;

     //�г�ʼ���б�Ļ��� ����ĳ�Ա���������������ѡ�
     stu (int age , teacher t): age(age) , t(t){
     }

     stu (int age , teacher t){
         age = age ;
         t = t ;
     }
     int a = 3 ;
     int b = 4;
     a = b;  //���ǳ�ʼ���𣿲��ǣ���仰�Ǹ�ֵ��

 };
 */


int main() {

    int a;

    try {
        vector<int> vi{ 10,20,30 };
        int result = vi.at(30);
        cout << "result =" << result << endl;
    }
    catch (exception e) {       // ���Լ�������
        cout << "�Ǳ�aԽ����" << endl;
    }
    
    
    
    //try {
    //    int a = 3 / 0;
    //    cout << "result = " << a <<endl;
    //}catch (exception e){
    //    cout << "ץ���쳣��" <<endl;
    //}


    //int a;
    //try {
    //    std::cout << "..in try...\n";
    //    a = 3 / 0;      // ����쳣û�������ף������޷�����
    //}
    //catch (exception e) {
    //    std::cout << "..in catch...\n";
    //}


    cout << "����ӡ����䣡" << endl;
    return 0;
}
