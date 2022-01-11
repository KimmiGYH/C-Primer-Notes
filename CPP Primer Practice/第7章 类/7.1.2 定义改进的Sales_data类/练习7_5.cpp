/* 练习7.5：在你的 Person 类中提供一些操作使其能够返回姓名和住址。
这些函数是否应该是 const 的呢？解释原因。*/

class Person
{
private:
    string strName;
    string strAddress;
public:
    string getName() const { return strName; }          // 返回姓名
    string getAddress() const { return strAddress; }    // 返回地址
};