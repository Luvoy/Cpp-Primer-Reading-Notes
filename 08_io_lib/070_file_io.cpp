#include <fstream>
#include <iostream>
#include <vector>
//ifstream和ofstream都是fstream的子类
int main(int argc, char const *argv[])
{
    std::fstream f1;
    std::fstream f2("./070_file_io_test.txt"); //这种构造函数，自带open，文件模式取决于fstream的类型

    std::cout << "f2.is_open(): " << f2.is_open() << std::endl;

    std::cout << "f2.bad() is " << f2.bad() << std::endl;
    std::cout << "f2.fail() is " << f2.fail() << std::endl;
    std::cout << "f2.eof() is " << f2.eof() << std::endl;
    std::cout << "f2.good() is " << f2.good() << std::endl;

    f2.close();
    f2.open(argv[1]);
    std::cout << "f2.is_open(): " << f2.is_open() << std::endl;
    f2.close();

    //文件模式file mode
    //in读
    //out写
    //app每次写操作前定位到文件末尾
    //ate打开文件直接定位到文件末尾
    //trunc截断文件
    //binary二进制方式进行io
    std::ifstream f3("./070_file_io_test_1.txt", std::ifstream::in);
    std::cout << "f3.is_open(): " << f3.is_open() << std::endl;

    std::ofstream f4("./070_file_io_test_2.txt", std::ofstream::out);
    //只有ofstream或者fstream可以设定out
    //只有ifstream或者fstream可以设定in
    //out默认是trunc
    std::vector<std::string> v1;
    while (!(f3.eof()))
    {
        std::string s;
        f3 >> s;
        v1.push_back(s);
        f4 << s << std::endl;
    }

    for (const auto &s : v1)
    {
        std::cout << s << std::endl;
    }
    f3.close();
    f4.close();
    std::fstream f5("./070_file_io_test_2.txt", std::fstream::out | std::fstream::app);
    f5 << "Fooooooooooooo";
    f5 << "Baaaaaaaaaaaar";
    f5 << std::endl;
    f5.close();
    std::fstream f6("./070_file_io_test_3.txt", std::fstream::out | std::fstream::ate);
    f6 << "HHHHHH" << std::endl;
    //app和ate区别：https://blog.csdn.net/qwezhaohaihong/article/details/51559455
    return 0;
}
