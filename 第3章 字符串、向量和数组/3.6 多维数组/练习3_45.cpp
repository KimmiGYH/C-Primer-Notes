/* 练习3.45：再一次改写程序，这次使用 auto 关键字。*/

/* 练习3.44：改写上一个练习中的程序，使用类型别名来代替循环控制变量的类型。 */

/* 练习3.43：编写 3 个不同版本的程序，令其均能输出 ia  的元素。
版本1 使用范围for语句管理迭代过程；
版本2 和 版本3 都是用普通的 for 语句，
其中版本2 要求用下标运算符，版本3 要求用指针。
此外，在所有3个版本的程序中都要直接写出数据类型，而不能使用类型别名、auto 关键字或 decltype关键字。*/

#include <iostream>

using namespace std;

int main()
{
    int ia[3][4] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    cout << "利用范围for语句输出多维数组的内容： " << endl;
    // for (int (&row)[4] : ia)
    // for (int_array &row : ia)
    for (auto &row : ia)
    {
        for (auto &col : row)
            cout << col << " ";
        cout << endl;
    }

    cout << "利用普通for语句和下标运算符输出多维数组的内容： " << endl;
    for (auto i = 0; i != 3; i++)
    {
        for (auto j = 0; j != 4; j++)
            cout << ia[i][j] << " ";
        cout << endl;
    }

    cout << "利用普通for语句和指针输出多维数组的内容： " << endl;
    // for (int (*p)[4] = ia; p != ia + 3; p++)
    for (auto p = ia; p != ia + 3; p++)
    {
        for (auto q = *p; q != *p + 4; q++)
            cout << *q << " ";
        cout << endl;
    }
    return 0;
}
