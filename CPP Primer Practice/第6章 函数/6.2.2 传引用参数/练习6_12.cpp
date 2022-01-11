/* 练习6.12：改写6.2.1节中练习6.10(第 188 页)的程序，使用引用而非指针交换两个整数的值。
你觉得哪种方法更易于使用呢？为什么？*/

#include <iostream>
using namespace std;

void mySWAP(int &i, int &j)
{
    int tmp = i;
    i = j;
    j = tmp;
}

int main()
{
    int a = 5, b = 10;
    cout << "Before the exchange: a = " << a << ", b = " << b << endl;
    mySWAP(a, b);
    cout << "After the exchange: a = " << a << ", b = " << b << endl;
    return 0;
}

/*
Before the exchange: a = 5, b = 10
After the exchange: a = 10, b = 5
*/