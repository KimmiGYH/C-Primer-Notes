/* 练习4.22：本节的示例程序将成绩划分为 high pass、pass 和 fail 三种，
扩展该程序使其进一步将 60分到 75分之间的成绩设定为 low pass。
要求程序包含两个版本：
一个版本只使用条件运算符；另一个版本使用 1 个或多个 if 语句。
哪个版本的程序更容易理解呢？为什么？
*/

// 使用条件运算符实现的程序如下所示：
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string finalgrade;
    int grade;
    cout << "Please enter the score you want to check: " << endl;
    // 确保输入的成绩合法
    while (cin >> grade && grade >= 0 && grade <= 100)
    {
        // 使用三层嵌套的条件表达式
        finalgrade = (grade > 90) ? "high pass"
                            : (grade > 75) ? "pass"
                            : (grade > 60) ? "low pass" : "fail";
        cout << "The band of the score falls in: " << finalgrade << endl;
        cout << "Please enter the score you want to check: " << endl;
    }
    return 0;
}


// 使用 if 语句实现的程序如下所示：

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string finalgrade;
    int grade;
    cout << "Please enter the score you want to check: " << endl;
    // 确保输入的成绩合法
    while (cin >> grade && grade >= 0 && grade <= 100)
    {
        // 使用 if 语句实现
        if (grade > 90)
            finalgrade = "high pass";
        else if (grade > 75)
            finalgrade = "pass";
        else if (grade > 60)
            finalgrade = "low pass";
        else
            finalgrade = "fail";
        cout << "The band if score you enter fall in as follows: " << finalgrade << endl;
        cout << "Please enter the score you want to check: " << endl;
    }
    return 0;
}