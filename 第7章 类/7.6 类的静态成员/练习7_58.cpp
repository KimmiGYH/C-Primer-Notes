/* 练习7.58：下面的静态数据成员的声明和定义有错误吗？请解释原因。*/

// example.h
class Example {
public:
    static double rate = 6.5;
    static const int vecSize = 20;
    static vector<double> vec(vecSize);
};

// example.C
#include "example.h"
double Example::rate;
vector<double> Example::vec;


/*【出题思路】本题旨在考察静态成员的用法。

【解答】本题的程序存在以下几处错误：
在类的内部，rate 和 vec 的初始化是错误的，因为除了静态常量成员之外，其他静态成员不能再类的内部初始化。

另外，example.c 文件的两条语句也是错误的，因为在这里我们必须给出静态成员的初始值。*/

// example.h
class Example {
public:
    double rate;
    static const int vecSize = 20;
    vector<double> vec(vecSize);
};

// example.C
#include "example.h"
double Example::rate = 6.5;
vector<double> Example::vec(vecSize);

