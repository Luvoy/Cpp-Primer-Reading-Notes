//函数基础
#include <iostream>
int global_i = 1;
int f1()
{
    global_i *= 3;
    return global_i;
}

int f2()
{
    global_i *= 2;
    return global_i;
}

int f3(int a, int b)
{
    return a + b;
}

int f4(int a)
{
    // int a = 3; //错误，函数内部最外层scope的变量不能和形参重名
    int sum = 0;
    for (int a = 1; a <= 10; ++a) //内层scope，正确
    {
        sum += a;
    }
    return sum;
}
int f5(int a, int)
{ //不用的形参不给名字，也可以
    return a + 1;
}

int f6(void)
{
    //对于如下局部变量:
    int a;         //内置类型，未初始化，初始值未定义
    std::string s; //这种对象本身有默认值，默认初始化
    return 0;
}

int f7(void)
{ //第一次调用count_calls就初始化
    //f7函数调用结束并不会销毁
    //持续整个程序
    static int count_calls = 0; //带static的即使不给初始化，内置类型也会初始化为0
    return ++count_calls;
}

int main(int argc, char const *argv[])
{
    int ret = f3(f1(), f2()); //注意，参数求值的顺序是未定义的
    std::cout << "f3(f1(), f2()) = " << ret << std::endl;
    global_i = 1;
    ret = f3(f2(), f1());
    std::cout << "f3(f2(), f1()) = " << ret << std::endl;
    f4(5);
    return 0;
}
