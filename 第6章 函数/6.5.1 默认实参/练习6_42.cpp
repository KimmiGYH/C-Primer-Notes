/* 练习6.42：给 make_plural 函数的第二个形参赋予默认实参 's'，
利用新版本的函数输出单词 success 和 failure 的但书和复数形式。

// P201 make_plural 函数
string make_plural(size_t ctr, const string &word, const string &ending)
{
    return (ctr > 1) ? word + ending : word;
}

【出题思路】
对于英语单词来说，大多数名词的复数是在单词末尾加's'得到的，
也有一部分名词在单数转变为复数时需要在末尾加'es'。
我们可以把's'作为默认实参，大多数情况下不必考虑这个参数，
只有在遇到末尾是'es'的单词时才专门处理。
*/

#include <iostream>
#include <string>
using namespace std;

// 最后一个形参赋予了默认实参

string make_plural(size_t ctr, const string &word, const string &ending = "s")
{
    return (ctr > 1) ? word + ending : word;
}

int main()
{
    cout << "The singular form of success is: " << make_plural(1, "success", "es") << endl;
    cout << "The plural form of success is: " << make_plural(2, "success", "es") << endl;
    // 一般情况下调用该函数只需要两个实参
    cout << "The singular form of success is: " << make_plural(1, "failure") << endl;
    cout << "The plural form of success is: " << make_plural(2, "failure") << endl;
    return 0;
}