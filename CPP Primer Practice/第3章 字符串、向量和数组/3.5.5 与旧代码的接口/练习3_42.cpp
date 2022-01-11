/* 练习 3.42：编写一段程序，将含有整数元素的 vector 对象拷贝给一个整型数组。*/

/*【出题思路】
C++ 允许使用数组直接初始化 vector 对象，但是不允许使用 vector 对象初始化数组。
如果想用 vector 对象初始化数组，则必须把 vector 对象的每个元素逐一赋值给数组。
*/

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    const int sz = 10;  // 常量 sz 作为 vector 对象的容量
    vector<int> vInt;
    srand( (unsigned) time (NULL) ); // 生成随机数种子

    cout << "The vector content is: " << endl;
    // 利用for循环遍历 vector 对象的每个元素
    for (int i = 0; i != sz; i++)
    {
        vInt.push_back(rand() % 100);   // 生成一个 100 以内的随机数
        cout << vInt[i] << " ";
    }
    cout << endl;

    auto it = vInt.cbegin(); // 迭代器 it
    int a[vInt.size()];

    cout << "The array content is: " << endl;
    // 利用范围for循环遍历数组的每个元素
    for (auto &val : a)
    {
        val = *it;
        cout << val << " ";
        it++;
    }
    cout << endl;
    return 0;
}

/* Output:
The vector content is: 
30 75 11 69 82 51 46 40 23 81 
The array content is: 
30 75 11 69 82 51 46 40 23 81
*/