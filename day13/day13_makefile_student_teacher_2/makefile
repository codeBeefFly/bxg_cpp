demo	: stu.o test.o
	g++ stu.o test.o -o demo
stu.o	: stu.cpp
test.o	: test.cpp

clean	: 
	del /Q /S stu.o test.o
.PHONY	: clean