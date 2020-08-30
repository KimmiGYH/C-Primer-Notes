/* 练习9.28：编写函数，接受一个 `forward list<string>` 和两个 `string` 共三个参数。
函数应在链表中查找第一个 `string`，并将第二个`string` 插入到紧接着第一个 `string` 之后的位置。
若第一个 `string` 未在链表中，则将第二个 `string` 插入到链表末尾。 */

#include <iostream>
#include <forward_list>

using namespace std;

void test_and_insert(forward_list<string> &sflst, const string &s1, const string &s2)
{
    auto prev = sflst.before_begin();               // 前驱元素
    auto curr = sflst.begin();                      // 当前元素
    bool inserted = false;

    while (curr != sflst.end()) {
        if (*curr == s1) {                          // 找到给定字符串
            curr = sflst.insert_after(curr, s2);    // 插入新字符串，curr 指向它
            inserted = true;
        }
        prev = curr;                                // 前驱迭代器向前推进
        curr++;                                     // 当前迭代器向前推进
    }

    if (!inserted)
        sflst.insert_after(prev, s2);               // 未找到给定字符串，插入尾后
}

int main()
{
    forward_list<string> sflst = {"Hello", "!", "world", "!"};

    test_and_insert(sflst, "Hello", "nihao");
    for (auto curr = sflst.cbegin(); curr != sflst.cend(); curr++)
        cout << *curr << " ";
    cout << endl;   // Hello nihao ! world !

    test_and_insert(sflst, "!", "?");
    for (auto curr = sflst.cbegin(); curr != sflst.cend(); curr++)
        cout << *curr << " ";
    cout << endl;   // Hello ! ? world ! ?

    test_and_insert(sflst, "Bye", "Zaijian");
    for (auto curr = sflst.cbegin(); curr != sflst.cend(); curr++)
        cout << *curr << " ";
    cout << endl;   // Hello ! world ! Zaijian

    return 0;
}