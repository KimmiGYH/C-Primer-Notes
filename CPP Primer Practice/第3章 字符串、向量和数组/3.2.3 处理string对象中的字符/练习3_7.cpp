/* 练习3.7：就上一题完成的程序而言，如果将循环控制变量的类型设为 char 将发生什么？
先估计一下结果，然后实际编程进行验证。 */

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cout << "Please enter a string, including space: " << endl;
    getline(cin, s);    // 读取整行，遇回车符结束
    for (char &c : s)   // 依次处理字符串中的每一个字符
    {
        c = 'X';
    }
    cout << s << endl;
    return 0;
}
/*就本题而言，将循环控制变量的类型设为 `char` 不会对程序运行结果造成影响，
因为我们使用 auto 自动推断字符串 s 的元素类型，结果同样是 char。*/