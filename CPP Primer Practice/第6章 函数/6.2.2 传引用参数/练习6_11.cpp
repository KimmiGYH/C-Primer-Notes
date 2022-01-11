/* 练习6.11：编写并验证你自己的 reset 函数，使其作用域引用类型的参数。*/

#include <iostream>
using namespace std;

void reset(int &i)
{
    i = 0;
}

int main()
{
    int num = 10;
    cout << "Before reset: num = " << num << endl;
    reset(num);
    cout << "After reset: num = " << num << endl;
    return 0;
}
/*
Before reset: num = 10
After reset: num = 0
*/