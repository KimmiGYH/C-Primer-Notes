/* 练习6.3：编写你自己的 fact 函数上级检查是否正确。

原书中的 fact 函数使用 while 循环执行递减连乘运算，我们改写该程序，使用普通 for 循环得到满足题意的函数。
*/

int fact (int val)
{
    if (val < 0)
        return -1;
    int ret = 1;
    // 从 1 连乘到 val
    for (int i = 1; i != val + 1; ++i)
        ret *= i;
    return ret;
}