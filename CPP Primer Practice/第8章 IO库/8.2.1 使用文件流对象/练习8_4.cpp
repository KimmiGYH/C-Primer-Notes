/*练习8.4：编写函数，以读模式打开一个文件，将其内容读入到一个 string 的vector 中将每一行作为一个独立的元素存于 vector 中。

【出题思路】本题练习文件输入和流的逐行输入，还练习了使用迭代器遍历容器中的元素。

ios::in 打开文件用于读取。
https://www.runoob.com/cplusplus/cpp-files-streams.html
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ifstream in("data");            // 打开文件
    if (!in) {
        cerr << "Fails to open the file" << endl;
        return -1;
    }

    string line;
    vector<string> words;
    while (getline(in, line)) {     // 从文件中读取一行
        words.push_back(line);      // 添加到 vector 中
    }

    in.close();                     // 输入完毕，关闭文件

    vector<string>::const_iterator it = words.begin();  // 迭代器
    while (it != words.end()) {     // 遍历 vector
        cout << *it << endl;        // 输出 vector 中的元素
        ++it;
    }

    return 0;
}