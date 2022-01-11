/* 练习 2.38：说明由`decltype`指定类型和由`auto`指定类型有何区别。
请举出一个例子，decltype 指定的类型与 auto 指定的类型一样；
再举一个例子，decltype 指定的类型与 auto 指定的类型不一样。*/

// 一个用以说明的示例如下所示：
#include <iostream>
#include <typeinfo>

int main()
{
    int a = 3;
    auto c1 = a;
    decltype(a) c2 = a;
    decltype((a)) c3 = a;

    const int d = 5;
    auto f1 = d;
    decltype(d) f2 = d;

    std::cout << typeid(c1).name() << std::endl;
    std::cout << typeid(c2).name() << std::endl;
    std::cout << typeid(c3).name() << std::endl;
    std::cout << typeid(f1).name() << std::endl;
    std::cout << typeid(f2).name() << std::endl;

    c1++;
    c2++;
    c3++;
    f1++;
    // f2++;   // 错误：f2 是整型常量，不能执行自增操作
    std::cout << a << " " << c1 << " " << c2 << " " << c3 << " " << f1 << " " << f2 << std::endl;
    return 0;
}

/*Output:
i
i
i
i
i
4 4 4 4 6 5
*/