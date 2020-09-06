/*练习10.7：下面程序是否有错误？如果有，请改正。*/

/* (b)
vector<int> vec;
vec.reserve(10);
fill_n(vec.begin(), 10, 0);


(b）这段程序仍然是错误的。
粗看起来，reserve 为 vec 分配了至少能容纳 10 个 int 的内存空间，调用 fill_n 时，vec已有足够空间。
但泛型算法对于容器 的要求并不是有足够的空间，而是足够的元素。
此时vec仍然为空，没有任何元素。
而算法又不具备向容器添加元素的能力，因此 fill_n 仍然失败。
这里，我们还是需要 back_inserter 来让 fill_n 有能力向 vec 添加元素。
其实，只有 0 有能力做到这一点，空间大小并不是问题，容器都能根据需要自动扩容。 */


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
    vector<int> vec;
    vec.reserve(10);
    fill_n(back_inserter(vec), 10, 0);

    for (auto iter = vec.begin(); iter != vec.end(); iter++)
        cout << *iter << " ";
    cout << endl;

    return 0;
}
