//函数匹配
//候选函数(candidate function): 同名，且其声明在调用点可见（也就是作用域内）
//可行函数(viable function): 形参和调用实参数量相等，且类型相同或能转换
#include <iostream>
void f1()
{
    std::cout << "111" << std::endl;
}
void f1(int a)
{
    std::cout << "222" << std::endl;
}
void f1(int a, int b)
{
    std::cout << "333" << std::endl;
}
void f1(double a, double b = 3.14)
{
    std::cout << "444" << std::endl;
}

////////////////////

void f2(int a)
{
    std::cout << "555" << std::endl;
}
void f2(short a)
{
    std::cout << "666" << std::endl;
}

////////////////

void f3(long a)
{
    std::cout << "777" << std::endl;
}
void f3(double a)
{
    std::cout << "888" << std::endl;
}
int main(int argc, char const *argv[])
{
    f1(5.6);
    //4个f1都是候选函数
    //只有222和444是可行函数，222的可以double转int，444的有默认参数
    //精确匹配>类型转换，所以444

    // f1(42, 5.6);
    //333，444都可行，但是333的需要转型，444的也需要转型
    //ambiguous

    f2(1); //按int处理
    short a = 1;
    f2(a); //这样才按short处理

    // f3(1);//错误，转换成long跟double都是转换，不区分哪个转换更好
    return 0;
}

//summary:
//1.精确匹配：类型相同，数组名->指针，函数名->指针，添加/删除顶层const
//2.const转换
//3.类型提升
//4.算术类型转换/指针类型转换
//5.类转换