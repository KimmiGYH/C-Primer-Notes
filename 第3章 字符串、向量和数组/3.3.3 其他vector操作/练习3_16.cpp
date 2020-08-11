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
    if (v1.size() > 0)
    {
        cout << "The elements in v1 are: " << endl;
        for (auto e : v1)
            cout << e << " ";
        cout << endl;
    }

    cout << "The number of elements for v2: " << v2.size() << endl;
    if (v2.size() > 0)  // 当 vector 含有元素时逐个输出
    {
        cout << "The elements in v2 are: " << endl;
        for (auto e : v2)
            cout << e << " ";
        cout << endl;
    }

    cout << "The number of elements for v3: " << v3.size() << endl;
    if (v3.size() > 0)
    {
        cout << "The elements in v3 are:  " << endl;
        for (auto e : v3)
            cout << e << " ";
        cout << endl;
    }

    cout << "The number of elements for v4: " << v4.size() << endl;
    if (v4.size() > 0)
    {
        cout << "The elements in v4 are: " << endl;
        for (auto e : v4)
            cout << e << " ";
        cout << endl;
    }

    cout << "The number of elements for v5: " << v5.size() << endl;
    if (v5.size() > 0)
    {
        cout << "The elements in v5 are: " << endl;
        for (auto e : v5)
            cout << e << " ";
        cout << endl;
    }

    cout << "The number of elements for v6: " << v6.size() << endl;
    if (v6.size() > 0)
    {
        cout << "The elements in v6 are: " << endl;
        for (auto e : v6)
            cout << e << " ";
        cout << endl;
    }

    cout << "The number of elements for v7: " << v7.size() << endl;
    if (v7.size() > 0)
    {
        cout << "The elements in v7 are: " << endl;
        for (auto e : v7)
            cout << e << " ";
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