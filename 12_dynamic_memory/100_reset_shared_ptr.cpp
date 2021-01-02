#include <memory>
#include <iostream>
int main(int argc, char const *argv[])
{
    auto p1 = std::make_shared<int>(42);
    auto p2 = p1;

    std::cout << "p1.use_count(): " << p1.use_count() << std::endl;
    std::cout << "p2.use_count(): " << p2.use_count() << std::endl;

    p1.reset(new int(11));

    std::cout << "p1.use_count(): " << p1.use_count() << std::endl;
    std::cout << "p2.use_count(): " << p2.use_count() << std::endl;

    p2.reset();
    std::cout << "p1.use_count(): " << p1.use_count() << std::endl;
    std::cout << "p2.use_count(): " << p2.use_count() << std::endl;

    auto p3 = p1;
    if (!p1.unique())
        p1.reset(new int(13));
    *p1 += 1;
    std::cout << "*p1 = " << *p1 << ", *p3 = " << *p3 << std::endl;
    p3.reset();
    p1.reset();

    return 0;
}
