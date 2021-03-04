# 字符、字符数组、stirng字符串的输入输出

## 字符 `char ch;`

- 输入：`scanf("%c", &ch);` 或 `cin >> ch;`
- - 过滤掉回车：`scanf("\n%c", &c);`

- 输出：`printf("%c", ch);` 或 `cout << ch;`

## 字符数组 `char s[31]`
 遇空格回车停止

### 单个

- 输入：`scanf("%s", s);` 或 `cin >> s;`
- - 从下标`1`开始读入：`scanf("%s", s + 1);` 或 `cin >> s + 1`
- 输出：`printf("%s\n", s);` 或 `cout << s;`
- - 从下标`1`开始输出：`printf("%s\n", s + 1);` 或 `cout << s + 1;`

### 一整行

- 输入：`fgets(s, 31, stdin);` 或 `cin.getline(s, 31);`
- 输出：`printf("%s", s);` 或 `cout << s;` 或 `puts(s);`
- - 注：`puts(s);` (自动补上换行符) 等价于 `printf("%s\n", s);` 

### 字符数组的常见操作

- `(1)	strlen(str);` 求长度 $O(n)$
- `(2)	strcmp(a, b);` 比较
- `(3)	strcpy(a, b);` 将后者复制给前者

## string 字符串
`string` 动态分配可变长的字符序列

### 单个

- 输入：`cin >> s;` 不能用 `scanf` 读入
- 输出：`cout << s` 或 `printf("%s", s.c_str());`  或 `puts(s.c_str());`
- - 注：`c_str()`返回字符数组首地址

### 一整行

- 输入：`getline(cin, s);` (用`cin`只能读入第一个字符串)
- 输出：`cout << s;`

## 字符串流 `stringstream`

- 头文件：`#include <sstream>`
- 输入：`stringstream ssin(s);`
