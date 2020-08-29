/* 练习9.21：如果我们将第 308 页中使用 `insert` 返回值将元素添加到 `list` 中的循环程序改写为将元素插入到 `vector` 中，分析循环将如何工作。

【解法】将新 string 插入到 vector 首元素之前的位置，成为新的首元素，并使 iter 始终指向 vector 首。这样 string 在 vector 排列的顺序将与它们的输入顺序恰好相反。整个循环执行的过程和最后的结果都与 list 版本没有什么区别。

但要注意，在 list 首元素之前插入新元素性能很好，但是对于 vector，这样的操作需要移动所有现有元素，导致性能很差。*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<string> svec;        // string 的 vector
    
    string word;
    auto iter = svec.begin();   // 获取 vector 首位置迭代器
    while (cin >> word)         // 读取字符串，直至遇到文件结束符
        iter = svec.insert(iter, word);
    
    // 用 cbegin() 获取 vector 首元素迭代器，遍历 vector 中所有元素
    for (auto iter = svec.cbegin(); iter != svec.cend(); iter++)
        cout << *iter << endl;
    
    return 0;
}