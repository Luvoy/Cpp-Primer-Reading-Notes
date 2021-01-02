//auto
#include <iostream>
#include <typeinfo>
int main(int argc, char const *argv[])
{
    int a = 1;
    double b = 2.3;
    auto c = a + b;
    std::cout << "auto c (int a + double b) = " << c << ", its type: " << typeid(c).name() << std::endl;
    auto d = b + a;
    std::cout << "auto d (double b + int a) = " << d << ", its type: " << typeid(d).name() << std::endl;

    //auto与引用
    int &ref = a;
    auto ref2 = ref; //ref2是int
    std::cout << "ref2 = " << ref2 << ", its type: " << typeid(ref2).name() << std::endl;

    //auto与const
    //auto会忽略顶层const，保留底层const

    const int *p1 = &a;
    int *const p2 = &a;
    const int *const p3 = &a;
    int *p4 = &a;

    auto ap1 = p1;
    auto ap2 = p2;
    auto ap3 = p3;
    auto ap4 = p4;

    // *ap1 = 3;//错误，不能修改*ap1，底层const保留
    int temp = 3;
    ap2 = &temp; //顶层const去掉了，可以修改ap2
    std::cout << "typeid(p1).name() is " << typeid(p1).name() << std::endl;
    std::cout << "typeid(p2).name() is " << typeid(p2).name() << std::endl;
    std::cout << "typeid(p3).name() is " << typeid(p3).name() << std::endl;
    std::cout << "typeid(p4).name() is " << typeid(p4).name() << std::endl;
    std::cout << "typeid(ap1).name() is " << typeid(ap1).name() << std::endl;
    std::cout << "typeid(ap2).name() is " << typeid(ap2).name() << std::endl;
    std::cout << "typeid(ap3).name() is " << typeid(ap3).name() << std::endl;
    std::cout << "typeid(ap4).name() is " << typeid(ap4).name() << std::endl;

    //需要auto之后是顶层const，再加上即可
    const auto ap5 = p2;
    // ap5 = p3;
    std::cout << "typeid(ap5).name() is " << typeid(ap5).name() << std::endl; //这里为什么显示的是pi而不是kpi?

    //auto&
    const int &ref_test_c = 3;

    auto &ar1 = ref_test_c; //注意这里auto后面有个&，和之前不一样，这里可以理解为，保留了底层const
    // ar1 = 4;//错误，指向const的引用，不可修改

    auto &ar2 = a; //正确，ar2是int&
    // auto &ar3 = 42; //错误，不能用字面值初始化一个非指向const的引用，也就是这里用low去初始化non-low了
    const auto &ar4 = 42;

    std::cout << "typeid(ar1).name() is " << typeid(ar1).name() << std::endl;

    std::cout << "typeid(ar2).name() is " << typeid(ar2).name() << std::endl;
    std::cout << "typeid(ar4).name() is " << typeid(ar4).name() << std::endl;
    return 0;
}
