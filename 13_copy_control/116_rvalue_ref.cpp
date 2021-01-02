//右值引用
//标准库容器，string，shared_ptr既可以拷贝，又可以移动
//IO类和unique_ptr仅支持移动

//右值引用，只能绑定到将要销毁的对象中
#include <utility>
#include <vector>
#include <iostream>
#include <ctime>
time_t f()
{
    return time(NULL);
}
int main(int argc, char const *argv[])
{
    auto &&r1 = f();
    std::vector<int> v(10);
    auto &r2 = v[0]; //容器的元素是个变量
    auto &r3 = r1;
    auto &&r4 = v[0] * f();
    return 0;
}
