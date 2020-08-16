/* 练习 3.31：编写一段程序，定义一个含有 10 个 int 的数组，令每个元素的值就是其下标值。*/

#include <iostream>
using namespace std;

int main()
{
    const int sz = 10;  // 常量 sz 作为数组的维度
    int arr[sz];
    // 通过for循环为数组元素赋值
    for (int i = 0; i < sz; i++)
        arr[i] = i;
    // 通过范围for循环输出数组的全部元素
    for (int val : arr)
        cout << val << " ";
    cout << endl;

    return 0;
}