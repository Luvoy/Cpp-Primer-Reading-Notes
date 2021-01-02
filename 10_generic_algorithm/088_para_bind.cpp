//参数绑定
//不用lambda，解决上一个问题，
//如何在一个vector<string>中，找到大于某个长度a的string有多少个呢？并打印
//按长度排序，然后用find_if，find_if接收一元谓词，元素本身已经占用了，没法传入长度a
//用法：
//  bind函数定义在头文件functional中
//  auto new_callable = bind(callable, arg_list);
//  arg_list中，_1, _2这些在std::placeholders::_1
//例如：
//  int f(a1,a2,a3,a4,a5);
//  auto g = bind(f, x, y, _2, z, _1);
//  g接受两个参数，
//  g(m, n) 等价于 f(x, y, n, z, m)
//  x,y,z拷贝过来，如果需要引用，可以使用ref或者cref函数
//  auto g = bind(f, ref(x), cref(y), _2, z, _1)； //x是引用，y是指向const的饮用，z还是拷贝

#include <functional>
#include <iostream>
int f1(int a1, int a2, int &a3, const int &a4, const int a5)
{
    return (++a1) + (++a2) + (++a3) + a4 + a5;
}
int f2(int &a1, int a2, int &a3, const int &a4, const int a5)
{ //值改变了参数int &a1
    return (++a1) + (++a2) + (++a3) + a4 + a5;
}

int main(int argc, char const *argv[])
{
    using namespace std::placeholders;
    int w = 0, x = 0, y = 0, z = 0;

    auto g1 = std::bind(f1, _1, w, x, y, z);
    int t1 = 0;
    std::cout << g1(t1) << std::endl; //3
    std::cout << t1 << std::endl;     //0
    std::cout << w << std::endl;      //0
    std::cout << x << std::endl;      //0

    auto g2 = std::bind(f2, _1, w, x, y, z);
    int t2 = 0;
    std::cout << g2(t2) << std::endl; //3
    std::cout << t2 << std::endl;     //1
    std::cout << w << std::endl;      //0
    std::cout << x << std::endl;      //0

    auto g3 = std::bind(f1, _1, std::ref(w), std::ref(x), y, z);
    int t3 = 0;
    std::cout << g3(t3) << std::endl; //3
    std::cout << t3 << std::endl;     //0
    std::cout << w << std::endl;      //0
    std::cout << x << std::endl;      //1
    //结论，对于_1这种，原函是啥，传过去就是啥.
    //对于其他已经绑定的参数，如果想用引用，必须原函数这个形参是引用，并且bind的时候加上std::ref(x)就好了
    
    return 0;
}
