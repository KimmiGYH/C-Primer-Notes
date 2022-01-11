/*练习 5.6：改写上一题的程序，使用条件运算符代替 if-else 语句。*/

#include <iostream>

using namespace std;

int main()
{
    int grade;
    cout << "Please enter your grade: ";
    cin >> grade;
    if (grade < 0 || grade > 100)
    {
        cout << "The grade is illegal." << endl;
        return -1;
    }
    if (grade == 100)
    {
        cout << "The score level is: " << "A++" << endl;
    }
    if (grade < 60)
    {
        cout << "Tje score level is: " << "F" << endl;
        return -1;
    }
    int iU = grade / 10;    // 成绩的十位数
    int iT = grade % 10;    // 成绩的个位数
    string score, level, lettergrade;
    // 根据成绩的十位数字确定 score
    score = (iU == 9) ? "A"
                   : (iU == 8) ? "B"
                            : (iU == 7) ? "C" : "D";
    // 根据成绩的个位数字确定 level
    level = (iT < 3) ? "-"
                : (iT > 7) ? "+" : "";
    // 累加求得等级成绩
    lettergrade = score + level;
    cout << "The score level is: " << lettergrade << endl;

    return 0;
}