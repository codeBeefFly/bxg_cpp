/*

需求：

智能指针 

唯一指针   unique_ptr

不能拷贝，只能移动

*/


#include <iostream>
#include <memory>


int main() {

	std::cout << "..in smart_pointer_0...\n";

	// 普通指针区
	int a = 3;
	int* p = &a;


	// 创建一个唯一指针对象，指向数据类型 int
	// 使用无参构造，无法管理指针，class unique_ptr 唯一指针是一个类 
	std::unique_ptr<int> u_ptr;

	// 调用有参构造，管理指针 
	//std::unique_ptr<int> u_ptr2(p);	// 这样写会报错
	//std::unique_ptr<int> u_ptr2(p, );	  // 如何改
	//std::unique_ptr<int> u_ptr2(std::move(p));	// 这样写也不行
	//std::unique_ptr<int> u_ptr2 = std::move(p);	// 这样也不对  完全没搞懂

	// 调用有参构造，管理堆内存指针
	std::unique_ptr<int> u_ptr3(new int(3));



	return 0;
}