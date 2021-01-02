//一般来说，需要析构函数的，一定需要拷贝构造和重载拷贝赋值运算
//需要拷贝构造的，也同时需要重载拷贝赋值运算符, 反之亦然
//需要拷贝构造的，不一定要析构
#include <iostream>
#include <ctime>

class Number1
{
public:
    int x;
    time_t unique_serial_number;
    Number1() : x(0) { unique_serial_number = time(0); }
    Number1(int i) : x(i) { unique_serial_number = time(0); };
    //使用合成的copy constructor和copy =
    ~Number1(){};
};
class Number2
{
public:
    int x;
    time_t unique_serial_number;
    Number2()
    {
        x = 0;
        unique_serial_number = time(0);
    }
    Number2(int i) : x(i)
    {
        unique_serial_number = time(0);
    }
    Number2(const Number1 &origin) : x(origin.x)
    {
        unique_serial_number = time(0);
    }
    Number2 &operator=(const Number2 &origin) = delete;
    {
        x = origin.x;
        unique_serial_number = time(0);
        return *this;
    }
    ~Number2(){};
};

void f1(Number1 n) { std::cout << "In nubmer1: " << n.unique_serial_number << std::endl; }
void f2(Number2 n) { std::cout << "In nubmer2: " << n.unique_serial_number << std::endl; }
void f11(const Number1 &n) { std::cout << "using const ref, In nubmer1: " << n.unique_serial_number << std::endl; }
void f22(const Number2 &n) { std::cout << "using const ref, In nubmer2: " << n.unique_serial_number << std::endl; }
void sleep(double t)
{
    clock_t total = t * CLOCKS_PER_SEC;
    clock_t start = clock();
    while (clock() - start < total)
        ;
}

int main(int argc, char const *argv[])
{

    Number1 n1;
    sleep(2.1);
    Number1 n2 = n1;
    sleep(1.8);
    Number1 n3 = n2;
    f1(n1); //这里也拷贝了
    f1(n2);
    f1(n3);
    f11(n1);
    f11(n2);
    f11(n3); //没有拷贝

    Number2 m1, m2, m3;
    sleep(2.1);
    // Number2 m2 = m1;//这种可能被编译器绕过拷贝
    m2 = m1;
    sleep(1.8);
    // Number2 m3 = m2;
    m3 = m2;
    f2(m1);
    f2(m2);
    f2(m3);
    f22(m1);
    f22(m2);
    f22(m3);

    return 0;
}
