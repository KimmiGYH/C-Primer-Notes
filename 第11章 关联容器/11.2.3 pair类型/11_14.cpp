#include <iostream>
#include <map>
#include <vector>
#include <utility>
#include <string>
#include <algorithm>

using namespace std;

void add_family(map<string, vector<pair<string, string>>>& families, const string& family)
{
    families[family];
}

void add_child(map<string, vector<pair<string, string>>>& families, const string& family, const string& child, const string& birthday)
{
    families[family].push_back({child, birthday}); //列表初始化创建名字和生日的pair
}

int main(int argc, char *argv[])
{
    map<string, vector<pair<string, string>>> families;

    add_family(families, "Zhang");
    add_child(families, "Zhang", "Qiang", "1970-1-1");
    add_child(families, "Zhang", "Gang", "1980-1-1");
    add_child(families, "Wang", "Five", "1990-1-1");
    add_family(families, "Wang");

    for (auto f : families) {
        cout << f.first << "family's children: ";
        for (auto c : f.second)
            cout << c.first << "(birthday" << c.second << "), ";
        cout << endl;
    }

    return 0;
}