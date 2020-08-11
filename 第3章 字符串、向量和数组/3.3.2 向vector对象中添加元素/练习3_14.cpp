/* 练习3.14：编写一段程序，用 cin 读入一组整数并把它们存入一个 vector 对象。*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> vInt;       // 元素类型为 int 的 vector 对象
    int i;                  // 记录用户的输入值
    char cont = 'y';        // 与用户交互，决定是否继续输入
    while (cin >> i)
    {
        vInt.push_back(i);  // 向 vector 对象中添加元素
        cout << "Do you wanna continue? (y or n)? " << endl;
        cin >> cont;
        if (cont != 'y' && cont != 'Y')
            break;
    }
    for (auto mem : vInt)   // 使用范围for循环语句遍历 vInt 中的每个元素
        cout << mem << " ";
    cout << endl;
    return 0;
}
/* Output:
1
Do you wanna continue? (y or n)?
y
2
Do you wanna continue? (y or n)?
y
3
Do you wanna continue? (y or n)?
Y
4
Do you wanna continue? (y or n)?
1 2 3 4
*/