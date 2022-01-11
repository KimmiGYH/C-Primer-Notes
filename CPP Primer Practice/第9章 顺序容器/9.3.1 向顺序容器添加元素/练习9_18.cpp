/* 练习9.18：编写程序，从标准输入读取 `string` 序列，存入一个 `deque` 中。编写一个循环，用迭代器打印 `deque` 中的元素。

【解答】对 `deque` 来说，在首尾位置添加新元素性能最佳，在中间位置插入新元素性能会很差。对遍历操作，可高效完成。*/

#include <iostream>
#include <deque>

using namespace std;

int main()
{
    deque<string> sd;   // string 的 deque
    
    string word;
    while (cin >> word) // 读取字符串，直至遇到文件结束符
        sd.push_back(word);
    
    // 用 cbegin() 获取 deque 首元素迭代器，遍历 deque 中所有元素
    for (auto si = sd.cbegin(); si != sd.cend(); si++)
        cout << *si << endl;
    
    return 0;
}

/*【其他解题思路】
由于在 `deque` 的首尾位置添加新元素性能很好，因此可以用 `push_front` 替换 `push_back`，性能不变，但元素在 `deque` 中的顺序将与输入顺序相反。
若需保持相同顺序，应使用 `push_back`。*/