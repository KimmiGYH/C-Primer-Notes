/* 练习3.6：编写一段程序，使用范围for语句将字符串内的所有字符用 X 代替。 */
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cout << "Please enter a string, including space: " << endl;
    getline(cin, s);    // 读取整行，遇回车符结束
    for (auto &c : s)   // 依次处理字符串中的每一个字符
    {
        c = 'X';
    }
    cout << s << endl;
    return 0;
}
/*有两点值得注意：
1. 利用`auto`关键字推断字符串中每一个元素的类型；、
2. `c`必须定义为引用类型，否则无法修改字符串内容。*/