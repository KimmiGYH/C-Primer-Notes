/* 练习 3.21：请使用迭代器重做 3.3.3节的第一个练习。*/

/* 练习3.16：编写一段程序，把练习3.13 中 vector 对象的容器和具体内容输出出来。
检验你之前的回答是否正确，如果不低，回过头重新学习 3.3.1节 P87 直到弄明白错在何处为止。*/

// (a) vector<int> v1;
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<int> v1;
    vector<int> v2(10);
    vector<int> v3(10, 42);
    vector<int> v4{10};
    vector<int> v5{10, 42};
    vector<string> v6{10};
    vector<string> v7{10, "hi"};

    cout << "The number of elements for v1: " << v1.size() << endl;
    if (v1.cbegin() != v1.cend())   // 当 vector 含有元素时逐个输出
    {
        cout << "The elements in v1 are: " << endl;
        for (auto it = v1.cbegin(); it != v1.cend(); it++)
            cout << *it << " ";
        cout << endl;
    }

    cout << "The number of elements for v2: " << v2.size() << endl;
    if (v2.cbegin() != v2.cend())
    {
        cout << "The elements in v2 are: " << endl;
        for (auto it = v2.cbegin(); it != v2.cend(); it++)
            cout << *it << " ";
        cout << endl;
    }

    cout << "The number of elements for v3: " << v3.size() << endl;
    if (v3.cbegin() != v3.cend())
    {
        cout << "The elements in v3 are:  " << endl;
        for (auto it = v3.cbegin(); it != v3.cend(); it++)
            cout << *it << " ";
        cout << endl;
    }

    cout << "The number of elements for v4: " << v4.size() << endl;
    if (v4.cbegin() != v4.cend())
    {
        cout << "The elements in v4 are: " << endl;
        for (auto it = v4.cbegin(); it != v4.cend(); it++)
            cout << *it << " ";
        cout << endl;
    }

    cout << "The number of elements for v5: " << v5.size() << endl;
    if (v5.cbegin() != v5.cend())
    {
        cout << "The elements in v5 are: " << endl;
        for (auto it = v5.cbegin(); it != v5.cend(); it++)
            cout << *it << " ";
        cout << endl;
    }

    cout << "The number of elements for v6: " << v6.size() << endl;
    if (v6.cbegin() != v6.cend())
    {
        cout << "The elements in v6 are: " << endl;
        for (auto it = v6.cbegin(); it != v6.cend(); it++)
            cout << *it << " ";
        cout << endl;
    }

    cout << "The number of elements for v7: " << v7.size() << endl;
    if (v7.cbegin() != v7.cend())
    {
        cout << "The elements in v7 are: " << endl;
        for (auto it = v7.cbegin(); it != v7.cend(); it++)
            cout << *it << " ";
        cout << endl;
    }

    return 0;

}
/* Output:
The number of elements for v1: 0 


The number of elements for v2: 10
The elements in v2 are: 
0 0 0 0 0 0 0 0 0 0 


The number of elements for v3: 10
The elements in v3 are:  
42 42 42 42 42 42 42 42 42 42 


The number of elements for v4: 1
The elements in v4 are: 
10 


The number of elements for v5: 2
The elements in v5 are: 
10 42


The number of elements for v6: 10
The elements in v6 are:


The number of elements for v7: 10
The elements in v7 are:
hi hi hi hi hi hi hi hi hi hi
*/