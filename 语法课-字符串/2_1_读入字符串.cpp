#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    char a1[] = {'C', '+', '+'}; //列表初始化，没有空字符，不是字符串
    char a2[] = {'C', '+', '+', '\0'}; //列表初始化，含有显式的空字符，是字符串
    char a3[] = "C++"; //自动添加表示字符串结尾的空字符
    //char a4[6] = "Daniel"; //错误，没有空间可存放空字符！
    cout << a1 << endl;
    printf("%s\n", a3);

    return 0;
}