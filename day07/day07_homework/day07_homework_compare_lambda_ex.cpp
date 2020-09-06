#include <iostream>
#include <string>

using namespace std;

/*
 * ����Ҫ�Ƚ�����ѧ���Ĵ�С�����԰������ֶ�������Ƚϡ�Ҳ���԰�������Ƚϡ�Ҳ���԰�����߱Ƚϡ�
����һ��ȫ�ֺ���compare , ������������������һ�Ͳ����� ΪҪ�Ƚϵ�ѧ�����󣬲�����Ϊlambda���ʽ
�������һ������Ƚ����䣬�������һ�������ʾ������ȣ������ӡ���˵Ĵ�С��
 */

class stu {
public:
    string name;
    int age;

    stu() : stu("unknown", 0) {}
    stu(string name, int age) :name(name), age(age) {

    }
    //����������������һ���û��ѡ�
    //ʵ��������������������������һ�����أ� �����������Ӧ������ostream���͡�
    //�����Ԫ������ȫ�ֺ�����
    //friend void operator<<( ostream& os , stu &s);
};

int compare(stu s1, stu s2, int(*cp)(stu, stu)) {
    return cp(s1, s2);
}

int main() {
    stu s1("zhangsan", 28);
    stu s2("zhangsan", 28);

    //������SDK ������API�������á�����Ҫ�����淵���ַ����� 1  0  -1
    /*int(*cp)(stu , stu)  =  [](stu s1 , stu s2){
        //������Ƚ��ˡ�
        if(s1.name == s2.name){
            //��ȣ���Ҫ�Ƚ����䡣
            if(s1.age == s2.age){
                return 0 ;
            }else if(s1.age > s2.age){
                return 1;
            }else if(s1. age < s2.age){
                return -1;
            }
        }else if(s1.name > s2. name){
            return 1;
        }else if(s1 .name < s2.name){
            return -1;
        }
        return 1;
    };
    int result = compare(s1, s2 , cp);*/


    //��ϣ�����д�����Ĵ��롣
    //1. ����Ч�ʸ��ߡ������������д���������
    //2. ���ִ���д���ˣ���ô���˼��Ҳ�������ˡ�
    //    �Ժ��������ĳһ������������һ�������õ��Ǻ���ָ�롣
    //       ��ô���Դ󵨲²⣬ ʵ������������ı�����ǻ�������Ǵ��ݽ�ȥ���������ָ�롣
    int result = compare(s1, s2, [](stu s1, stu s2) {
        //������Ƚ��ˡ�
        if (s1.name == s2.name) {
            //��ȣ���Ҫ�Ƚ����䡣
            if (s1.age == s2.age) {
                return 0;
            }
            else if (s1.age > s2.age) {
                return 1;
            }
            else if (s1.age < s2.age) {
                return -1;
            }
        }
        else if (s1.name > s2.name) {
            return 1;
        }
        else if (s1.name < s2.name) {
            return -1;
        }
        return 1;
        });
    cout << "result = " << result << endl;

    return 0;
}
