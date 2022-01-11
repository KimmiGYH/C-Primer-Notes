#include <iostream>
#include <vector>
#include <string>

using namespace std;

void name_string(string& name, const string& prefix, const string& suffix)
{
    name.insert(name.begin(), 1, ' '); // 加空格
    name.insert(name.begin(), prefix.begin(), prefix.end()); // 插入前缀
    name.append(" ");
    name.append(suffix.begin(), suffix.end());
}

int main()
{
    string name = "James Bond";
    name_string(name, "Mr.", "II");
    cout << name << endl; // Mr. James Bond II

    name = "M";
    name_string(name, "Mrs.", "III");
    cout << name << endl; // Mrs. M III

    return 0;
}
