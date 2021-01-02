#include <iostream>
//构造函数最好使用初始值列表
class ConstExample
{
public:
    // ConstExample() = default;//这个类的默认构造函数无法调用
    ConstExample() : i(0), ci(0), ref_i(i){};      //应该这样写，或者使用类初始值
    ConstExample(int a) : i(a), ci(a), ref_i(a){}; //用构造函数初始值列表是最吼的

    void show() const
    {
        std::cout << "i = " << i << ", ci =" << ci << ", ref_i = " << ref_i << std::endl;
    }

private:
    int i;
    const int ci;
    int &ref_i;
};
// ConstExample::ConstExample(int a)
// {
//     i = a;
//     ci = ii; //错误，const不能赋值
//     ri = i;  //引用没有初始化
// }

//
////////////////////////////////////////////////////////////////
//Example 2: 初始化顺序
class X
{
private:
    int i;
    int j;

public:
    X(int v) : j(v), i(j) {} //错误，初始化顺序和类中定义的顺序一致
    void show() const
    {
        std::cout << "i = " << i << ", j = " << j << std::endl;
    }
};

//
////////////////////////////////////////////////////////////////
//Example 3: 带默认实参的构造函数
class Y
{
private:
    int i = 0;
    int j = 0;
    int k = 0;

public:
    // Y(int a = 1) : i(a){}; //这句话也是默认构造函数了

    Y(int a, int b, int c = 888) : i(a), j(b), k(c){};
    // Y(int a = 1, int b = 2, int c = 3) : i(a), j(b), k(c){}; //这句就是默认构造函数了
    Y() = default;
    void show() const
    {
        std::cout << "i = " << i << ", j = " << j << ", k = " << k << std::endl;
    }
};
int main(int argc, char const *argv[])
{
    ConstExample ce1;
    ConstExample ce2(8);
    ce1.show();
    ce2.show();

    X x(1);
    x.show();

    Y y1;
    // Y y2(8);
    Y y3(12, 23);
    Y y4(333, 444, 555);
    y1.show();
    // y2.show();
    y3.show();
    y4.show();
    return 0;
}
