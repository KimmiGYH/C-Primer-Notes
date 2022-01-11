#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

void find_char(string& s, const string& chars)
{
    printf("In string s: %s found element: %s\n", s.c_str(), chars.c_str());

    string::size_type pos = 0;
    while ((pos = s.find_first_of(chars, pos)) != string::npos)
    {
        cout << "pos: " << pos << ", char: " << s[pos] << endl;
        pos++;
    }
}

int main()
{
    string s = "ab2c3d7R4E6";

    cout << "Found all the digits" << endl;
    find_char(s, "0123456789");
    
    cout << endl << "Found all the letters" << endl;
    find_char(s, "abcdefghijklmnopqrstuvwxyz"\
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ");

    return 0;
}
/*
Found all the digits
In string s: ab2c3d7R4E6 found element: 0123456789
pos: 2, char: 2
pos: 4, char: 3
pos: 6, char: 7
pos: 8, char: 4
pos: 10, char: 6

Found all the letters
In string s: ab2c3d7R4E6 found element: abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ
pos: 0, char: a
pos: 1, char: b
pos: 3, char: c
pos: 5, char: d
pos: 7, char: R
pos: 9, char: E
*/