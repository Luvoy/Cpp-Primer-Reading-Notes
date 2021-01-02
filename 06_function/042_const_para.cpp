//const形参和实参
#include <iostream>
int f1(int *const i)
{ //形参是顶层const，实参传入顶层const或者非顶层const都可以
    int *a = i;
    if (a != nullptr)
        return *a;
    else
        return 0;
}
//c++允许函数名相同的多个函数定义，但必须参数明显不同
//但是顶层const在形参上是被忽略的，所以定义同名函数用顶层const参数不算
// int f1(int *p)//错误，redefinition
// {
//     return 0;
// }
int f2(const int *p)
{
    return 0;
}
int f2(int *p) //正确，底层const和非底层const，看作不同的形参
{
    return 0;
}
int f3(const int *const p)
{
    return 0;
}
int f4(int *p)
{
    return 0;
}
int main(int argc, char const *argv[])
{
    int i = 3;
    const int *low_const_p = &i;
    const int &low_const_ref = i;

    // int *p = low_const_p;//错误，不能用底层const初始化非底层const
    int *p = &i;
    const int *low_const_p_2 = p; //可以用非底层const初始化底层const

    //函数调用，形参的初始化和上面变量初始化类似
    // f1(low_const_p);//错误，不能用底层const初始化非底层const
    // f4(low_const_p_2);//错误，不能用底层const初始化非底层const

    //函数形参要尽量使用指向const的引用，养成这种习惯
    return 0;
}
