#include <iostream>

class AA
{

public:
    AA() = default;
    AA(int i1) : x(++i1), y(++i1), z(++i1)
    { //是按xyz定义的顺序，这里的顺序无效
        std::cout << "In AA constructor1: x = " << x << ", y = " << y << ", z = " << z << std::endl;
    }
    // AA(int &i1) : x(++i1), y(++i1), z(++i1)
    // {
    //     std::cout << "In AA constructor2: x = " << x << ", y = " << y << ", z = " << z << std::endl;
    // }
    AA(const AA &origin) : x(origin.x),
                           y(origin.y),
                           z(origin.z)
    {

        std::cout << "In AA copy constructor: I'm copying x class. x = " << x << ", y = " << y << ", z = " << z << std::endl;
    }
    AA &operator=(const AA &origin)
    {
        std::cout << "In AA copy operator: I'm coping a class." << std::endl;
        x = origin.x;
        y = origin.y;
        z = origin.z;
        return *this;
    }
    ~AA()
    {
        std::cout << "IN AA deconstructor: firstly excute function, then destroy members." << std::endl;
    }

private:
    int z;
    int y;
    int x;
};
class A
{
public:
    A() = default;
    // A(int i1) : x(++i1), y(++i1), z(++i1),aa(1)
    // {
    //     std::cout << "In A constructor1: x = " << x << ", y = " << y << ", z = " << z << std::endl;
    // }
    A(int &i1) : x(++i1), y(++i1), z(++i1), aa(i1)
    {
        std::cout << "In A constructor2: x = " << x << ", y = " << y << ", z = " << z << std::endl;
    }
    A(const A &origin) : aa(origin.aa),
                         x(origin.x),
                         y(origin.y),
                         z(origin.z)
    {
        std::cout << "In A copy constructor: I'm copying x class. x = " << x << ", y = " << y << ", z = " << z << std::endl;
    }
    A &operator=(const A &origin)
    {
        std::cout << "In A copy operator: I'm coping a class." << std::endl;
        x = origin.x;
        y = origin.y;
        z = origin.z;
        return *this;
    }
    ~A()
    {
        std::cout << "IN A deconstructor: firstly excute function, then destroy members." << std::endl;
    }

private:
    int z;
    int y;
    AA aa;
    int x;
};

void f1(const A *p, A a)
{
    A a1(*p), a2(a);
    return;
}

int main(int argc, char const *argv[])
{
    int i = 3;
    A *p;
scope_1:
{
    auto a1 = A(i);
    std::cout << "i = " << i << std::endl;
    p = new A(i);
    A &a_ref = a1;
}
    std::cout << "i = " << i << std::endl;
    auto c = *p;
    auto d = A(i);
    std::cout << "------------------" << std::endl;
    f1(p, d);
    std::cout << "------------------" << std::endl;
    delete p;
    return 0;
}
