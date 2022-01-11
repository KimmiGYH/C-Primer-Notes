/* 练习 3.30：指出下面代码中的索引错误。 */
constexpr size_t array_size = 10;
int ia[array_size];
for (size_t ix = 0; ix < array_size; ++ix)
    ia[ix] = ix;
