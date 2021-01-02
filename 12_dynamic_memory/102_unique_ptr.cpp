//unique_ptr与shared_ptr不同，只有有一个unique_ptr指向一个对象
#include <memory>
#include <new>
#include <iostream>
void my_finalize(int *p)
{
    delete p;
};
int main(int argc, char const *argv[])
{
    //没有make_shared,需要使用new
    std::unique_ptr<int> p1(new int(42));

    // std::unique_ptr<int> p2(p1); //不支持拷贝，除非用作返回值时
    //std::unique_ptr<int> p3 = p1; //不支持赋值

    std::unique_ptr<int> p4(p1.release()); //p1放弃控制权并置空，转给p4
    std::cout << *p4 << std::endl;         //release并不会释放
    p4.reset(new int(32));                 //p4释放原控制对象，并重新控制一个32

    //注意release的时候必须用一个东西接受，否则无法释放
    //如果不用智能指针，就得自己释放

    //自己制定释放的办法
    std::unique_ptr<int, decltype(my_finalize) *>(new int(), my_finalize);
    return 0;
}
