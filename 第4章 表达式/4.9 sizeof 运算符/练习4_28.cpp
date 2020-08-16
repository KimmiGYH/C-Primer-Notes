/* 练习4.28：编写一段程序，输出每一种内置类型所占空间的大小。*/

#include <iostream>

using namespace std;

int main()
{
    cout << "Type Name\t" << "Space Taken" << endl;
    cout << "bool\t\t" << sizeof(bool) << endl;
    cout << "char\t\t" << sizeof(char) << endl;
    cout << "wchar_t\t\t" << sizeof(wchar_t) << endl;
    cout << "char16_t\t" << sizeof(char16_t) << endl;
    cout << "char32_t\t" << sizeof(char32_t) << endl;
    cout << "short\t\t" << sizeof(short) << endl;
    cout <<"int\t\t" << sizeof(int) << endl;
    cout << "long\t\t" << sizeof(long) << endl;
    cout << "long long\t" << sizeof(long long) << endl;
    cout << "float\t\t" << sizeof(float) << endl;
    cout << "double\t\t" << sizeof(double) << endl;
    cout << "long double\t" << sizeof(long double) << endl;
    return 0;
}

/* Output:
                所占字节
Type Name       Space Taken
bool            1
char            1
wchar_t         2
char16_t        2
char32_t        4
short           2
int             4
long            4
long long       8
float           4
double          8
long double     12
*/