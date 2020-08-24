/*练习7.23：编写你自己的 Screen 类。

【思路】对于 Screen 类来说，必不可少的数据成员有：
屏幕的宽度和高度、屏幕点内容以及光标的当前位置。
因此仅包含数据成员的 Screen类是：*/

class Screen
{
private:
    unsigned height = 0, width = 0;
    unsigned cursor = 0;
    string contents;
}