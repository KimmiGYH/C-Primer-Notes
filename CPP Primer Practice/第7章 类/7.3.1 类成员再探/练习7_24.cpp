/* 练习7.24：给你的Screen类添加三个构造函数：
一个默认构造函数；
另一个构造函数接受宽和高的值，然后将宽和高的值以及一个字符 contents 初始化成给定数量的空白；
第三个构造函数接受该字符作为初始化之后屏幕的内容。

【出题思路】同一个类可以包含多个构造函数，构造函数的定义可以再类的内部也可以在类的外部。*/

class Screen
{
private:
    unsigned height = 0, width = 0;
    unsigned cursor = 0;
    string contents;
public:
    Screen() = default;     // 默认构造函数
    Screen(unsigned ht, unsigned wd) : height(ht), width(wd), contents(ht * wd, ' ') { }
    Screen(unsigned ht, unsigned wd, char c)
        : height(ht), width(wd), contents(ht * wd, c) { }
};