/*练习6.4：编写一个与用户交互的函数，要求用户输入一个数字，计算生成该数字的阶乘。
在 main 函数中调用该函数。*/

#include <iostream>
using namespace std;

int fact(int val)
{
    int ret = 1;
    while (val > 1)
        ret *= val--;
    return ret;
}
// OR
int fact(int val)
{
    if (val < 0)
        return -1;
    int ret = 1;
    // 从 1 连乘到 val
    for (int i = 1; i != val + 1; ++i)
        ret *= i;
    return ret;
}

int main()
{
    int num;
    cout << "Please enter a number: " << endl;
    cin >> num;
    cout << fact(num) << endl;;
    return 0;
}