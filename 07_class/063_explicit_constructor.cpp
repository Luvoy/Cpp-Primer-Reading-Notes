//抑制构造函数的隐式转换
#include <string>
#include <iostream>
class X
{
public:
    X() = default;
    X(int a, int b, const std::string &s) : i1(a), i2(b), contents(s){};
    explicit X(const std::string &s) : contents(s){};
    explicit X(std::istream &is); //仅声明

    void show() const
    {
        std::cout << "i1 = " << i1 << ", i2 = " << i2 << ", contents = " << contents << std::endl;
    }
    X &combine(const X &x_right)
    {
        i1 += x_right.i1;
        i2 += x_right.i2;
        return *this;
    }

private:
    int i1 = 1;
    int i2 = 2;
    std::string contents;
};

// explicit X::X(std::istream &is) //错误，explicit只能用于声明
X::X(std::istream &is)
{
    is >> i1 >> i2 >> contents;
}

int main(int argc, char const *argv[])
{
    std::string s1 = "Hello";
    X x1(s1);
    // X x2 = s1;//explicit的构造函数，不能拷贝初始化，只能直接初始化

    x1.show();

    // x1.combine(s1);//错误，禁止隐式转换

    x1.combine(X(s1)); //正确
    x1.show();

    x1.combine(static_cast<X>(s1)); //正确
    x1.show();
    return 0;
}
