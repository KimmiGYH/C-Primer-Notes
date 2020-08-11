/* 练习3.12：下列 vector 对象的定义有不正确的吗？
如果有，请指出来。对于正确的，描述其执行结果；对于不正确的，说明其错误的原因。*/

(a) vector<vector<int>> ivec;
// 正确。定义了一个名为`ivec`的`vector`对象，其中的每个元素都是`vector<int>`对象。

(b) vector<string> svec = ivec;
// 错误。`svec`的元素类型是`string`，而`ivec`的元素类型是`int`，因此不能使用`ivec`初始化`svec`。

(c) vector<string> svec(10, "null");
// 正确。定义了一个名为`svec`的`vector`对象，其中含有 10 个元素，每个元素都是字符串 `null`。(null 是一个 int 变量，但这里写的是 "null")。