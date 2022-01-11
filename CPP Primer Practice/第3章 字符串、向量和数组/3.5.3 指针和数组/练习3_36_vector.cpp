/* 练习 3.36：编写一段程序，比较两个数组是否相等。
再写一段程序，比较两个 vector 对象是否相等。

对比两个 vector 对象是否相等的程序如下所示，其中使用迭代器遍历 vector 对象的元素。
*/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>

using namespace std;

int main()
{
    const int sz = 5;
    int i = 0;
    vector<int> a, b;
    srand( (unsigned) time (NULL));

    // 通过 for 循环为 vector 元素赋值
    for (int i = 0; i < sz; i++)
        a.push_back(rand() % 10);
    
    cout << "Please enter 5 digits (0~9), with repetition: " << endl;
    int uVal;
    // 通过 for 循环为 vector 元素赋值
    for (i = 0; i < sz; i++)
        if (cin >> uVal)
            b.push_back(uVal);
    
    cout << "The system generated data are: " << endl;
    for (auto val : a)
        cout << val << " ";
    cout << endl;

    cout << "Your guessed data are: " << endl;
    for (auto val : b)
        cout << val << " ";
    cout << endl;

    // 令 it1, it2 分别指向 vector 对象 a 和 b 的首元素
    auto it1 = a.cbegin(), it2 = b.cbegin();
    while (it1 != a.cend() && it2 != b.cend())
    {
        if (*it1 != *it2)
        {
            cout << "You have guessed them wrong. The two vectors are not equal." << endl;
            return -1;
        }
        it1++;  // p 向后移动一位
        it2++;  // q 向后移动一位
    }
    cout << "Congratulations, you have guessed them all right!" << endl;

    return 0;
}