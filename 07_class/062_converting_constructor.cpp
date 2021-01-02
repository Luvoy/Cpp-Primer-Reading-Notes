//转换构造函数：构造函数只接受一个实参，那么它定义了从形参类型转换成类类型的隐式转换机制
#include <string>
#include <vector>
#include <iostream>
class X
{
public:
    X() = default;
    X(std::string s) : contents(s){};
    X(int a, int b = 3) : i1(a), i2(b){};
    X(int a, int b, std::string s) : i1(a), i2(b), contents(s){};

    X &combine(const X &x_right)
    {
        i1 += x_right.i1;
        i2 += x_right.i2;
        return *this;
    }
    void show() const
    {
        std::cout << "i1 = " << i1 << ", i2 = " << i2 << ", contents = " << contents << std::endl;
    }

private:
    int i1 = 1;
    int i2 = 1;
    std::string contents;
};

class Y
{
public:
    Y() = default;
    Y(X x_para) : x_in_y(x_para){};

    X x_in_y;
    Y &combine(const Y &y_right)
    {
        x_in_y.combine(y_right.x_in_y);
        return *this;
    }
};

class Z
{
public:
    Z() = default;
    Z(Y y_para) : y_in_z(y_para){};

    Y y_in_z;
    Z &combine(const Z &z_right)
    {
        y_in_z.combine(z_right.y_in_z);
        return *this;
    }
};

int main(int argc, char const *argv[])
{
    X x1(3, 4, "Hello");
    std::string s1 = "World";
    x1.show();
    x1.combine(s1);
    x1.show();
    // x1.combine("World");//不允许两步转换

    Y y1(x1);
    y1.x_in_y.show();
    Y y2(s1); //可以
    // y1.combine(s1);//不可以，两步转换
    y1.combine(y2);
    y1.x_in_y.show();

    Z z1(x1);
    // Z z2(s1); //不可以，两步转换
    return 0;
}
