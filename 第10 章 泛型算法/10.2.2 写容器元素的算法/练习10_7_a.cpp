/*练习10.7：下面程序是否有错误？如果有，请改正。*/

/* (a)
vector<int> vec;
list<int> lst;
int i;
while (cin >> i)
    lst.push_back(i);
copy(lst.cbegin(), lst.cend(), vec.begin());


(a）是错误的。
因为泛型算法的一个基本特点是：算法总是通过迭代器操作容器，因此不能直接向／从容器添加、删除元素，无法改变容器大小。
因此，对于copy算法，要求目标序列至少要包含与源序列一样多的元素。
而此程序中，vec进行缺省初始化，它是空的，copy无法进行。
如需改变容器大小，需要使用一类特殊的称为插入器的迭代器。
我们可以将第三个参数改为 back_inserter(vec)，通过它，copy算法即可将lst中元素的拷贝插入到vec的末尾。*/

#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
    ifstream in(argv[1]);
    if (!in) {
        cout << "Fails to open the file!" << endl;
        exit(1);
    }

    list<int> lst;
    vector<int> vec;
    int val;
    while (in >> val)
        lst.push_back(val);
    
    copy(lst.begin(), lst.end(), back_inserter(vec));

    cout << equal(lst.begin(), lst.end(), vec.begin()) << endl;
    for (auto iter = vec.begin(); iter != vec.end(); iter++)
        cout << *iter << " ";
    cout << endl;

    return 0;
}
