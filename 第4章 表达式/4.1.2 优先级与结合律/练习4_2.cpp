/* 练习4.2：根据4.12节中的表，在下述表达式的合理位置添加括号，使得添加括号后运算对象的组合顺序雨天加括号前一致。
(a) *vec.begin()
答： *(vec.begin())

(b) *vec.begin() + 1
答： (*(vec.begin()) + 1)
*/

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    vector<int> vec;
    srand( (unsigned) time (NULL));
    cout << "The system generates a group of elements for the vector: " << endl;
    for (int i = 0; i != 10; i++)
        vec.push_back(rand() % 100);
    cout << "The data generated are: " << endl;
    for (auto c : vec)
        cout << c << " ";
    cout << endl;
    cout << "To check if the brackets added are right: " << endl;
    cout << "The value of *vec.begin() is: " << *vec.begin() << endl;
    cout << "The value of *(vec.begin()) is: " << *(vec.begin()) << endl;
    cout << "The value of (*(vec.begin())) + 1 is: " << (*(vec.begin())) + 1 << endl;
    return 0;
}

/*Output:
The system generates a group of elements for the vector:
The data generated are:
39 89 54 60 79 25 94 13 20 12
To check if the brackets added are right:
The value of *vec.begin() is: 39
The value of *(vec.begin()) is: 39
The value of (*(vec.begin())) + 1 is: 40
*/