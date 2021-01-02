#include <iostream>
#include <vector>
#include <string>
int main(int argc, char const *argv[])
{
    //vector是模板而非类型
    //编译器根据模板创建类/函数的过程叫做实例化

    //vector<不能包括引用>
    std::vector<int> vi1 = {1, 2, 3}; //列表初始化
    std::vector<int> vi2(vi1);
    std::vector<int> vi3 = vi1;
    std::vector<int> vi4(10, -1); //10个-1
    // std::vector<std::string> vs1(vi1);//错误，类型不一致
    // std::vector<std::string> vs2("AAA", "BBB", "CCC"); //错误，列表初始化是{}，()代表构造函数，没有这种构造函数
    std::vector<std::string> vs3(3, "AAA");

    std::vector<int> vi5(10); //只指定数量是10个，每个初始化为默认的，也就是0
    //注意()和{}的区别！！！
    std::vector<std::string> vs4(10); //每个都是空的string对象，这种初始化要求类必须设定初始值

    std::vector<std::string> vs5{10, "hi"}; //类型不同，这里无法执行列表初始化，编译器转而执行默认值初始化，相当于(10, "hi")
    //尽量少用

    for (auto e : vs5)
    {
        // vs5.push_back("a");//遍历的时候不应该改变vector的容量
        std::cout << e << std::endl;
    }

    std::vector<int>::size_type vi1_size = vi1.size();
    std::vector<std::string>::size_type vs5_size = vs5.size();
    // std::vector::size_type t;//错误
    return 0;
}
