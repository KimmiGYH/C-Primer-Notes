/* 练习2.30：对于下面的这些语句，请说明对象被声明成了顶层 const 还是底层 const？ */

(1) const int v2 = 0;
// 底层 const

(2) int v1 = v2;
// 顶层 const

(3) int *p1 = &vl, &rl = v1;
// 底层 const

(4) const int *p2 = &v2, *const p3 = &i, &r2 = v2;
// 底层 const，顶层 const，引用？底层？
