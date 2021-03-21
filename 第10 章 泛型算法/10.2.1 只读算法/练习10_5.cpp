/*练习10.5：在本节对名册(roster)调用 equal 的例子中，如果两个名册中保存的都是 C 风格字符串而不是 string，会发生什么？

【解答】equal使用 == 运算符比较两个序列中的元素。
string类重载了 ==，可比较两个字符串是否长度相等且其中元素对位相等。
而 C 风格字符串本质是 char* 类型， 用 == 比较两个 char* 对象，只是检查两个指针值是否相等，即地址是否相等，而不会比较其中字符是否相同。
所以，只有当两个序列中的指针都指向相同的地址时，equal 才会返回 true。
否则，即使字符串内容完全相同，也会返回 false。 

如下面的程序，q 中的每个字符串是 p 中字符串的拷贝，虽然内容相同，但是不同对象指向不同地址，因此 equal 判定它们不等。
[注]：strdup可以直接把要复制的内容复制给没有初始化的指针，因为它会自动分配空间给目的指针。
strdup 不是标准的c函数。strdup() 在内部调用了 malloc() 为变量分配内存，不需要使用返回的字符串时，需要用 free() 释放相应的内存空间，否则会造成内存泄漏。

而 r 中每个指针都是 p 中指针的拷贝，指向相同的地址，因此 equal 判定它们相等。*/

#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int main(int argc, char *argv[])
{
    char *p[] = { "Hello", "World", "!" };
    char *q[] = { strdup(p[0]), strdup(p[1]), strdup(p[2]) };
    char *r[] = { p[0], p[1], p[2] };
    cout << equal(begin(p), end(p), q) << endl; //输出 0
    cout << equal(begin(p), end(p), r) << endl; //输出 1

    return 0;
}