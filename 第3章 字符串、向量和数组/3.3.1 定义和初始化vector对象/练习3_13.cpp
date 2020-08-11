/* 练习3.13：下列的 vector 对象各包含多少个元素怒？这些元素的值分别是多少？ */

(a) vector<int> v1;
// 包含 0 个元素，是没有初始值的 int 型 vector

(b) vector<int> v2(10);
// 10 个元素，每个元素为 0

(c) vector<int> v3(10, 42);
// 10 个元素，每个元素初始值为 42‘

(d) vector<int> v4{10};
// 1 个元素，元素值为 10

(e) vector<int> v5{10, 42};
// 2 个元素，元素值分别为 10, 42；

(f) vector<string> v6{10};
// 报错，int 型的 10 不能赋给 string 类型的 vector ？？
// 10 个元素？空字符串？

(g) vector<string> v7{10, "hi"};
// 报错……？？