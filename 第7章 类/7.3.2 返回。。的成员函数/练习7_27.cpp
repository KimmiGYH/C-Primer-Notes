/*练习7.27：给你自己的 Screen 类添加 move、set 和 display 函数，通过之心管下面的代码检验你的类是否正确。

Screen my Screen(5, 5, 'X');
myScreen.move(4,0).set('#').display(cout);
cout << "\n";
myScreen.display(cout);
cout << "\n";
*/

class Screen
{
private:
    unsigned height = 0, width = 0;
    unsigned cursor = 0;
    string contents;
public:
    Screen() = default;
    Screen(unsigned ht, unsigned wd) : height(ht), width(wd),
            contents(ht * wd, ' ') { }
    Screen(unsigned ht, unsigned wd, char c) : height(ht), width(wd),
            contents(ht * wd, c) { }
public:
    Screen& move(unsigned r, unsigned c)
    {
        cursor = r * width + c;
        return *this;
    }
    Screen& set(char ch)
    {
        contents[ cursor ] = ch;
        return *this;
    }
    Screen& set(unsigned r, unsigned c, char ch)
    {
        contents[ r * width + c] = ch;
        return *this;
    }
    Screen& display()
    {
        cout << contents;
        return *this;
    }
};
