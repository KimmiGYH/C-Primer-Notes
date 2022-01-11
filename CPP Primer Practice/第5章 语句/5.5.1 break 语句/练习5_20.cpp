/* 练习5.20：编写一段程序从标准输入中读取 string 对象的序列
直到连续出现两个相同的单词或者所有单词都读完为止。
使用 while 循环次读取一个单词，当一个单词连续出现两次时使用 break 语句终止循环。
输出连续重复出现的单词，或者输出一个消息说明没有任何单词是连续重复出现的。*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string currString, preString;
    bool bl = true; // bl 为真时表示没有连续出现的字符串
    cout << "Please enter a group of strings: " << endl;
    while (cin >> currString)
    {
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

/* 本题用到了一个起标识作用的布尔值 bl，当 bl 为真时表示没有连续出现的字符串，
一旦我们发现了存在连续出现的字符串，就立即把 bl 的值置为 false。 */