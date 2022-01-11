## 第一章 字符串处理

### 1. 字符串库函数

- `to_string()` //将整数转换成字符串
- `stoi(str);`  //将字符串转换成数字
- `atoi(str.c_str());`  //将字符数组转换成数字

### 2. 插入字符串的技巧

- 插入字符串 `res = ',' + res;`

### 3. 手写库函数 `to_string()`

```cpp
    int d = abs(c);
    while (d)
    {
        num = char(d % 10 + '0') + num, d /= 10;
    }
    if (c < 0) num = '-' + num;
    if (!c) num = "0";
```

### 4. 如何存储 `char` 对应的 `string` ？

[AcWing 1477. 拼写正确](https://www.acwing.com/activity/content/code/content/946348/)

- (1) 可以用 `Map` 数据结构

```cpp
    map<char, string> dict;
    dict['0'] = "zero"; dict['1'] = "one"; dict['2'] = "two"; dict['3'] = "three"; dict['4'] = "four";
    dict['5'] = "five"; dict['6'] = "six"; dict['7'] = "seven"; dict['8'] = "eight"; dict['9'] = "nine"; 
```

- (2) 也可以用二维字符数组 

```cpp
    char dict[10][6] = {
        "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
    };
```

[AcWing 1547. 约会](https://www.acwing.com/activity/content/code/content/963543/)

```cpp
    char week_days[7][4] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
```

### 6. 在字符串 s1 中删除 字符串 s2 中出现的所有字符

哈希表: [AcWing 1534. 字符串减法](https://www.acwing.com/activity/content/code/content/963405/)

```cpp
    unordered_set<char> hash; //定义哈希表
    for (auto c : s2)
        hash.insert(c); //将s2中的字符插入哈希表
    
    string res;
    for (auto c : s1)
        if (!hash.count(c))
            res += c;
```

### 7. 提取单词 + 哈希表记录最高频单词

[AcWing 1557. 说话方式](https://www.acwing.com/activity/content/code/content/963408/)

- 读入一整行：`getline(cin, str)`
- 提取每个单词，双指针算法
- 遍历哈希表中每个单词和它的次数，找一个最大值

```cpp
// 把每个单词提取出来并且放到哈希表中
for (int i = 0; i < str.size(); i++)
{
    string word;
    if 是字母或数字
        int j = i;
        while (j < str.size() && 也是字母或数字)  word += str[j++];
        i = j;
}
```




### 字符串模拟题

[AcWing 1478. 签到与签出](https://www.acwing.com/activity/content/code/content/946748/) （字典序比较字符串）

[AcWing 1520. 男孩 vs 女孩](https://www.acwing.com/activity/content/code/content/963401/)

[AcWing 1547. 约会](https://www.acwing.com/activity/content/code/content/963543/)

[AcWing 1546. 它们是否相等](https://www.acwing.com/activity/content/code/content/965544/)


### 繁琐的字符串模拟题

[AcWing 1493. 电话账单](https://www.acwing.com/activity/content/code/content/963911/)（前缀和+`sprintf`）

[AcWing 1494. 银行排队](https://www.acwing.com/activity/content/code/content/965082/)