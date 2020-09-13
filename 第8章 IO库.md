<!-- TOC -->

- [第8章 `IO`库](#第8章-io库)
  - [8.1 `IO`类](#81-io类)
    - [`IO`类型间的关系](#io类型间的关系)
    - [8.1.1 `IO`对象无拷贝或赋值](#811-io对象无拷贝或赋值)
    - [8.1.2 条件状态](#812-条件状态)
      - [查询流的状态](#查询流的状态)
      - [管理条件状态](#管理条件状态)
    - [8.1.3 管理输出缓冲](#813-管理输出缓冲)
      - [刷新输出缓冲区](#刷新输出缓冲区)
      - [`unitbuf`操纵符](#unitbuf操纵符)
      - [关联输入和输出流](#关联输入和输出流)
  - [8.2 文件输入输出](#82-文件输入输出)
    - [8.2.1 使用文件流对象](#821-使用文件流对象)
      - [用`fstream`代替`iostream&`](#用fstream代替iostream)
      - [成员函数`open`和`close`](#成员函数open和close)
      - [自动构造和析构](#自动构造和析构)
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

如果到达文件结束位置，`eofbit`和`failbit`都会被置位。

`goodbit`的值为`0`，表示流未发生错误。

如果`badbit`、`failbit`和`eofbit`任一个被置位，则检测流状态的条件会失败。

标准库还定义了一组函数来查询这些标志位的状态．操作`good`在所有错误位均未置位的情况下返回`true`，而`bad`、`fail`和`eof`则在对应错误位被置位时返回`true`。

此外，在`badbit`被置位时，`fail`也会返回`true`。这意味着，使用`good`或`fail`是确定流的总体状态的正确方法。

实际上，我们将流当作条件使用的代码就等价于`!fail()`。而`eof`和`bad`操作只能表示特定的错误。

#### 管理条件状态

流对象的`rdstate`成员返回一个`iostate`值，对应流的当前状态。

`setstate`操作将给定条件位置位，表示发生了对应错误。

`clear`成员是一个重载的成员：它有一个不接受参数的版本，而另一个版本接受一个`iostate`类型的参数。

`clear`不接受参数的版本清除（复位）所有错误标志位。

执行`clear()`后，调用`good`会返回`true`。我们可以这样使用这些成员：

```cpp
// 记住 cin 的当前状态
auto old_state = cin.rdstate(); // 记住 cin 的当前状态
cin.clear();                    // 使 cin 有效
process_input(cin);             // 使用 cin
cin.setstate(old_state);        // 将 cin 置为原有状态
```

带参数的`clear`版本接受一个`iostate`值，表示流的新状态。
为了复位单一的条件状态位，我们首先用`rdstate`读出当前条件状态，然后用位操作将所需位复位来生成新的状态。

例如，下面的代码将`failbit`和`badbit`复位，但保持`eofbit`不变：

```cpp
// 复位 failbit 和 badbit，保持其他标志位不变
cin.clear(cin.rdstate() & ~cin.failbit & ~cin.badbit);
```

**练习8.1：编写函数，接受一个 istream& 参数，返回值类型也是 istream&。此函数须从给定流中读取数据，直至遇到文件结束标识时停止。它将读取的数据打印在标准输出上。完成这些操作后，在返回流之前，对流进行复位，使其处于有效状态。**

```cpp
/*练习8.1：编写函数，接受一个 istream& 参数，返回值类型也是 istream&。此函数须从给定流中读取数据，直至遇到文件结束标识时停止。它将读取的数据打印在标准输出上。完成这些操作后，在返回流之前，对流进行复位，使其处于有效状态。*/

/*【出题思路】本题是流的输入输出的基本练习。此外，本节介绍了流的条件状态，本题还对流的结束状态（本题是遇到文件结束符）、错误状态和数据错误状态（例如要求输入整数时输入了字符）的检测和处理进行了练习。*/

#include <iostream>
#include <stdexcept>
using namespace std;

istream& f(istream& in)
{
    int v;
    while (in >> v, !in.eof()) { // 直到遇到文件结束符才停止读取
        if (in.bad())
            throw runtime_error("IO流错误");
        if (in.fail()) {
            cerr << "Data error, please try again: " << endl;
            in.clear();
            in.ignore(100, '\n');
            continue;
        }
        cout << v << endl;
    }
    in.clear();
    return in;
}

int main()
{
    cout << "Please enter some integers, press Ctrl+Z to end." << endl;
    f(cin);
    return 0;
}

/* Output:
Please enter some integers, press Ctrl+Z to end.
1 247 565 65 485 65
1
247
565
65
485
65
*/
```

**练习8.3：什么情况下，下面的 while 循环会终止？**

```cpp
while (cin >> i) /* ... */
```

【解答】遇到了文件结束符，或者遇到了 IO 流错误，或者读入了无效数据。

### 8.1.3 管理输出缓冲

每个输出流都管理一个缓冲区，用来保存程序读写的数据。

```cpp
os << "please enter a value: ";
```

导致缓冲刷新（即，数据真正写到输出设备或文件）的原因有很多：

- 程序正常结束，作为`main`函数的`return`操作的一部分，缓冲刷新被执行。
- 缓冲区满时，需要刷新缓冲，而后新的数据才能继续写入缓冲区。
- 在每个输出操作之后，我们可以用操纵符`unitbuf`设置流的内部状态，来清空缓冲区。默认情况下，对`cerr`是设置`unitbuf`的，因此写到`cerr`的内容都是立即刷新的。
- 一个输出流可能被关联到另一个流。在这种情况下，当读写被关联的流时，关联到的流的缓冲区会被刷新。例如，默认情况下，`cin`和`cerr`都关联到`cout`。因此，读`cin`或写`cerr`都会导致`cout`的缓冲区被刷新。

#### 刷新输出缓冲区

我们已经使用过操纵符`endl`，它完成换行并刷新缓冲区的工作。
IO库中还有两个类似的操纵符：`flush`和`ends`。

`flush`刷新缓冲区，但不输出任何额外的字符；
`ends`向缓冲区插入空字符，然后刷新缓冲区：

```cpp
cout << "hi!" << endl;  // 输出 hi 和一个换行，然后刷新缓冲区
cout << "hi!" << flush; // 输出 hi，然后刷新缓冲区，不附加任何额外字符
cout << "hi!" << ends;  // 输出 hi 和一个空字符，然后刷新缓冲区
```

#### `unitbuf`操纵符

如果想在每次输出操作后都刷新缓冲区，我们可以使用`unitbuf`操纵符。它告诉流在接下来的每次写操作之后都进行一次`flush`操作。而`nounitbuf`操纵符则重置流．使其恢复使用正常的系统管理的缓冲区刷新机制：

```cpp
cout << unitbuf;    // 所有输出操作后都会立即刷新缓冲区
// 任何输出都立即刷新，无缓冲
cout << nounitbuf;  // 回到正常的缓冲方式
```

**警告：如果程序崩溃，输出缓冲区不会被刷新。**

如果程序异常终止，输出缓冲区是不会被刷新的，当一个程序崩溃后，它所输出的数据很可能停留在输出缓冲区中等待打印。

当调试一个已经崩溃的程序时．需要确认那些你认为已经输出的数据确实已经刷新了。否则，可能将大量时间浪费在追踪代码为什么没有执行上，而实际上代码已经执行了，只是程序崩溃后缓冲区没有被刷新，输出数据被挂起没有打印而已。

#### 关联输入和输出流

Note: 交互式系统通常应该关联输入流和输出流。这意味着所有输出，包括用户提示信息，都会在读操作之前被打印出来。

我们既可以将一个`istream`对象关联到另一个`ostream`，也可以将一个`ostream`关联到另一个`ostream`：

```cpp
cin.tie(&cout); // 仅仅是用来展示：标准库将 cin 和 cout 关联在一起
// old_tie 指向当前关联到 cin 的流（如果有的话）
ostream *old_tie = cin.tie(nullptr);    // cin 不再与其他流关联
// 将 cin 与 cerr 关联；这不是一个好主意，因为 cin 应该关联到 cout
cin.tie(&cerr);     // 读取 cin 会刷新 cerr 而不是 cout
cin.tie(old_tie);   // 重建 cin 和 cout 间的正常关联
```

## 8.2 文件输入输出

头文件`fstream`定义了三个类型来支持文件IO：`ifstream`从一个给定文件读取数据，`ofstream`向一个给定文件写入数据，以及`fstream`可以读写给定文件。

| 表8.3：                   | `fstream`特有的操作                                          |
| ------------------------- | ------------------------------------------------------------ |
| `fstream fstrm;`          | 创建一个未绑定的文件流。`fstream`是头文件`fstream`中定义的一个类型 |
| `fstream fstrm(s);`       | 创建一个`fstream`，并打开名为`s`的文件。`s`可以是`string`类型，或者是一个指向`C`风格字符串的指针。这些构造函数都是`explicit`的。默认的文件模式`mode`依赖于`fstream`的类型。 |
| `fstream fstrm(s, mode);` | 与前一个构造函数类似，但按指定`mode`打开文件                 |
| `fstrm.open(s)`           | 打开名为`s`的文件，并将文件与`fstrm`绑定。`s`可以是一个`string`或一个指向`C`风格字符串的指针。默认的文件`mode`依赖于`fstream`的类型。返回`void` |
| `fstrm.close()`           | 关闭与`fstrm`绑定的文件。返回`void`                          |
| `fstrm.is_open()`         | 返回一个`bool`值，指出与`fstrm`关联的文件是否成功打开并且尚未关闭 |

### 8.2.1 使用文件流对象

```cpp
ifstream in(ifile); // 构造一个 ifstream 并打开给定文件
ofstream out;       // 输出文件流未关联到任何文件
```

这段代码定义了一个输入流`in`，它被初始化为从文件读取数据，文件名由`string`类型的参数`ifile`指定。

第二条语句定义了一个输出流`out`，未与任何文件关联。

#### 用`fstream`代替`iostream&`

```cpp
ifstream input(argv[1]);    // 打开销售记录文件
ofstream output(argv[2]);   // 打开输出文件
Sales_data total;           // 保存销售总额的变量
if (read(input, total)) {   // 读取第一条销售记录
    Sales_data trans;       // 保存下一条销售记录的变量
    while (read(input, trans)) {            // 读取剩余记录
        if (total.isbn() == trans.isbn())   // 检查 isbn
            total.combine(trans);           // 更新销售总额
        else {
            print(output, total) << endl;   // 打印结果
            total = trans;                  // 处理下一本书
        }
    }
    print(output, total) << endl;   // 打印最后一本书的销售额
} else                              // 文件中无输入数据
    cerr << "No data?!" << endl;
```

虽然两个函数定义时指定的形参分别是`istream&`和`ostream&`，但我们可以向它们传递`fstream`对象。

#### 成员函数`open`和`close`

如果我们定义了一个空文件流对象，可以随后调用`open`来将它与文件关联起来：

```cpp
ifstream in(ifile);         // 构筑一个 ifstream 并打开给定文件
ofstream out;               // 输出文件流未与任何文件相关联
out.open(ifile + ".copy");  // 打开指定文件
```

因此调用`open`可能会失败，进行`open`是否成功的检测通常是一个好习惯：

```cpp
if (out)    // 检查 open 是否成功
            // open 成功，我们可以使用文件了
```

对一个已经打开的文件流调用`open`会失败，并会导致`failbit`被置位。随后的试图使用文件流的操作都会失败。为了将文件流关联到另外一个文件，必须首先关闭已经关联的文件。一旦文件成功关闭，我们可以打开新的文件：

```cpp
in.close();             // 关闭文件
in.open(ifile + "2");   // 打开另一个文件
```

如果`open`成功，用`open`会设置流的状态，使得`good()`为`true`。

#### 自动构造和析构

```cpp
// 对每个传递给程序的文件执行循环操作
for (auto p = argv + 1; p != argv + argc; ++p) {
    ifstream input(*p);     // 创建输出流并打开文件
    if (input) {            // 如果文件打开成功，“处理”此文件
        process(input);
    } else
        cerr << "couldn't open: " + string(*p);
}   // 每个循环步 input 都会离开作用域，因此会被销毁
```

Note: 当一个`fstream`对象被销毁时，`close`会自动被调用。

**练习8.4：编写函数，以读模式打开一个文件，将其内容读入到一个 `string` 的 `vector` 中将每一行作为一个独立的元素存于 `vector` 中。**

```cpp
/*练习8.4：编写函数，以读模式打开一个文件，将其内容读入到一个 string 的vector 中将每一行作为一个独立的元素存于 vector 中。

【出题思路】本题练习文件输入和流的逐行输入，还练习了使用迭代器遍历容器中的元素。

ios::in 打开文件用于读取。
https://www.runoob.com/cplusplus/cpp-files-streams.html
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ifstream in("data");            // 打开文件
    if (!in) {
        cerr << "Fails to open the file" << endl;
        return -1;
    }

    string line;
    vector<string> words;
    while (getline(in, line)) {     // 从文件中读取一行
        words.push_back(line);      // 添加到 vector 中
    }

    in.close();                     // 输入完毕，关闭文件

    vector<string>::const_iterator it = words.begin();  // 迭代器
    while (it != words.end()) {     // 遍历 vector
        cout << *it << endl;        // 输出 vector 中的元素
        ++it;
    }

    return 0;
}
```

### 8.2.2 文件模式



## 8.3 `string`流

### 8.3.1 使用`istringstream`

### 8.3.2 使用`ostringstream`
