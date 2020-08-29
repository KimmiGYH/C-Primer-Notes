/* 练习9.19：重写上题的程序，用 `list` 替代 `deque`。列出程序要做出哪些改变。

【解答】对 `list` 来说，在任何位置添加新元素都有很好的性能，遍历操作也能高效完成，因此程序与上一题并无太大差异。*/

#include <iostream>
#include <list>

using namespace std;

int main()
{
    list<string> sl;    // string 的 list

    string word;
    while (cin >> word) // 读取字符串，直至遇到文件结束符
        sl.push_back(word);
    
    // 用 cbegin() 获取 list 首元素迭代器，遍历 list 中的所有元素
    for (auto si = sl.cbegin(); si != sl.cend(); si++)
        cout << *si << endl;
    
    return 0;
}

