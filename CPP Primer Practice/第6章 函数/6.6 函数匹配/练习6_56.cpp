/* 练习6.56：调用上述 vector 对象汇总的每个元素并输出其结果。*/

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

void Compute(int a, int b, int (*p) (int, int))
{
    cout << p(a, b) << endl;
}

int main()
{
    int i = 5, j = 10;
    decltype(func1) *p1 = func1, *p2 = func2, *p3 = func3, *p4 = func4;
    vector<decltype(func1)* > vF = {p1, p2, p3, p4};

    for (auto p : vF)   // 遍历 vector 中的每个元素，依次调用四则运算函数
    {
        Compute(i, j, p);
    }
    return 0;
}

/* Output:
15
-5
50
0
*/