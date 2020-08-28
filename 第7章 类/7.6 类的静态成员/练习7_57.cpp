/* 练习7.57：编写你自己的 Account 类。

【解答】如果类的某些（某个）成员从逻辑上来说更应该与类本身关联，而不是与类的具体对象关联，则我们应该把这种成员声明成静态的。
在 Account 类中，很明显利率是相对稳定和统一的，应该是静态成员；
而开户人以及它的储蓄额则与对象息息相关，不能是静态的。*/

class Account
{
private:
    string strName;
    double dAmount = 0.0;
    static double dRate;
};
