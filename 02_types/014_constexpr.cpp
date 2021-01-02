//常量表达式
//值不变，并且在编译阶段就可以直接得到计算结果的表达式

#include <iostream>
int global = 42;
int main(int argc, char const *argv[])
{
    const int a = 20;    //是
    const int b = a + 1; //是
    int c = 27;          //不是
    // const int d = func(); //如果运行时才得到，不是

    /*********************/
    //用constexpr定义常量表达式：
    // constexpr int ii0;//未初始化错误
    constexpr int c1 = 20;     //是常量表达式
    constexpr int c2 = c1 + 4; //是常量表达式
    // constexpr int c3 = size(); //只有size()是一个constexpr函数时，才正确

    /****************************/

    //可声明为constexpr的类型叫做：字面值类型
    //基本算术类型，指针，引用都属于 字面值类型
    //自定义类，IO库，string类都不属于

    //注意，指针类型用作字面值类型时，要求必须初始化为常量
    // constexpr int *p1 = &c;         //错误，&c不是常量表达式
    // constexpr int *p2 = &a;         //错误
    constexpr int *p3 = nullptr; //正确，constexpr指针的初始值，必须是常量地址（top-const）
    // constexpr int *p4 = 0x12345678; //错误，不能将int赋值给int*
    // constexpr int *p5 = (int *const)(&c);//错误，(int* const)(& c)不是常量表达式
    // constexpr int *p6 = reinterpret_cast<int *const>(&c);//错误，(int* const)(& c)不是常量表达式
    // constexpr int *p7 = static_cast<int *const>(&c);//错误，&c不是常量表达式
    constexpr int *p8 = (int *const)(0x12345678);                 //正确，c风格强制转换.但是在linux-gcc编译错误//TODO
    constexpr int *p9 = reinterpret_cast<int *const>(0x12345678); //正确，指针强制转换 linux 编译错误//TODO
    // constexpr int *p10 = static_cast<int *const>(0x12345678); //错误，转换无效

    constexpr int *p11 = &global; //正确
    //函数体内的变量，地址一般不确定
    //函数体外的变量，地址固定不变

    static int s_i = 33;
    constexpr int *p12 = &s_i; //正确
    //函数内static变量有固定地址

    //
    //注意：constexpr的指针，是本身const，不是指向const
    //即constexpr是top-level const

    constexpr const int *p13 = &global; //non-low赋值给low

    return 0;
}
