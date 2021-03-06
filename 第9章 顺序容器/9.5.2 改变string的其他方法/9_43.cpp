#include <iostream>
#include <vector>
#include <string>

using namespace std;

void replace_string(string& s, const string& oldVal, const string& newVal)
{
    int len = oldVal.size();
    if (!len) return;   // 要查找的字符串为空
    auto iter = s.begin();
    while (iter <= s.end()-1)
    {
        auto iter1 = iter;
        auto iter2 = oldVal.begin();
        // s 中 iter 开始的子串必须每个字符都与 oldVal 相同
        while (iter2 != oldVal.end() && *iter1 == *iter2) {
            iter1++;
            iter2++;
        }
        if (iter2 == oldVal.end()) {    // oldVal耗尽——字符串相等
            iter = s.erase(iter, iter1);// 删除 s 中与 oldVal 相等的部分
            if (newVal.size()) {        // newVal不为空时
                iter2 = newVal.end();   // 由后至前逐个顺次将newVal中的字符插入到s中
                do {
                    iter2--;
                    iter = s.insert(iter, *iter2);
                } while (iter2 > newVal.begin());
            }
            iter += newVal.size();      // 迭代器移动到新插入内容之后
        } 
        iter++;
    }    
}

int main()
{
    string s = "tho thru tho!";

    replace_string(s, "thru", "through");
    cout << s << endl; // "tho through tho!"

    replace_string(s, "tho", "though");
    cout << s << endl; // "though through though!"

    replace_string(s, "through", "");
    cout << s << endl; // "though  though!"

    return 0;
}