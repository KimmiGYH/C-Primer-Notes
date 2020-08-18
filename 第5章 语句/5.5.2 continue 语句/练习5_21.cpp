/*
练习5.21：修改5.5.1节练习题的程序，使其找到的重复单词必须以大写字母开头。

练习5.20：编写一段程序从标准输入中读取 string 对象的序列
直到连续出现两个相同的单词或者所有单词都读完为止。
使用 while 循环次读取一个单词，当一个单词连续出现两次时使用 break 语句终止循环。
输出连续重复出现的单词，或者输出一个消息说明没有任何单词是连续重复出现的
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string currString, preString;
    bool bl = true;
    cout << "Please enter a group of strings: " << endl;
    while (cin >> currString)
    {
        // 找到的重复单词必须以大写字母开头
        if (!isupper(currString[0]))
            continue;
        if (currString == preString)
        {
            bl = false;
            cout << "The adjacent same string is: " << currString << endl;
            break;
        }
        preString = currString;
    }
    if (bl)
        cout << "There are no adjacent same strings." << endl;
    return 0;
}