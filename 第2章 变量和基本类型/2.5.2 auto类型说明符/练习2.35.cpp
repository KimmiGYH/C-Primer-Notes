/* 练习 2.35：判断下列定义推断出的类型是什么，然后编写程序进行验证。*/

(1) const int i = 42;
// 整型常量

(2) auto j = i; const auto &k = i; auto *p = &i;
// 整数          对整数常量的引用     指向整数常量的指针

(3) const auto j2 = i, &k2 = i;
// 整数常量             k2 是 i 的别名

