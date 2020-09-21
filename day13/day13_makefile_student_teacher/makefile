demo	: test.o stu.o			# 两个.o 文件 编译成 一个可执行文件，这两个.o是真正存在的文件，不是 3，4行的名称，所以文件名必须准确
	g++ test.o stu.o -o demo	
test.o	:	test.cpp			# 源文件 -> .o 文件
stu.o 	: 	stu.cpp	stu.h		# 源文件 -> .o 文件，下面如果不手动写 g++ -c stu.cpp，就会自动添加 g++ -c -o stu.o stu.cpp，所以可以不写

# 一个源文件会编译出来一个.o文件
# 再把所有的.o文件一块整合起来才会形成一个完整的程序。
# 打包生成完整程序的 g++ 命令是不能省略的
# 已编译的 .o 文件不再编译