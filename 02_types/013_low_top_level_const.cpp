//顶层const和底层const
#include <iostream>
int main(int argc, char const *argv[])
{
    int i = 0;
    int *const p1 = &i;       //top-level const
    const int ci = 42;        //top-level const
    const int *p2 = &ci;      //low-level const
    const int *const p3 = p2; //low-level const + top-level const
    const int &r = ci;        //指向const引用都是low-level const

    int a = ci;
    a = r;
    p2 = p3;
    //将top的赋值给non-top的，可以

    const int b = i;
    //将non-top的赋值给top的，可以

    // int *p = p2; //low的赋值给non-low的，不可以
    p2 = p3; //low的赋值给low的，可以
    p2 = p1; //non-low的赋值给low的，可以
    // int &rr = r; //low的引用 去初始化non-low引用，不可以

    // int *p4 = &ci;//ci是顶层const，但是&ci是底层const，不能初始化非底层const
    return 0;
}
