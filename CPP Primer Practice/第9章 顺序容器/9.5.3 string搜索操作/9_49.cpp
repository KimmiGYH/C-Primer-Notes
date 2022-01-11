#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void find_longest_word(ifstream &in)
{
    string s, longest_word;
    int max_length = 0;

    while (in >> s) {
        if (s.find_first_of("bdfghjklpqty") != string::npos)  continue; // 重要
        cout << s << " ";
        if (max_length < s.size()) { // 新单词更长
            max_length = s.size(); // 记录长度和单词
            longest_word = s;
        }
    }
    cout << endl << "Longest string is: " << longest_word << endl;
}


int main(int argc, char *argv[])
{
    ifstream in(argv[1]);
    if (!in) {
        cerr << "Can't open the input file" << endl;
        return -1;
    }

    find_longest_word(in);

    return 0;
}