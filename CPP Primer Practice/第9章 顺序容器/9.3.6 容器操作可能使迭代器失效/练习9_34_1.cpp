/*下面的程序可展示程序执行效果。其中，我们在循环体最后加入了一个循环， 打印容器中所有元素，即可观察程序执行效果。这是种简单的程序调试方法。
cin>>tmp 是为了让程序暂停，程序员有时间观察输出，需要继续执行程序时，随意输入一个字符串即可。*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> vi = {1,2,3,4,5,6,7,8,9};
    auto iter = vi.begin();
    string tmp;
    while (iter != vi.end()) {
        if (*iter % 2)
            iter = vi.insert(iter, *iter);
        for (auto begin = vi.begin(); begin != vi.end(); begin++)
            cout << *begin << " ";
        cout << endl;
        cin >> tmp;
        // cin>>tmp 是为了让程序暂停，程序员有时间观察输出
        // 需要继续执行程序时，随意输入一个字符串即可
    }
    ++iter;
    
    return 0;
}

/* Output:
1 1 2 3 4 5 6 7 8 9 
y
1 1 1 2 3 4 5 6 7 8 9 
y
1 1 1 1 2 3 4 5 6 7 8 9 
y
1 1 1 1 1 2 3 4 5 6 7 8 9 
*/