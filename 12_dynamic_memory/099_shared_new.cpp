//shared_ptr和new结合使用
#include <new>
#include <memory>
#include <vector>
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
void not_accept_smart_ptr(const int *const p)
{
    std::cout << "I don't accept smart pointers, and I don't delete the ptr,"
                 "and I don't create new smart pointers. I just use the value, *p = "
              << *p << std::endl;
    //禁止delete这个p
    //禁止把这个p绑定给智能的
}
int main(int argc, char const *argv[])
{
    std::shared_ptr<int> p1(new int);

    std::cout << "p1.use_count(): " << p1.use_count() << std::endl; //1
    int i = *p1;
    std::cout << "p1.use_count(): " << p1.use_count() << std::endl; //1

    //shared_ptr的构造是explicit，只能直接初始化
    // std::shared_ptr<int> p2 = new int(1024);//错误

    int *p3 = new int(42);
    // f1(p3);//不能把int*转换成shared_ptr<int>
    f1(std::shared_ptr<int>(p3));  //这里执行完之后会自动释放，所以原来p3指向的东西已经没了
    std::cout << *p3 << std::endl; //!未定义行为

    //用shared_ptr接管内置类型指针，就不要再用原来的内置类型了

    std::shared_ptr<int> p4(new int(42));
    int *p_temp = p4.get();
    not_accept_smart_ptr(p_temp); //智能指针的get作用只有这时候用
    //禁止delete一个智能指针get的结果，禁止使用get的结果去创建新的智能指针

    return 0;
}
