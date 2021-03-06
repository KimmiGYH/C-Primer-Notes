#include <iostream>
#include <vector>
#include <string>

using namespace std;

void replace_string(string& s, const string& oldVal, const string& newVal)
{
    int p = 0;
    while ((p = s.find(oldVal, p)) != string::npos) // string::npos返回字符串尾指示器
    {
        s.replace(p, oldVal.size(), newVal);    // 将找到的子串替换为 newVal 的内容
        p += newVal.size();                     // 下标调整到新插入内容之后
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