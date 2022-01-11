#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
    ifstream in(argv[1]);
    if (!in) {
        cout << "Fails to open the file! " << endl;
        exit(1);
    }

    map<string, size_t> word_count; // string 到 count 的映射
    string word;
    while (in >> word)
        ++ word_count[word];        // 这个单词的出现次数加 1

    for (const auto& w: word_count) // 对 map 中的每个元素
        cout << w.first << "appears " << w.second << "times." << endl;
    
    return 0;
}
