/* 练习6.54：编写函数的声明，令其接受两个 int 形参并且返回类型也是 int；
然后声明一个 vector 对象，令其元素是指向该函数的指针。

【出题思路】考查函数指针的声明和使用。*/

// 满足题意的函数：
int func(int, int);

// 满足题意的 vector 对象：
vector<decltype(func)*> vF;
