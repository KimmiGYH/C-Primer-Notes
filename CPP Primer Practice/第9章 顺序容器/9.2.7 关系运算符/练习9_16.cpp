/* 练习9.16：重写上一题的程序，比较一个 list<int> 中的元素和一个 vector<int> 中的元素。*/

/* 练习9.15：编写程序，判定两个 vector<int> 是否相等。

【解答】标准库容器支持关系运算符，比较两个 vector 是否相等使用 == 运算符即可。
当两个vector包含相同个数的元素，且对位元素都相等时，判定两个 vector 相等，否则不等。
两个 vector 的 capacity 不会影响相等性判定，因此，当下面程序中 ivec1 在添加、删除元素导致扩容后，仍然与 ivec 相等。*/

#include <iostream>
#include <vector>
#include <list>

using namespace std;

bool l_v_equal(vector<int> &ivec, list<int> &ilist) {
    // 比较 list 和 vector 元素个数
    if (ilist.size() != ivec.size())
        return false;
    
    auto lb = ilist.cbegin();       // list 首元素
    auto le = ilist.cend();         // list 尾后位置
    auto vb = ivec.cbegin();        // vector 首元素
    for ( ; lb != le; lb++, vb++)
        if (*lb != *vb)             // 元素不等，容器不等
            return false;
    return true;                    // 容器相等
}

int main()
{
    vector<int> ivec = {1, 2, 3, 4, 5, 6, 7};
    list<int> ilist = {1, 2, 3, 4, 5, 6, 7};
    list<int> ilist1 = {1, 2, 3, 4, 5};
    list<int> ilist2 = {1, 2, 3, 4, 5, 6, 8};
    list<int> ilist3 = {1, 2, 3, 4, 5, 7, 6};

    cout << l_v_equal(ivec, ilist) << endl;
    cout << l_v_equal(ivec, ilist1) << endl;
    cout << l_v_equal(ivec, ilist2) << endl;
    cout << l_v_equal(ivec, ilist3) << endl;

    return 0;
}