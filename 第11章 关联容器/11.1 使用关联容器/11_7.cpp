#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void add_family(map<string, vector<string>>& families, const string& family)
{
    if (families.find(family) == families.end())
        families[family] = vector<string>();
}

void add_child(map<string, vector<string>>& families, const string& family, const string& child)
{
    families[family].push_back(child);
}

int main(int argc, char *argv[])
{
    map<string, vector<string>> families;

    add_family(families, "Zhang");
    add_child(families, "Zhang", "Qiang");
    add_child(families, "Zhang", "Gang");
    add_child(families, "Wang", "Five");
    add_family(families, "Wang");

    for (auto f : families) {
        cout << f.first << " family's children are: ";
        for (auto c : f.second)
            cout << c << ", ";
        cout << endl;
    }

    return 0;
}

/*
Wang family's children are: Five, 
Zhang family's children are: Qiang, Gang, 
*/