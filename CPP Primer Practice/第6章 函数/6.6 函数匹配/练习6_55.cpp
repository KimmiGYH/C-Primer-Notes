/* 练习6.55：编写 4 个函数，分别对两个 int 值执行加、减、乘、除运算；
在上一题创建的 vector 对象中保存指向这些值的指针。

【出题思路】考查函数指针的声明和使用。*/


#include <iostream>
#include <vector>
using namespace std;

int func1(int a, int b)
{
    return a + b;   // 加法
}

int func2(int a, int b)
{
    return a - b;   // 减法
}

int func3(int a, int b)
{
    return a * b;   // 乘法
}

int func4(int a, int b)
{
    return a / b;   // 除法
}

int main()
{
    decltype(func1) *p1 = func1, *p2 = func2, *p3 = func3, *p4 = func4;
    vector<decltype(func1)* > vF = {p1, p2, p3, p4};
    return 0;
}