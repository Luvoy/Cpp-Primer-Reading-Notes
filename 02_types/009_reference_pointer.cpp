//指针的引用
//饮用不是一个变量/对象,所以没有指向引用 的指针
//但是有指针的引用
#include <iostream>
int main(int argc, char const *argv[])
{
    int a = 1;
    int *p_a;
    int *&ref_p_a = p_a; //这种复杂的, 从右往左读, 首先看到它是个引用
    ref_p_a = &a;
    std::cout << p_a << ": " << *ref_p_a << std::endl;

    return 0;
}
