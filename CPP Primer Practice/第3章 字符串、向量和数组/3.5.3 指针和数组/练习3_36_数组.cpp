/* 练习 3.36：编写一段程序，比较两个数组是否相等。
再写一段程序，比较两个 vector 对象是否相等。

类似于一个彩票游戏，先由程序随机选出 5 个 0~9 的数字，次过程类似于摇奖；
再由用户手动输入 5 个猜测的数字，类似于购买彩票；
分别把两组数字存入数组 a 和 b，然后逐一比对两个数组的元素；
一旦有数字不一致，则告知用户猜测错误，
只有当两个数组的所有元素都相等时，判定数组相等，即用户猜测正确。
*/

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    const int sz = 5;   // 常量 sz 作为数组的维度
    int a[sz], b[sz], i = 0;
    srand( (unsigned) time (NULL) );    // 生成随机数种子
    
    // 通过 for 循环为数组元素赋值
    for (int i = 0; i < sz; i++)
    {
        // 每次循环生成一个 10 以内的随机数并添加到 a 中
        a[i] = rand() % 10;
    }

    cout << "Please enter 5 digits (0~9), with repetition: " << endl;
    int uVal;
    // 通过 for 循环为数组元素赋值
    for (i = 0; i < sz; i++)
        if (cin >> uVal)
            b[i] = uVal;
    
    cout << "The system generated data are: " << endl;
    for (auto val : a)
        cout << val << " ";
    cout << endl;
    
    cout << "Your guessed data are: " << endl;
    for (auto val : b)
        cout << val << " ";
    cout << endl;

    // 比较两个数组
    int *p = begin(a), *q = begin(b);   // 令 p 和 q 分别指向数组 a 和 b 的首元素
    while(p != end(a) && q != end(b))
    {
        if (*p != *q)
        {
            cout << "Your guess is wrong. The two arrays are not equal." <<endl;
            return -1;
        }
        p++;    // p 向后移动一位
        q++;    // q 向后移动一位
    }
    cout << "Congratulations, you have guessed them all right!" << endl;

    return 0;
}