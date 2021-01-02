//指向const的引用
#include <iostream>
int main(int argc, char const *argv[])
{
    int a = 1;
    double b = 3.14;
    const int &ref1 = a;
    const int &ref2 = 1;
    const int &ref3 = a * 2; //对const的引用, 初始化允许使用任意变量
    const int &ref4 = b * 2; //相当于const int temp = b;然后const int &ref4 = temp;
    //恰好指向const的引用不能修改指向的变量的值, 所以可以用任意值初始化,
    //而且实际上相当于开辟了一个临时变量, 临时变量是不能修改的

    //c++不允许改变引用的指向. 所以引用itself都是const的,这里是指向const的引用, 是不能修改指向的变量的值
    //所以常常有人把指向const的引用叫做常量引用

    int &aa = a; //虽然ref1是不能用来修改a的值,但是aa仍然可以.
    return 0;
}
