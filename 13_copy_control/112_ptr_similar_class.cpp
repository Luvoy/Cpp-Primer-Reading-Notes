//copy行为像指针的类
#include <iostream>
#include <string>
#include <memory>
class HasPtr
{
public:
    HasPtr(const std::string &s = "") : ps(new std::string(s)), i(0), use_count(new size_t(1))
    {
    }

    HasPtr(const HasPtr &origin) : ps(origin.ps), i(origin.i), use_count(origin.use_count)
    {
        ++*use_count;
    }
    HasPtr &operator=(const HasPtr &origin)
    {
        ++*(origin.use_count);
        if (--*use_count == 0)
        {
            delete ps;
            delete use_count;
        }
        ps = origin.ps;
        i = origin.i;
        use_count = origin.use_count;
        return *this;
    }
    ~HasPtr()
    {
        if (--*use_count == 0)
        {
            delete ps;
            delete use_count;
        }
    }
    std::size_t get_use_count()
    {
        return *use_count;
    }

private:
    std::string *ps;
    int i;
    std::size_t *use_count;
};
int main(int argc, char const *argv[])
{
    auto a = HasPtr("a");
    std::cout << a.get_use_count() << std::endl;

    auto aa(a);
    std::cout << a.get_use_count() << std::endl;
    std::cout << aa.get_use_count() << std::endl;

    auto aaa = aa;
    std::cout << a.get_use_count() << std::endl;
    std::cout << aa.get_use_count() << std::endl;
    std::cout << aaa.get_use_count() << std::endl;
    return 0;
}
