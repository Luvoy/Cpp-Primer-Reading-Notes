#include <string>
#include <vector>
class Account
{
public:
    void balance()
    { //结算
        amount += amount * rate;
    }
    static double get_rate()
    { //静态成员函数，不包含this，不能使用this，也不能声明为const
        return rate;
    }
    static void set_rate(double); //仅声明

private:
    std::string owner;
    double amount;
    static double rate; //静态数据成员不和任何对象绑定在一起，被所有对象共享

    //constexpr字面值常量的static成员，可以初始化
    constexpr static int balance_cycle_period = 30;
    double daily_array[balance_cycle_period]; //用constexpr指定数组维度，
    //constexpr static：如果只是用作编译时替换，不需要再单独定义，否则需要单独定义。
    //为了方便所有static数据成员都在类外定义一下
};
void Account::set_rate(double new_rate) //定义不能加staic，仅声明加
{
    rate = new_rate;
}

//静态数据成员不属于单独的对象，不是创建对象时定义
//也就是和构造函数无关
//也就是不能在类内部初始化静态数据成员（一般来说)
//在外部定义初始化，只能定义1次
double Account::rate = 0.05;

constexpr int Account::balance_cycle_period; //已经给了初始值不用再给了

class X
{ //static成员的另一个用途
public:
    void func(int a = arg); //static数据成员可以作为默认参数

    static X x1; //static允许不完全类型
    X *xp1;
    // X x2; //不允许不完全类型，错误

    static int arg;
};

class Y
{
public:
    // static double a = 6.5; //错误，需要constexpr
    static const int b = 3;

    // static std::vector<double> v1(b);//错 //TODO
};
#include <iostream>
int main(int argc, char const *argv[])
{
    Account a1;
    double r1 = a1.get_rate();

    double r2 = Account::get_rate();

    std::cout << "r1 = " << r1 << ", r2 = " << r2 << std::endl;
    return 0;
}
