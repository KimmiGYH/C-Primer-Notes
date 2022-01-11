/* 练习9.14：编写程序，将一个`list`中的`char*`指针（指向C风格字符串）元素赋值给一个`vector`中的`string`。

【出题思路】
容器有多种赋值操作，本题帮助读者理解不同赋值方式的差异。

【解答】
由于 list<char*> 与 vector<string> 是不同类型的容器，因此无法采用赋值运算符 `=` 来进行元素赋值。
但 char* 可以转换为 string，因此可以采用范围赋值方式来实现本题要求。*/

#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main()
{
    list<char *> slist = {"hello", "world", "!"};
    vector<string> svec;

    // 容器类型不同，不能直接赋值
    // svec = slist;

    /*元素类型相容，可以采用范围赋值*/
    svec.assign(slist.begin(), slist.end());

    cout << svec.capacity() << " " << svec.size() << " " << svec[0] << " " << svec[svec.size()-1] << endl;

    return 0;
}

// Output: 3 3 hello !