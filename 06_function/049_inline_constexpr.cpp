//内联函数(inline)用于优化规模小，流程直接，频繁调用的函数
//可以直接在调用点展开
//只是一种编译建议
#include <iostream>
//constexpr函数，返回值和形参都是字面值类型
//只能有一个return

// constexpr int f1(int a)
// {
//     if (a) //错误，
//     {
//         return 1;
//     }
//     else
//     {
//         return 0; //错误只能有一个return
//     }
//其实编译器检查最后一行是不是return
// }

constexpr int f2(int a)
{
    typedef char my_char; //typedef
    ;                     //空语句
    return 1;
}

constexpr int f3(int a)
{
    return 3 * a; //只要a是常量表达式，返回值就是常量表达式，虽然直观上看起来返回值不是常量表达式
}
//书上说inline和constexpr函数可以多次定义，但定义必须一样
//实际测试不能重复定义
//TODO
//建议inline和constexpr函数定义在头文件中
int main(int argc, char const *argv[])
{
    // constexpr int ret1 = f1(2);
    constexpr int ret2 = f2(2);

    int i = 2;
    // constexpr int ret3 = f3(i); //错误, i不是常量
    const int ii = 2;
    constexpr int ret4 = f3(ii); //正确

    return 0;
}
