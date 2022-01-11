/* 练习5.5：写一段自己的程序，使用 if-else 语句实现把数字成绩转换成字母成绩的要求。 */

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
        cout << "The socre level is: " << "A++" << endl;
        return -1;
    }
    if (grade < 60)
    {
        cout << "The score level is: " << "F" << endl;
        return -1;
    }
    int iU = grade / 10;    // 成绩的十位数
    int iT = grade % 10;    // 成绩的个位数
    string score, level, lettergrade;
    // 根据成绩的十位数字确定 score
    if (iU == 9)
        score = "A";
    else if (iU == 8)
        score = "B";
    else if (iU == 7)
        score = "C";
    else
        score = "D";
    // 根据成绩的个位数字确定level
    if (iT < 3)
        level = "-";
    else if (iT > 7)
        level = "+";
    else
        level = "";
    // 累加求得等级成绩
    lettergrade = score + level;
    cout << "The score level is: " << lettergrade << endl;
    
    return 0;
}