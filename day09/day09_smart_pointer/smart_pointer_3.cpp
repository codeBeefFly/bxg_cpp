/*

����

shared_ptr


`shared_ptr` : ����������ָ��ָ��ͬһ��λ�� �� ��Ե��� `shared_ptr`��
����Ϊ�˱�֤�����ͷŻ��գ������˼�������ÿһ�ε�ָ����� + 1 �� 
ÿһ�ε�reset�ᵼ�¼��� -1 ��ֱ������Ϊ0 ���ڴ�Ż����ձ��ͷŵ��� 
����ʹ��`use_cout` ���鿴Ŀǰ��ָ�����  count

*/


#include <iostream>
#include <memory>

using  namespace std;

/*
 *  ����ָ��
 *      �÷�������Ψһָ��һ������������ʼ����ȡֵ������һ����
 *      ��ͬ�㣺
 *          a. ���Կ�����
 *         b. ����������shared_ptr ����һ��ָ�룬ָ��ͬһ���ط���
 *              û����һ��shared_ptr ��ô���� + 1
 *              ֻ�����ļ���Ϊ0 ���Ż�����ڴ�
 *                  �����ֶ�reset  ��������� -1 ��
 */

class stu {
public:
    string name;
    stu() = default;
    stu(string name) : name(name) {
        cout << "����ѧ�� :" << name << endl;
    }

    ~stu() {
        cout << "���� :" << name << endl;
    }

};

int main() {

    //1. ��������ָ�롣
    stu* s = new stu("����");

    shared_ptr<stu> sp(s);
    //sp.reset(s); ��ʾ��ֵ������ָ�� s
    cout << "����ָ��ļ���1 sp��" << sp.use_count() << endl;

    //2. ���Կ�����  ���Կ����������ƶ���
    shared_ptr<stu> sp1 = sp;
    cout << "����ָ��ļ���2 sp��" << sp.use_count() << endl;

    shared_ptr<stu> sp2 = move(sp);
    cout << "����ָ��ļ���3 sp��" << sp.use_count() << endl; //��仰���صļ�����0����Ϊsp�Ѿ��ƶ�����sp2
    cout << "����ָ��ļ���3 sp2��" << sp2.use_count() << endl;

    //3. ȡֵ
    cout << "ȡֵ1��" << sp2.get()->name << endl;
    cout << "ȡֵ2��" << (*sp2).name << endl;
    cout << "ȡֵ3��" << sp2->name << endl;

    //4. ʲôʱ���ͷ�ָ�롣
    sp1.reset();
    cout << "����ָ��ļ���4 sp2��" << sp2.use_count() << endl;

    sp2.reset();  // �����Ѿ����0  ������������  ��ӡ������䡣
    cout << "����ָ��ļ���5 sp2��" << sp2.use_count() << endl;

    cout << "��������ӡ����䣡����" << endl;

    return 0;
}


/*

output


����ѧ�� :����
����ָ��ļ���1��1
����ָ��ļ���2��2
����ָ��ļ���3��0
����ָ��ļ���3��2
ȡֵ1������
ȡֵ2������
ȡֵ3������
����ָ��ļ���4��1
���� :����
����ָ��ļ���5��0
��������ӡ����䣡����

*/
