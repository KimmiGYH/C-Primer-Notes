/* 练习7.32：定义你自己的 Screen 和 Window_mgr，其中 clear 是 Window_mgr 的成员，是 Screen 的友元。

【出题思路】类可以把其他类定义成友元，也可以把其他类的成员函数定义成友元。
当把成员函数定义成友元时，要特别注意程序的组织结构。

1. 我们必须首先定义 Window_mgr 类，其中声明 clear 函数，但是不能定义它；
2. 接下来定义 Screen 类，并且在其中指明 clear 函数；
3. 最后定义 clear 函数。*/

#include <iostream>
#include <string>
using namespace std;

class Window_mgr        // 1. 我们必须首先定义 Window_mgr 类，其中声明 clear 函数，但是不能定义它；
{
public:
    void clear();
};

class Screen            // 2. 接下来定义 Screen 类，并且在其中指明 clear 函数；
{
friend void Window_mgr::clear();
private:
    unsigned height = 0, width = 0;
    unsigned cursor = 0;
    string contents;
public:
    Screen() = default;
    Screen(unsigned ht, unsigned wd, char c)
        : height(ht), width(wd), contents(ht * wd, c) { }
};

void Window_mgr::clear()    // 3. 最后定义 clear 函数。
{
    Screen myScreen(10, 20, 'X');
    cout << "Before clear, the contenst are: " << endl;
    cout << myScreen.contents << endl;
    myScreen.contents = "";
    cout << "After clear, the contenst are: " << endl;
    cout << myScreen.contents << endl;
}

int main()
{
    Window_mgr w;
    w.clear();
    return 0;
}

/*Output:
Before clear, the contenst are:                                                                                                               XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
After clear, the contenst are:

*/