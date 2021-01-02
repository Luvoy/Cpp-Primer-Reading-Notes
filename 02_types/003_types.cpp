#include <iostream>
#include <limits>
#include <stdint.h>
//c++基本类型，长度，范围
int main(int argc, char const *argv[])
{
    std::cout << "type\t\t"
              << "size\t\t"
              << "min\t\t\t\t"
              << "max\t\t\t\t" << std::endl;
    std::cout << "bool\t\t"
              << sizeof(bool) << "\t\t"
              << (std::numeric_limits<bool>::min)() << "\t\t\t\t"
              << (std::numeric_limits<bool>::max)() << "\t\t\t\t" << std::endl;
    std::cout << "char\t\t"
              << sizeof(char) << "\t\t"
              << static_cast<long>((std::numeric_limits<char>::min)()) << "\t\t\t\t"
              << static_cast<long>((std::numeric_limits<char>::max)()) << "\t\t\t\t" << std::endl;
    std::cout << "wchar_t\t\t"
              << sizeof(wchar_t) << "\t\t"
              << static_cast<long>((std::numeric_limits<wchar_t>::min)()) << "\t\t\t\t"
              << static_cast<long>((std::numeric_limits<wchar_t>::max)()) << "\t\t\t\t" << std::endl;
    std::cout << "char16_t\t"
              << sizeof(char16_t) << "\t\t"
              << static_cast<long>((std::numeric_limits<char16_t>::min)()) << "\t\t\t\t"
              << static_cast<long>((std::numeric_limits<char16_t>::max)()) << "\t\t\t\t" << std::endl;
    std::cout << "char32_t\t"
              << sizeof(char32_t) << "\t\t"
              << static_cast<long long>((std::numeric_limits<char32_t>::min)()) << "\t\t\t\t"
              << static_cast<long long>((std::numeric_limits<char32_t>::max)()) << "\t\t\t\t" << std::endl;
    std::cout << "short\t\t"
              << sizeof(short) << "\t\t"
              << (std::numeric_limits<short>::min)() << "\t\t\t\t"
              << (std::numeric_limits<short>::max)() << "\t\t\t\t" << std::endl;
    std::cout << "int\t\t"
              << sizeof(int) << "\t\t"
              << (std::numeric_limits<int>::min)() << "\t\t\t\t"
              << (std::numeric_limits<int>::max)() << "\t\t\t\t" << std::endl;
    std::cout << "long\t\t"
              << sizeof(long) << "\t\t"
              << (std::numeric_limits<long>::min)() << "\t\t\t\t"
              << (std::numeric_limits<long>::max)() << "\t\t\t\t" << std::endl;
    std::cout << "long long\t"
              << sizeof(long long) << "\t\t"
              << (std::numeric_limits<long long>::min)() << "\t\t\t\t"
              << (std::numeric_limits<long long>::max)() << "\t\t\t\t" << std::endl;
    std::cout << "float\t\t"
              << sizeof(float) << "\t\t"
              << (std::numeric_limits<float>::min)() << "\t\t\t\t"
              << (std::numeric_limits<float>::max)() << "\t\t\t\t" << std::endl;
    std::cout << "double\t\t"
              << sizeof(double) << "\t\t"
              << (std::numeric_limits<double>::min)() << "\t\t\t\t"
              << (std::numeric_limits<double>::max)() << "\t\t\t\t" << std::endl;
    std::cout << "long double\t"
              << sizeof(long double) << "\t\t"
              << (std::numeric_limits<long double>::min)() << "\t\t\t\t"
              << (std::numeric_limits<long double>::max)() << "\t\t\t\t" << std::endl;
    return 0;
}
