/* 练习9.15：编写程序，判定两个 vector<int> 是否相等。

【解答】标准库容器支持关系运算符，比较两个 vector 是否相等使用 == 运算符即可。
当两个vector包含相同个数的元素，且对位元素都相等时，判定两个 vector 相等，否则不等。

两个 vector 的 capacity 不会影响相等性判定，因此，当下面程序中 ivec1 在添加、删除元素导致扩容后，仍然与 ivec 相等。*/


#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> ivec = {1, 2, 3, 4, 5, 6, 7};
    vector<int> ivec1 = {1, 2, 3, 4, 5, 6, 7};
    vector<int> ivec2 = {1, 2, 3, 4, 5};
    vector<int> ivec3 = {1, 2, 3, 4, 5, 6, 8};
    vector<int> ivec4 = {1, 2, 3, 4, 5, 7, 6};

    cout << (ivec == ivec1) << endl;    // 1
    cout << (ivec == ivec2) << endl;    // 0
    cout << (ivec == ivec3) << endl;    // 0
    cout << (ivec == ivec4) << endl;    // 0

    ivec1.push_back(8);
    ivec1.pop_back();
    cout << ivec1.capacity() << " " << ivec1.size() << endl; // 14 7
    cout << (ivec == ivec1) << endl;    // 1

    return 0;
}

/* Output:
1
0
0
0
14 7
1
*/