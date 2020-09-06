/*练习 10.2：重做上一题，但读取 string 序列存入 list 中。
【解答】可以看到，与上一题对比．程序的变化只在不同类型变量的声明上，而算法的 使用部分几乎没有任何差异。*/

#include <iostream>
#include <fstream>
#include <string>
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

    list<string> ls;
    string word;
    while (in >> word)
        ls.push_back(word);
    
    cout << "Please enter the strings you wanna search: ";
    cin >> word;

    cout << "The sequence contains " << count(ls.begin(), ls.end(), word)
         << "个" << word;
    
    return 0;
}