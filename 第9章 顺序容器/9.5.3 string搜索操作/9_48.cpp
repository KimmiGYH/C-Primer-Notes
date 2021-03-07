#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string name = "r2d2", numbers = "0123456789";
    
    printf("In string s: \"%s\" to find elment: \"%s\"\n", name.c_str(), numbers.c_str());

    string::size_type pos = 0;
    while ((pos = name.find_first_of(numbers, pos)) != string::npos)
    {
        cout << "pos: " << pos << ", numbers: " << name[pos] << endl;
        pos++;
    }

    return 0;
}

/*
In string s: "r2d2" to find elment: "0123456789"
pos: 1, numbers: 2
pos: 3, numbers: 2
*/