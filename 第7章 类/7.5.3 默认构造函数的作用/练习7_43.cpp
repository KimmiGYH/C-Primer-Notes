/*练习7.43：假定有一个名为 NoDefault 的类，它有一个接受 int 的构造函数，但是没有默认构造函数。
定义类C，C 有一个 NoDefault 类型的成员，定义 C 的默认构造函数。

【出题思路】因为 NoDefault 仅有的一个构造函数并不是默认构造函数，所以在类C中，不能使用无参数的默认构造函数，那样的话，类 C 的 NoDefault 成员无法正确初始化。*/

#include <iostream>
#include <string>
using namespace std;

// 该类型没有显式定义默认的构造函数，编译器也不会为它合成一个
class NoDefault
{
public:
    NoDefault(int i)
    {
        val = i;
    }
    int val;
};

class C
{
public:
    NoDefault nd;
    // 必须显式调用 Nodefault 的带参构造函数初始化 nd
    C(int i = 0) : nd(i) { }
};

int main()
{
    C c;    // 使用了类型 C 的默认构造函数
    cout << c.nd.val << endl;
    return 0;
}