//默认参数
//越频繁调用的默认参数放越后面
//建议把声明放在头文件中
#include <iostream>

//可以多次声明，但是同一作用域中，每多一次声明，默认的参数不能减少。（只能从后面往前增加，或者不变）
void set(int a, int aa, double b, char c = '#');

// void set(int a, int aa, double b, char c = '3'); //不能修改已有的，这将导致重复声明

// void set(int a, int aa, double b, char c); //不能减少默认形参

// void set(int a, int aa, double b = 3.14, char c = '#'); //正确，将以最新的为准
//TODO 这里报错了，和书上的不一样

int p1 = 1;
int p2 = 2;
int p3 = 3;
void print(int a = p1, int b = p2, int c = p3)
{
    std::cout << "a = " << a << ", b = " << b << ", c = " << c << std::endl;
}

int main(int argc, char const *argv[])
{
    // set(1, 2, 3);

    p1 = 4;     //改变了p1的值
    int p2 = 6; //重新声明定义p2，隐藏了外部的p2，但是print调用的是外部的p2
    print();    //a=4,b=2,c=3

    //p1,p2,p3在print函数声明所在的scope解析(寻找)，但是求值发生在print函数调用时
    return 0;
}
