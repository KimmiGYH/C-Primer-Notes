/* 练习7.33：如果我们给 Screen 添加一个如下所示的 size 成员将发生什么情况？
如果出现了问题，请尝试修改它。*/

pos Screen::size() const
{
    return height * width;
}

/* 【出题思路】如果添加入题目所示的 size 函数将会出现编译错误。
因为该函数的返回类型 pos 本身定义在 Screen 类的内部，所以在类的外部无法直接使用 pos。
要想使用 pos，需要在它的前面加上作用域 Screen::。
修改后的程序是：*/
Screen::pos Screen::size() const
{
    return height * width;
}