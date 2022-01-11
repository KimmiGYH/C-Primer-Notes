/* 练习 3.32：将上一题刚刚创建的数组拷贝给另外一个数组。
利用vector重写程序，实现类似的功能。*/

// 实现数组拷贝的程序如下所示：
#include <iostream>

using namespace std;

int main()
{
    const int sz = 10;  // 常量 sz 作为数组的维度
    int a[sz], b[sz];
    // 通过for循环为数组元素赋值
    for (int i = 0; i < sz; i++)
        a[i] = i;
    for (int j = 0; j < sz; j++)
        b[j] = a[j];
    // 通过范围 for 循环输出数组的全部元素
    for (auto val : b)    
        cout << val << " ";
    cout << endl;
    
    return 0;
}


// 实现 vector 拷贝的程序如下所示：
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    const int sz = 10;  // 常量 sz 作为 vector 的容量
    vector<int> vInt, vInt2;
    // 通过for循环为 vector对象的元素赋值
    for (int i = 0; i < sz; i++)
        vInt.push_back(i);
    for (int j = 0; j < sz; j++)
        vInt2.push_back(vInt[j]);
    // 通过范围 for 循环输出 vector对象的全部元素
    for (auto val : vInt2)
        cout << val << " ";
    cout << endl;

    return 0;
}