//new把内存分配和构造对象放在了一起，是一种浪费，并且没有默认构造函数不能使用new
#include <memory>
#include <random>
#include <string>
#include <vector>
#include <iostream>
int main(int argc, char const *argv[])
{
    std::allocator<std::string> a1;
    //分配内存
    auto const p = a1.allocate(10);

    std::uniform_int_distribution<unsigned> u('A', 'Z');
    std::default_random_engine e;

    //分配了才能构造
    for (size_t i = 0; i < 10; ++i)
    {
        a1.construct(p + i, u(e), static_cast<char>(u(e))); //对每一个都要构造，p+i
    }

    for (size_t i = 0; i < 10; ++i)
    {
        std::cout << *(p + i) << std::endl;
    }

    //构造了才能销毁
    for (size_t i = 0; i < 10; ++i)
    {
        a1.destroy(p + i);
    }
    //销毁之后可以重新构造

    //销毁了才能释放
    a1.deallocate(p, 10); //注意这个10必须和原来一样

    std::vector<int> v1 = {1, 2, 3, 4, 5, 6};
    std::allocator<int> a2;
    auto pp = a2.allocate(v1.size() * 2);
    auto ppp = std::uninitialized_copy(v1.cbegin(), v1.cend(), pp);
    auto pppp = std::uninitialized_fill_n(ppp, v1.size(), 42);

    for (size_t i = 0; i < v1.size() * 2; ++i)
    {
        std::cout << *(pp + i) << ", ";
    }
    std::cout << std::endl;

    for (size_t i = 0; i < v1.size() * 2; ++i)
    {
        a2.destroy(pp + i);
    }
    a2.deallocate(pp, v1.size() * 2);

    return 0;
}
