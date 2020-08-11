/* 练习 3.22：修改之前那个输出 text 第一段的程序，首先把 text 的第一段全都改成大写形式，然后再输出它。*/

/* 思路：需要将第一段（vector对象第一个空串元素之前的所有元素）改写成大写字母的形式再输出。
因为需要更改 vector 对象的内容，所以使用的迭代器应该是 begin 和 end，而非 cbegin 和 cend。*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<string> text;
    string s;
    // 利用 getline 读取一句话，直接回车产生一个空串，表示段落结束
    while (getline(cin, s))
        text.push_back(s);
    // 利用迭代器遍历全部字符串，遇空串停止循环
    for (auto it = text.begin(); it != text.end() && !it -> empty(); it++)
    {
        // 利用迭代器遍历当前字符串
        for (auto it2 = it -> begin(); it2 != it -> end(); it2++)
            *it2 = toupper(*it2);   // 利用toupper改写成大写形式
        cout << *it << endl;        // 输出当前字符串
    }
    return 0;
}