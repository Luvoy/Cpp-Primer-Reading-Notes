//decltype的用法
#include <iostream>
int func(int a, int b)
{
    return 0;
}
int sum(int a, int b)
{
    return a + b;
}
int max(int a, int b)
{
    return a > b ? a : b;
}

int main(int argc, char const *argv[])
{
    decltype(sum(1, 1.8)) a = 3; //书上写编译器并不实际调用func

    const int c1 = 1;
    const int &ref1 = c1;
    int i = 0;
    int &ref2 = i;

    decltype(c1) d1 = 4;
    decltype(ref1) d2 = 6;
    // decltype(ref1) d3;     //错误，引用必须初始化
    // decltype(ref2) d4;     //错误，引用必须初始化
    // decltype(ref2) d5 = 2; //错误 low初始化non-low

    int j = 1;
    decltype(ref2) ref3 = j; //ref3是个引用，指向j
    decltype(ref2 + 0) k;    //k是个int, 因为ref2+0这个表达式是个具体值了
    k = 3;
    std::cout << "j = " << j << ", ref3 = " << ref3 << ", k = " << k << std::endl;

    int *p = &j;
    decltype(*p) ref4 = k; //说出来你可能不信，*p得到的就是引用类型

    //如果decltype中的变量加上括号，编译器把它当作表达式，变量是一种可以作为左值的特殊表达式，所以最终会得到引用。
    //而且这种结果永远是引用
    decltype((j)) ref5 = k;
    decltype(j) m; //不加括号就是int

    decltype((func)) f = max; //函数引用
    std::cout << "max(1,2) is " << f(1, 2) << std::endl;
    return 0;
}
