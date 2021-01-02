#include <iostream>
#include <limits>
//unsigned和signed相互计算的结果
int main(int argc, char const *argv[])
{
    unsigned u1 = 10, u2 = 42;
    std::cout << u2 - u1 << std::endl;                                                                                                                                                                            //32
    std::cout << u1 - u2 << std::endl;                                                                                                                                                                            //4294967264 = 2^32-1-2^5+1
    std::cout << (1 + static_cast<unsigned long>((std::numeric_limits<unsigned>::max)())) << "%" << (10 - 42) << "=" << (static_cast<long>((std::numeric_limits<unsigned>::max)()) + 1) % (10 - 42) << std::endl; //

    int i1 = 10, i2 = 42;
    std::cout << i2 - i1 << std::endl; //32
    std::cout << i1 - i2 << std::endl; //-32

    std::cout << i1 - u1 << std::endl; //0
    std::cout << u1 - i1 << std::endl; //0

    std::cout << i1 - u2 << std::endl; //unsinged(-32) = 4294967264
    std::cout << u1 - i2 << std::endl; //unsigned(-32) = 4294967264
    return 0;
}
