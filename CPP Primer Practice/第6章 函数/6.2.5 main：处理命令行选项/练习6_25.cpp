/* 练习6.25：编写一个 main 函数，令其接受两个实参。把实参的内容连接成一个 string 对象并输出出来。*/

#include <iostream>
using namespace std;

// 第一个参数 argc 指明数组中字符串的数量
// 第二个参数 argv 是存有字符串的数组
int main(int argc, char **argv)
{
    string str;
    for (int i = 0; i != argc; ++i)
        str += argv[i];
    cout << str << endl;
    return 0;
}