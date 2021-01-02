//swap对于拷贝构造和赋值运算有很大的用处
//同时对于一些需要用到swap的算法，比如排序，如果类想支持这种算法，最好重写swap
#include <iostream>
#include <string>
#include <algorithm>
class HasPtr
{
    friend void swap(HasPtr &h1, HasPtr &h2);

public:
    HasPtr(const std::string &s = "") : ps(new std::string(s)), i(0), use_count(new size_t(1))
    {
    }

    HasPtr(const HasPtr &origin) : ps(origin.ps), i(origin.i), use_count(origin.use_count)
    {
        ++*use_count;
    }
    HasPtr &operator=(HasPtr origin) //这里不应该再用引用了, 是拷贝传值
    {
        swap(*this, origin);
        return *this;
        //已经销毁了origin
        //使用拷贝和交换实现赋值运算是excetional-safe的，并且满足a=a
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
void swap(HasPtr &h1, HasPtr &h2);
void swap(HasPtr &h1, HasPtr &h2)
{
    std::swap(h1.i, h2.i);
    std::swap(h1.ps, h2.ps);
    std::swap(h1.use_count, h2.use_count);
}
int main(int argc, char const *argv[])
{
    auto a = HasPtr("a");
    std::cout << a.get_use_count() << std::endl;

    auto aa(a);
    std::cout << a.get_use_count() << std::endl;
    std::cout << aa.get_use_count() << std::endl;

    HasPtr aaa;
    aaa = aa;
    std::cout << a.get_use_count() << std::endl;
    std::cout << aa.get_use_count() << std::endl;
    std::cout << aaa.get_use_count() << std::endl;
    return 0;
}
