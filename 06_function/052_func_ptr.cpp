//函数指针
//和c类似，不过多测试

//返回函数指针
#include <iostream>
using my_func = int(int, int);
using my_func_p = int (*)(int, int);

my_func *f1(double a);                  //返回函数指针
my_func_p f1(double a);                 //返回函数指针
auto f1(double a) -> int (*)(int, int); //返回函数指针

int add(int a, int b)
{
    return a + b;
}

//和数组名类似，当函数名add作为实参，右值，就是函数指针，
//但是decltype特殊,decltype(）一个数组，得到的就是数组，decltype一个函数，得到的就是函数
//想要指针必须再加*
decltype(add) *f1(double a);

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
