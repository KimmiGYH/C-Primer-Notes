/* 练习2.36：关于下面的代码，请指出每一个变量的类型以及程序结束时它们各自的值。 */

int a = 3, b = 4;
decltype(a) c = a;      // int
decltype((b)) d = a;    // reference
++c;        // int
++d;        // int
// 因为 d 是变量 a 的别名。程序结束时，a, b, c, d 的值都是 4。