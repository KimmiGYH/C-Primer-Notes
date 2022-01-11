#include <iostream>
#include <memory>

using namespace std;

struct destination {};
struct connection {};

connection connect(destination *pd)
{
    cout << "Open the connection" << endl;
    return connection();
}

void disconnect(connection c)
{
    cout << "Close the connection" << endl;
}

// 未使用 shared_ptr 的版本
void f(destination &d)
{
    cout << "Directly manage connect" << endl;
    connection c = connect(&d);
    // 忘记调用 disconnect 关闭连接

    cout << endl;
}

void end_connection(connection *p) { disconnect(*p); }

// 使用 shared_ptr 的版本
void f1(destination &d)
{
    cout << "Use shared_ptr to manage connect" << endl;
    connection c = connect(&d);

    shared_ptr<connection> p(&c, end_connection);
    // 忘记调用 disconnect 关闭连接

    cout << endl;
}

int main(int argc, char **argv)
{
    destination d;
    f(d);
    f1(d);

    return 0;
}

/*
Directly manage connect
Open the connection

Use shared_ptr to manage connect
Open the connection

Close the connection
*/