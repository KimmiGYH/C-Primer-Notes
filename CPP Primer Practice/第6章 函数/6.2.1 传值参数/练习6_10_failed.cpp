/* 练习6.10：编写一个函数，使用指针形参交换两个整数的值。
在代码中调用该函数并输出交换后的结果，以此验证函数的正确性。*/

#include <iostream>
using namespace std;

void mySWAP(int *p, int *q)
{
    int *tmp = p;   // tmp 是一个指针
    p = q;
    q = tmp;
}

int main()
{
    int a = 5, b = 10;
    int *r = &a, *s = &b;
    cout << "Before the exchange: a = " << a << ", b = " << b << endl;
    mySWAP(r, s);
    cout << "After the exchange: a = " << a << ", b = " << b << endl;
    return 0;
}
/*
Before the exchange: a = 5, b = 10
After the exchange: a = 5, b = 10
*/