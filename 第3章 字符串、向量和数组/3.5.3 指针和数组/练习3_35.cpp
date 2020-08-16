/* 练习：编写一段程序，利用指针将数组中的元素置为 0。 */

#include <iostream>

using namespace std;

int main()
{
    const int sz = 10; // 常量 sz 作为数组的维度
    int a[sz], i = 0;

    // 通过 for 循环为数组元素赋值
    for (i = 0; i < 10; i++)
        a[i] = i;
    cout << "The initial content in the array is: " << endl;
    for (auto val : a)
        cout << val << " ";
    cout << endl;

    int *p = begin(a);  // 令 p 指向数组首元素
    while (p != end(a))
    {
        *p = 0;         // 修改 p 所指元素的值
        p++;            // p 向后移动一位
    }
    cout << "The revised array content is: " << endl;

    // 通过范围for循环输出数组的全部元素
    for (auto val : a)
        cout << val << " ";
    cout << endl;

    return 0;
}