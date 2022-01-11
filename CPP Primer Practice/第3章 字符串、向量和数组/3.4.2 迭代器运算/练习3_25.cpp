/* 例子：
假设有一组成绩的集合，其中成绩的取值是从 0 到 100。以 10 分为一个分数段，要求统计各个分数段各有多少个成绩。
显然，从 0 到 100 总共有 101 种可能的成绩取值，这些成绩分布在 11 个分数段上：每 10 个分数构成一个分数段，这样的分数段有 10 个，额外还有一个分数段表示满分 100 分。
这样第一个分数段将统计成绩在 0 到 9 之间的数量；
第二个分数段将统计成绩在 10 到 19 之间的数量，以此类推。
最后一个分数段统计满分 100 分的数量。
按照上面的描述，如果输入的成绩如下：
42 65 95 100 39 67 95 76 88 76 83 92 76 93
则输出的结果应该是：
0 0 0 1 1 0 2 3 2 4 1

结果显示：
成绩在30分以下的没有、
30分至39分有 1 个、
40分至49分有 1 个、
50分至59分没有、
60分至69分有 2 个、
70分至79分有 3 个、
80分至89分有 2 个、
90分至99分有 4 个、
还有 1 个是满分。*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<unsigned> scores(11);
    auto it = scores.begin();
    int grade;
    cout << "Please enter a group of scores (0~100): " << endl;
    while (cin >> grade)
        if (grade <= 100)
            ++*(it + grade/10); // 利用迭代器定位到对应的元素，加 1
    cout << "You have inputted in total " << scores.size() << " scores." << endl;
    cout << "The number of people in each band (from low to high) is: " << endl;
    // 利用迭代器遍历 scores 的元素并逐个输出
    for (it = scores.begin(); it != scores.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}