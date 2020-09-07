/*练习10.9：实现你自己的 elimDups。测试你的程序，分别在读取输入后、调用 unique 后以及调用 erase 后打印vector 的内容。*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

inline void output_words(vector<string> &words)
{
    for (auto iter = words.begin(); iter != words.end(); iter++)
        cout << *iter << " ";
    cout << endl;
}

void elimDups(vector<string> &words)
{
    output_words(words);

    sort(words.begin(), words.end());
    output_words(words);

    auto end_unique = unique(words.begin(), words.end());
    output_words(words);

    words.erase(end_unique, words.end());
    output_words(words);
}

int main(int argc, char *argv[])
{
    ifstream in(argv[1]);
    if (!in) {
        cout << "Fails to open the file!" << endl;
        exit(1);
    }

    vector<string> words;
    string word;
    while (in >> word)
        words.push_back(word);
    
    elimDups(words);

    return 0;
}