//����ԭ��
void createPointer(int** p);

/*
�����һ��ָ��

void createPointer(int *p);

*/

int main() {

    //��ָ��
    int* p = nullptr;

    //�ں����ڲ��Ը�ָ���ʼ��
    createPointer(&p);

    //��ʼ����Ϻ��޸�ָ��ռ������
    *p = 42;

    //�ͷ�ָ��
    delete p;

    return 0;
}

void createPointer(int** p) {
    // �����ã��õ�����һ��ָ�룬��ʵ���ǵõ�������� p ��ô���λ����������� int *P  = new int();
    *p = new int();     // **p �����ú� *p ���� int *p = nullptr;
}


/*
�����һ��ָ��

void createPointer(int *p){

    // �����ú���ôֻ��ʹ��
    p = new int();  // p �� ���� int *p = nullptr; p ���洢�� nullptr�� ��ַ��

}


*/