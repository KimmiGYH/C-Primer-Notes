/* 练习5.14：编写段程序，从标准输入中读取若干 string 对象并查找连续重复出现的单词。
所谓连续重复出现的意思是：一个单词后面紧跟着这个单词本身。要求记录连续重复出现的最大次数以及对应的单词。
如果这样的单词存在，输出重复出现的最大次数；
如果不存在，输出一条信息说明任何单词都没有连续出现过。
例如，如果输入是
    how now now now brown cow cow
那么输出应该表明单词 now 连续出现了 3 次。*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string currString, preString = "", maxString;
    int currCnt = 1, maxCnt = 0;
    while (cin >>currString)
    {
        if (currString == preString)
        {
            ++currCnt;
            if (currCnt > maxCnt)
            {
                maxCnt = currCnt;
                maxString = currString;
            }
        }
        else // 如果当前字符串与前一个字符串不一致，重置 currCnt
        {
            currCnt = 1;
        } // 更新 preString 以便于下一次循环使用
        preString = currString;
    }
    
    if (maxCnt > 1)
        cout << "The most frequently occured string is: " << maxString 
             << ", and the number of occurence is: " << maxCnt << endl;
    else
        cout << "Every string occurrs only once." << endl;
    return 0;
}