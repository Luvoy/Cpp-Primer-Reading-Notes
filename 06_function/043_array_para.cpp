//数组形参
#include <iostream>
#include <iterator>
void f1(int a[])
{
    // for (auto i = std::begin(a); i != std::end(a); ++i)
    //指针作为形参时,在函数内，std::begin(container)算不出的
    //三种传指针确定界限的方式：
    //1.c风格字符串，'\0'结尾
    //2.利用标准库传递首元素指针和尾元素指针
    //3.再传一个形参表示数组大小
}
void f2(int *a)
{
}
void f3(int a[10])
{
    //期望有10个，实际上不一定
}
//这三种方式是一样的

//
//传递多维数组
//多维数组其实是数组的数组
//数组名就是首个元素的指针，也就是指向数组的指针
//因此传递数组名时，数组第2维和后面所有的维度，都不能省略长度
void f4(int (*a)[10]) //相当于int a[][10]
{
}

void f5(int a[][10][2][3])
{
}

void f6(int (*a)[10][2][3])
{
}
int main(int argc, char const *argv[])
{

    return 0;
}
