//条件运算符 condition?A:B;
#include <iostream>
int main(int argc, char const *argv[])
{
    //当条件运算符的两个表达式都是左值（或者转换成同一种左值类型），结果才是左值
    //否则右值
    int a = 0, b = 1;

    a < b ? a : b = 2;
    std::cout << "a = " << a << ", b = " << b << std::endl; //这里没有修改
    (a < b ? a : b) = 2;
    std::cout << "a = " << a << ", b = " << b << std::endl; //这里修改了

    int *p = nullptr;
    p = a > b ? &a : &b;
    std::cout << "&a: " << &a << ", &b: " << &b << ", p: " << p << std::endl;

    *(a < b ? &a : &b) = 33;
    std::cout << "a = " << a << ", b = " << b << std::endl;

    int c = 2;
    decltype(a < b ? a : b) d = c;    //这里d是个引用
    decltype((a < b ? a : b)) dd = c; //显然引用

    auto e = a < b ? a : b;   //int
    auto f = (a < b ? a : b); //int

    std::cout << (a < b ? "min is a" : "min is b") << std::endl; //输出时用条件运算符，记得加括号！
    return 0;
}
