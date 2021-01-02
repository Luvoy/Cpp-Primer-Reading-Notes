//weak_ptr需要绑定到shared_ptr上，并且不会改变shared_ptr的计数
//weak_ptr使用reset也不会真正释放指针，只是将weak_ptr置空
#include <iostream>
#include <memory>
int main(int argc, char const *argv[])
{
    // std::shared_ptr<int> p1 = std::make_shared<int>(42);
    std::shared_ptr<int> p1(new int(42));
    std::weak_ptr<int> w1 = p1;
    std::cout << "p1.use_count(): " << p1.use_count() << std::endl;
    std::cout << "w1.use_count(): " << w1.use_count() << std::endl;
    std::cout << "w1.expired(): " << w1.expired() << std::endl;
    if (w1.lock())
        std::cout << "w1.lock().get(): " << w1.lock().get() << ", *(w1.lock()): " << *(w1.lock()) << std::endl;

    p1.reset();
    std::cout << "after p1.reset(): " << std::endl;

    std::cout << "p1.use_count(): " << p1.use_count() << std::endl;
    std::cout << "w1.use_count(): " << w1.use_count() << std::endl;
    std::cout << "w1.expired(): " << w1.expired() << std::endl;
    if (w1.lock())
        std::cout << "w1.lock().get(): " << w1.lock().get() << ", *(w1.lock()): " << *(w1.lock()) << std::endl;
    if (p1)
        std::cout << "*p1: " << *p1 << std::endl;

    /////////////////////////////////////////////////////////////
    std::cout << "--------------------------------" << std::endl;
    /////////////////////////////////////////////////////////////

    std::shared_ptr<int> p2 = std::make_shared<int>(33);
    std::weak_ptr<int> w2(p2);
    std::cout << "p2.use_count(): " << p2.use_count() << std::endl;
    std::cout << "w2.use_count(): " << w2.use_count() << std::endl;
    std::cout << "w2.expired(): " << w2.expired() << std::endl;
    if (w2.lock())
        std::cout << "w2.lock().get(): " << w2.lock().get() << ", *(w2.lock()): " << *(w2.lock()) << std::endl;

    w2.reset();
    std::cout << "after w2.reset(): " << std::endl;

    std::cout << "p2.use_count(): " << p2.use_count() << std::endl;
    std::cout << "w2.use_count(): " << w2.use_count() << std::endl;
    std::cout << "w2.expired(): " << w2.expired() << std::endl;
    if (w2.lock())
        std::cout << "w2.lock().get(): " << w2.lock().get() << ", *(w2.lock()): " << *(w2.lock()) << std::endl;
    if (p2)
        std::cout << "*p2: " << *p2 << std::endl;
    return 0;
}
