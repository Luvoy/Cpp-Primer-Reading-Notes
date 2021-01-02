//智能指针 - shared_ptr
#include <memory>
#include <vector>
#include <string>
#include <iostream>
void f1(std::shared_ptr<int> p)
{
    std::cout << "in f1(), p.use_count(): " << p.use_count() << std::endl;
    if (p)
        std::cout << "in f1(), *p = " << *p << std::endl;
    return;
}

void f2(std::shared_ptr<int> &p)
{
    std::cout << "in f2(), p.use_count(): " << p.use_count() << std::endl;
    if (p)
        std::cout << "in f2(), *p = " << *p << std::endl;
    return;
}

std::shared_ptr<int> factory(int a)
{
    return std::make_shared<int>(a);
}

std::shared_ptr<int> f3(std::shared_ptr<int> &p)
{
    std::cout << "in f3(), p.use_count(): " << p.use_count() << std::endl;
    if (p)
        std::cout << "in f3(), *p = " << *p << std::endl;
    return p;
}

int main(int argc, char const *argv[])
{
    std::shared_ptr<std::string> p1;                                          //默认初始化的智能指针中保存着空指针
    std::shared_ptr<std::string> p2 = std::make_shared<std::string>();        //最安全的方法就是使用make_shared
    std::shared_ptr<std::string> p3 = std::make_shared<std::string>(10, 'a'); //括号内接收初始化参数，空则值初始化

    std::cout << "p3.unique(): " << p3.unique() << std::endl;
    std::cout << "p3.use_count(): " << p3.use_count() << std::endl;
    auto p4(p3);

    std::cout << "p3.unique(): " << p3.unique() << std::endl;
    std::cout << "p3.use_count(): " << p3.use_count() << std::endl;
    std::cout << "p4.unique(): " << p4.unique() << std::endl;
    std::cout << "p4.use_count(): " << p4.use_count() << std::endl;

    std::cout << "p2.unique(): " << p2.unique() << std::endl;
    std::cout << "p2.use_count(): " << p2.use_count() << std::endl;

    p2 = p3; //先递减p2的count， p2的count变成0，会释放p2指向的原来的对象，然后重新指向，此时p3 的计数会增加
    std::cout << "p2.unique(): " << p2.unique() << std::endl;
    std::cout << "p2.use_count(): " << p2.use_count() << std::endl;
    std::cout << "p3.unique(): " << p3.unique() << std::endl;
    std::cout << "p3.use_count(): " << p3.use_count() << std::endl;
    std::cout << "p4.unique(): " << p4.unique() << std::endl;
    std::cout << "p4.use_count(): " << p4.use_count() << std::endl;

    ////////////////////////////

    auto p5 = factory(111);
    std::cout << "int main, p5.use_count(): " << p5.use_count() << std::endl;

    f1(p5);
    std::cout << "in main, p5.use_count(): " << p5.use_count() << std::endl;
    f2(p5);
    std::cout << "in main, p5.use_count(): " << p5.use_count() << std::endl;
    //可见，拷贝一个shared_ptr会增加计数

    auto p6 = f3(p5);
    std::cout << "in main, p5.use_count(): " << p5.use_count() << std::endl;
    std::cout << "in main, p6.use_count(): " << p6.use_count() << std::endl;

    return 0;
}