/* 练习4.15：下面的赋值是非法的，为什么？应该如何修改？*/

double dval; int ival; int *pi;
dval = ival = pi = 0;

/*因为参与赋值的几个变量类型不同。
dval是双精度浮点数，ival是整数，pi是整型指针。

自右向左分析赋值操作的含义：
pi = 0 表示 pi 是空指针，
接下来 ival = pi 试图把整形指针的值赋给整数，这是不符合语法规范的操作，无法编译通过。
稍作调整，就可以把上述程序改为合法：*/

double dval; int ival; int *pi;
dval = ival = 0;
pi = 0