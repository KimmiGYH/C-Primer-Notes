<!-- TOC -->

- [第8章 `IO`库](#第8章-io库)
  - [8.1 `IO`类](#81-io类)
    - [`IO`类型间的关系](#io类型间的关系)
    - [8.1.1 `IO`对象无拷贝或赋值](#811-io对象无拷贝或赋值)
    - [8.1.2 条件状态](#812-条件状态)
      - [查询流的状态](#查询流的状态)
      - [管理条件状态](#管理条件状态)
    - [8.1.3 管理输出缓冲](#813-管理输出缓冲)
  - [8.2 文件输入输出](#82-文件输入输出)
    - [8.2.1 使用文件流对象](#821-使用文件流对象)
    - [8.2.2 文件模式](#822-文件模式)
  - [8.3 `string`流](#83-string流)
    - [8.3.1 使用`istringstream`](#831-使用istringstream)
    - [8.3.2 使用`ostringstream`](#832-使用ostringstream)

<!-- /TOC -->

# 第8章 `IO`库

已经学过的`IO`库设施：

- `istream` (输入流)类型，提供输入操作。
- `ostream` (输出流)类型，提供输出操作。
- `cin`，一个 `istream` 对象，从标准输入读取数据。
- `cout`，一个 `ostream` 对象，向标准输出写入数据。
- `cerr`，一个 `ostream` 对象，通常用于输出程序错误消息，写入到标准错误。
- `>>` 运算符，用来从一个 istream 对象读取输入数据。
- `<<` 运算符，用来向一个 ostream 对象写入输出数据。
- `getline` 函数，从一个给定的 `istream` 读取一行数据，存入一个给定的 `string` 对象中。

## 8.1 `IO`类

头文件  类型

- 头文件`iostream`
  - `istream`，`wistream`从流读取数据
  - `ostream`，`wostream`向流写入数据
  - `iostream`，`wiostream`读写流
- 头文件`fstream`
  - `ifstream`，`wifstream`从文件读取数据
  - `ofstream`，`wofstream`向文件写入数据
  - `fstream`，`wfstream`读写文件
- 头文件`sstream`
  - `istringstream`，`wistringstream`从`string`读取数据
  - `ostringstream`，`wostringstream`向`string`写入数据
  - `stringstream`，`wstringstream`读写`string`

### `IO`类型间的关系

概念上，设备类型和字符大小都不会影响我们要执行的`IO`操作。
例如，我们可以用`>>`读取数据，而不用管是从一个控制台窗口，一个磁盘文件，还是一个`string`读取。类似的，我们也不用管读取的字符能存入一个`char`对象内，还是需要一个`wchar_t`对象来存储。

标准库使我们能忽略这些不同类型的流之间的差异，这是通过**继承机制**(inheritance)实现的。
继承机制使我们可以声明一个特定的类继承自另一个类。我们通常可以将一个派生类（继承类）对象当作其**基类**。

类型 `ifstream` 和 `istringstream` 都继承自 `istream`。（`istream`是前两者的基类。）

因此我们可以向使用 `istream` 对象一样来使用 `ifstream` 和 `istringstream` 对象。
也就是说，我们是如何使用 `cin` 的，就可以同样地使用这些类型的对象。

### 8.1.1 `IO`对象无拷贝或赋值

```cpp
ofstream out1, out2;
out1 = out2;                // 错误：不能对流对象赋值
ofstream print(ofstream);   // 错误：不能初始化 ofstream 参数
out2 = print(out2);         // 错误：不能拷贝流对象
```

### 8.1.2 条件状态

| 表8.2：             | `IO`库条件状态                                               |
| ------------------- | ------------------------------------------------------------ |
| `strm::iostate`     | `strm`是一种`IO`类型。`iostate`是一种机器相关的类型，提供了表达条件状态的完整功能 |
| `strm::badbit`      | `strm::badbit`用来指出流已崩溃                               |
| `strm::failbit`     | `strm::failbit`用来指出一个`IO`操作失败了                    |
| `strm::eofbit`      | `strm::eofbit`用来指出流到达了文件结束                       |
| `strm::goodbit`     | `strm::goodbit`用来指出流未处于错误状态。此值保证为零        |
| `s.eof()`           | 若流`s`的`eofbit`置位，则返回`true`                          |
| `s.fail()`          | 若流`s`的`failbit`或`badbit`置位，则返回`true`               |
| `s.bad()`           | 若流`s`的`badbit`置位，则返回`true`                          |
| `s.good()`          | 若流`s`处于有效状态，则返回`true`                            |
| `s.clear()`         | 将流`s`中所有条件状态位复位，将流的状态设置为有效，返回`void` |
| `s.clear(flags)`    | 根据给定的`flags`标志位，将流`s`中对应条件状态位复位。`flags`的类型为`strm::iostate`。返回`void` |
| `s.setstate(flags)` | 根据给定的`flags`标志位，将流`s`中对应条件状态位置位。`flags`的类型为`strm::iostate`，返回`void` |
| `s.rdstate()`       | 返回流`s`的当前条件状态，返回值类型为`strm::iostate`         |

代码通常应该在使用一个流之前检查它是否处于良好状态。
确定一个流对象的状态的最简单的方法是将它当做一个条件来使用：
`while`循环检查`>>`表达式返回的流的状态。如果输入操作成功，流保持有效状态，则条件为真。

```cpp
while (cin >> word)
    // OK：读操作成功……
```

#### 查询流的状态

`IO`库定义了一个与机器无关的`iostate`类型，它提供了表达流状态的完整功能。

`badbit`表示系统级错误，如不可恢复的读写错误。通常情况下，一旦`badbit`被置位，流就无法再使用了。
在发生可恢复错误后，`failbit`被置位，如期望读取数值却读出一个字符等错误。

如果到达文件结束为止，`eofbit`和`failbit`都会被置位。

`goodbit`的值为`0`，表示流未发生错误。

如果`badbit`、`failbit`和`eofbit`任一个被置位，则检测流状态的条件会失败。

#### 管理条件状态



### 8.1.3 管理输出缓冲

## 8.2 文件输入输出

### 8.2.1 使用文件流对象

### 8.2.2 文件模式

## 8.3 `string`流

### 8.3.1 使用`istringstream`

### 8.3.2 使用`ostringstream`
