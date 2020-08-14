//函数原型
void createPointer(int** p);

/*
如果是一级指针

void createPointer(int *p);

*/

int main() {

    //空指针
    int* p = nullptr;

    //在函数内部对该指针初始化
    createPointer(&p);

    //初始化完毕后，修改指向空间的数据
    *p = 42;

    //释放指针
    delete p;

    return 0;
}

void createPointer(int** p) {
    // 解引用，得到的是一级指针，其实就是得到了外面的 p 那么整段话连起来就是 int *P  = new int();
    *p = new int();     // **p 解引用后 *p 就是 int *p = nullptr;
}


/*
如果是一级指针

void createPointer(int *p){

    // 解引用后，那么只有使用
    p = new int();  // p 中 就是 int *p = nullptr; p 所存储的 nullptr的 地址。

}


*/