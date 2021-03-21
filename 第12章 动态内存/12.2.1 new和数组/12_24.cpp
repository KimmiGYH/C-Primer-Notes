#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char **argv)
{
	char c;
	
	// 分配 20 个字符的动态数组
	// 因此最多存放 19 个字符
    char *r = new char[20];
    int l = 0;
    
    while (cin.get(c)) {
        if (isspace(c)) // 空格符、制表符等空白符
            break;
        r[l++] = c;	// 存入动态数组
        if (l == 20) {
            cout << "达到数组容量上限" << endl;
            break;
        }
    }
    r[l] = 0;
    cout << r << endl;
    
    // 释放动态数组
    delete [] r;
    
    return 0;
}