#include <iostream>
#include "010_const_include.h"
// const int a; //ERROR,不能重复定义
extern const int b;
extern const int c;
int main(int argc, char const *argv[])
{
    func();

    std::cout << "In main():" << std::endl;
    std::cout << "a = " << a << ", &a = " << &a << std::endl;
    std::cout << "b = " << b << ", &b = " << &b << std::endl;
    std::cout << "c = " << c << ", &c = " << &c << std::endl;

    func();

    const int a = 3;
    std::cout << "In main(): redeclare a:" << std::endl;
    std::cout << "a = " << a << ", &a = " << &a << std::endl;

    func();
    return 0;
}
