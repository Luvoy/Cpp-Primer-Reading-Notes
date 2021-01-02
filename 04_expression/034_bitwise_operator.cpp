//位运算
//移位运算，如何处理符号位取决于机器，
//尽量对无符号类型进行移位
#include <iostream>
#include <bitset>
#include <limits>
#include <cstdint>
int main(int argc, char const *argv[])
{
    int a = 1;
    for (unsigned i = 1; i < sizeof(int) * 8; ++i)
    {
        a <<= 1;
        std::cout << "time: " << i << ", a: " << a << ", bin(a): " << std::bitset<8 * sizeof(int)>(a) << std::endl;
    }
    //其中，最后一次移动，1移到符号位，变成了负数

    //继续左移两次，观察溢出
    a <<= 1;
    std::cout << "overflow, a = " << a << ", bin(a): " << std::bitset<8 * sizeof(int)>(a) << std::endl; //0
    a <<= 1;
    std::cout << "overflow, a = " << a << ", bin(a): " << std::bitset<8 * sizeof(int)>(a) << std::endl; //0

    //单个的1右移，即将溢出
    a = 1;
    a >>= 1;
    std::cout << "a = 1, a>>=1, then a = " << a << ", bin(a): " << std::bitset<8 * sizeof(int)>(a) << std::endl;

    //负数
    a = (std::numeric_limits<int>::min)(); //10000...0000按照补码，其二进制的符号位为1，其余全0
    std::cout << "a: " << a << ", bin(a): " << std::bitset<8 * sizeof(int)>(a) << std::endl;
    a >>= 1; //这里右移补1
    std::cout << "a >> 1, then a  = " << a << ", bin(a): " << std::bitset<8 * sizeof(int)>(a) << std::endl;

    a = (std::numeric_limits<int>::min)(); //10000...0000按照补码，其二进制的符号位为1，其余全0
    std::cout << "a: " << a << ", bin(a): " << std::bitset<8 * sizeof(int)>(a) << std::endl;
    a <<= 1; //这里左移即将溢出
    std::cout << "a << 1, then a  = " << a << ", bin(a): " << std::bitset<8 * sizeof(int)>(a) << std::endl;

    a = (std::numeric_limits<int>::min)() + 1; //10000...0001符号位为1，末尾为1
    std::cout << "a: " << a << ", bin(a): " << std::bitset<8 * sizeof(int)>(a) << std::endl;
    a >>= 1; //仍然右移补1
    std::cout << "a >> 1, then a  = " << a << ", bin(a): " << std::bitset<8 * sizeof(int)>(a) << std::endl;

    a = (std::numeric_limits<int>::min)() + 1; //10000...0001符号位为1，末尾为1
    std::cout << "a: " << a << ", bin(a): " << std::bitset<8 * sizeof(int)>(a) << std::endl;
    a <<= 1; //即将溢出
    std::cout << "a << 1, then a  = " << a << ", bin(a): " << std::bitset<8 * sizeof(int)>(a) << std::endl;

    //小类型测试
    char c = 1;
    std::cout << "c: " << c << ", bin(c): " << std::bitset<8 * sizeof(char)>(c) << std::endl;
    auto c2 = c << 10;
    auto c3 = c << 2;
    std::cout << "c2 = c << 10 , then c2 = " << c2 << ", bin(c2): " << std::bitset<8 * sizeof(decltype(c2))>(c2) << std::endl;
    std::cout << "c3 = c << 2  , then c3 = " << c3 << ", bin(c3): " << std::bitset<8 * sizeof(decltype(c3))>(c3) << std::endl;
    //自动提升

    //取反
    //char类型会自动提升成int
    char c4 = (std::numeric_limits<char>::min)() + 1; //10000001，负的
    std::cout << "c4: " << c4 << ", bin(c4): " << std::bitset<8 * sizeof(char)>(c4) << std::endl;
    int i5 = c4;
    std::cout << "int i5 = c4, then i5 = " << i5 << ", bin(i5): " << std::bitset<8 * sizeof(int)>(i5) << std::endl;
    std::cout << "~i5 = " << ~i5 << ", bin(~i5): " << std::bitset<8 * sizeof(int)>(~i5) << std::endl;
    auto c5 = ~c4;
    std::cout << "c5 = ~c4, then c5 = " << c5 << ", bin(c5): " << std::bitset<8 * sizeof(decltype(c5))>(c5) << std::endl;
    //这里，提升int，然后全部取反，包括符号位

    char c6 = 1;
    std::cout << "c6: " << c6 << ", bin(c6): " << std::bitset<8 * sizeof(char)>(c6) << std::endl;
    auto c7 = ~c6;
    std::cout << "c7 = ~c6, then c7 = " << c7 << ", bin(c7): " << std::bitset<8 * sizeof(decltype(c7))>(c7) << std::endl;
    //这里，提升int，然后全部取反，包括符号位

    //按位与，或，异或差不多
    return 0;
}
