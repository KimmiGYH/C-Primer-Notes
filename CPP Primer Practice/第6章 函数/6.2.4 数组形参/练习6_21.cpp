/*练习6.21：编写一个函数，令其接受两个参数：一个是 int 型的数，另一个是 int 指针。
函数比较 int 的值和指针所指的值，返回较大的那个。
在该函数中指针的类型应该是什么？

【出题思路】第一个参数的实际值毫无疑问是 int 类型，第二个参数是 int 指针，
实际上可能表示的是一个 int 数组，该指针指向了数组的首元素。
*/

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

int myCompare(const int val, const int *p)
{
    return (val > *p) ? val : *p;
}

int main()
{
    srand( (unsigned) time (NULL));
    int a[10];
    for (auto &i : a)
        i = rand() % 100;
    cout << "Please enter a number: ";
    int j;
    cin >> j;
    cout << "The bigger one between the number and the inital element in the array is: "
         << myCompare(j, a) << endl;
    cout << "All the elements in the array are: " << endl;
    for (auto i : a)
        cout << i << " ";
    cout << endl;
    return 0;
}
