/* 练习6.26：编写一个程序，使其接受本节所示的选项：输出传递给 main 函数的实参的内容。*/

#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    for (int i = 0; i != argc; ++i)
    {
        cout << "argc[" << i <<"]: " << argv[i] << endl;
    }
    return 0;
}