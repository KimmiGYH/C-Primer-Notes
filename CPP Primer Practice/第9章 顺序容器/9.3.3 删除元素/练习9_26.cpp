/* 练习9.26：使用下面代码定义的 ia，将 ia 拷贝到一个 vector 和一个 list 中。使用单迭代器版本的 erase 从 list 中删除奇数元素，从 vector 中删除偶数元素。 
int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };   */

/*【解答】
当从 vector 中删除元素时，会导致删除点之后位置的迭代器、引用和指针失效。
而 erase 返回的迭代器指向删除元素之后的位置。因此，将 erase 返回的迭器赋予 iiv，使其正确向前推进。且尾后位置每个循环步中都用 end 重新获得，保证其有效。

对于 list 删除操作并不会令迭代器失效，但上述方法仍然是适用的． */

#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main()
{
    int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
    vector<int> iv;
    list<int> il;

    iv.assign(ia, ia + 11);         // 将数据拷贝到 vector
    il.assign(ia, ia + 11);         // 将数据拷贝到 list

    vector<int>::iterator iiv = iv.begin();
    while (iiv != iv.end())
        if (!(*iiv & 1))            // 偶数
            iiv = iv.erase(iiv);    // 删除偶数，返回下一位置迭代器
        else iiv++;                 // 推进到下一位置
    
    list<int>::iterator iil = il.begin();
    while (iil != il.end())
        if (*iil & 1)               // 奇数
            iil = il.erase(iil);    // 删除奇数，返回下一位置迭代器
        else iil++;                 // 推进到下一位置
    
    for (iiv = iv.begin(); iiv != iv.end(); iiv++)
        cout << *iiv << " ";
    cout << endl;

    for (iil = il.begin(); iil != il.end(); iil++)
        cout << *iil << " ";
    cout << endl;

    return 0;
}

/*Output:
1 1 3 5 13 21 55 89 
0 2 8 
*/
