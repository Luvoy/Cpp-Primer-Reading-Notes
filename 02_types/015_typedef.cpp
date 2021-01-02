//typedef的用法以及注意事项
//using关键字（c++11）
#include <iostream>
#include <typeinfo>
int main(int argc, char const *argv[])
{
    typedef int my_int;
    using my_double = double; //c++11
    my_double a = 1.3;
    my_int b = 2;
    std::cout << "a = " << a << ", b = " << b << std::endl;

    int c = 42;
    int d = 33;
    typedef int *my_intp;
    const my_intp p1 = &c;
    // p1 = &d; //错误，p1是不能修改的
    std::cout << "*p1 = " << *p1 << ", p1 = " << p1 << std::endl;
    *p1 = 45;
    std::cout << "atfer change, *p1 = " << *p1 << ", p1 = " << p1 << std::endl;

    //const一个typedef，是顶层const，不是下面这种！

    const int *p2;
    p2 = &c;
    std::cout << "p2 = &c, so p2 = " << p2 << std::endl;
    p2 = &d;
    std::cout << "p2 = &d, so p2 = " << p2 << std::endl;
    // *p2 = 34;//错误，*p2不可修改

    std::cout << "typeid(p1).name() is " << typeid(p1).name() << std::endl;
    std::cout << "typeid(p2).name() is " << typeid(p2).name() << std::endl;

    return 0;
}
