//返回数组指针
#include <iostream>

//正常方式：
//elem_type (* func_name(parameters_list))[dimension]
int (*f1(int a, int b))[10]
{
    return nullptr;
}

//类型别名
using int_arr_10 = int[10]; //c++11
// typedef int int_arr_10[10];
int_arr_10 *f1(int a, int b)
{
    return nullptr;
}

//c++11: 尾置返回类型
auto f3(int a, int b) -> int (*)[10]
{
    return nullptr;
}

//使用decltype, 但必须现有已知
int global_arr[10];
decltype(global_arr) *f4(int a, int b) //decltype的特性，数组不会变成指针
{
    return nullptr;
}

//错误
// int (*)[10] f(int a, int b)
// {
//     return nullptr;
// }
int main(int argc, char const *argv[])
{
    int_arr_10 *p;
    int a[2][10];
    p = a;
    return 0;
}
