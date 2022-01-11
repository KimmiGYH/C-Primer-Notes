/* 练习9.13：如何从一个 `list<int>` 初始化一个 `vector<double>`？
从一个 `vector<int>` 又该如何创建？编写代码验证你的答案。

【出题思路】更深入地理解容器拷贝初始化和范围初始化两种方式的差异。

【解答】
由于 `list<int>` 与 `vector<double>` 是不同的容器类型，因此无法采用容器拷贝初始化方式。
但前者的元素类型是 `int`，与后者的元素类型 `double` 是相容的，因此可以采用范围初始化方式来构造一个 `vector<double>`，令它的元素值与 `list<int>`完全相同。*/

#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main()
{
    list<int> ilist = {1, 2, 3, 4, 5, 6, 7};
    vector<int> ivec = {7, 6, 5, 4, 3, 2, 1};

    // 容器类型不同，不能使用拷贝初始化
    // vector<double> ivec(ilist);

    /* 元素类型相容，因此可采用范围初始化 */
    vector<double> dvec(ilist.begin(), ilist.end());

    // 元素类型不同，不能使用拷贝初始化
    // vector<double> dvec1(ivec);

    /* 元素类型相容，因此可采用范围初始化 */
    vector<double> dvec1(ivec.begin(), ivec.end());

    cout << dvec.capacity() << " " << dvec.size() << " " << dvec[0] << " " << dvec[dvec.size() - 1] << endl;

    cout << dvec1.capacity() << " " << dvec1.size() << " " << dvec1[0] << " " << dvec1[dvec1.size() - 1] << endl;

    return 0;
}

/*Output:
7 7 1 7
7 7 7 1
*/