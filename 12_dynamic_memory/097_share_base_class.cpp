//某个类，多个类对象需要共享相同的底层数据
//也就是类分配的资源对于实例对象来说，有独立的生存周期
//也就是说，销毁某个实例对象时，不能单方面地销毁底层数据
#include <memory>
#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>
#include "097_share_base_class.hpp"

int main(int argc, char const *argv[])
{
    StrBlob sb1;
scope_1:
{
    StrBlob sb2{"a", "b", "c"};
    sb1 = sb2;
    sb2.push_back("d");
}
    std::cout << "sb1.size(): " << sb1.size() << std::endl;

    return 0;
}
