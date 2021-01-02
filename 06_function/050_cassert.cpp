//assert和NDEBUG
#include <iostream>
#include <cassert>

//assert应仅用于因故障等因素导致的不该发生的情况
//不能取代if
int threshold = 5;
void func(int *p)
{
    assert(p != nullptr);

    int c = *p;
#ifndef NDEBUG
    if (c > threshold)
        std::cerr << "ERROR: value > threshold, in file: " << __FILE__ << ", at line: " << __LINE__ << ", compiled on " << __DATE__ << ", at " << __TIME__ << std::endl;
#endif
    std::cout << "c = " << c << std::endl;
}

#undef NDEBUG
int main(int argc, char const *argv[])
{
    int a = 6;
    int *p = &a;
    func(p);
    int *pp = nullptr;
    func(pp);
    return 0;
}
