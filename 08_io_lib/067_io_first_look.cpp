//io类
#include <iostream> //读写流，包括istream,wistream, ostream, wostream, iostream, wiostream
#include <sstream>  //读写内存字符串， 包括istringstream,wistringstream,
                    //ostringstream, wostringstream, stringstream,wstringstream
#include <fstream>  //读写文件，包括ifstream, wifstream, ofstream, wofstream, fstream, ofstream

//默认的都是处理char类型，w开头处理wchar_t类型
//ifstream和istringstream都继承自istream

int main(int argc, char const *argv[])
{

    std::ofstream o1, o2;
    // o1 = o2; //不能赋值
    // std::ofstream o3(o2);//不能拷贝构造
    int i1 = 0;
    std::cin >> i1;
    auto state_1 = std::cin.rdstate(); //它返回的类型是std::ios_base::iostate
    //std::ios_base是父类，std::basic_ios是子类
    // typedef basic_ios<char> ios;
    std::cout << "std::cin.rdstate() is " << state_1 << std::endl;
    std::cout << "i1 = " << i1 << std::endl; //一个io操作失败，并不会给i1写入值

    auto a1 = std::ios_base::badbit;  //类型是std::ios_base::iostate, 流崩溃，不可恢复
    auto a2 = std::ios_base::failbit; //类型是std::ios_base::iostate，IO操作失败，可恢复
    auto a3 = std::ios_base::eofbit;  //类型是std::ios_base::iostate, 流到达文件结束
    auto a4 = std::ios_base::goodbit; //类型是std::ios_base::iostate，流未处于错误状态

    std::cout << "std::ios_base::badbit is " << std::ios_base::badbit << std::endl;
    std::cout << "std::ios_base::failbit is " << std::ios_base::failbit << std::endl;
    std::cout << "std::ios_base::eofbit is " << std::ios_base::eofbit << std::endl;
    std::cout << "std::ios_base::goodbit is " << std::ios_base::goodbit << std::endl;

    std::cout << "std::cin.badbit is " << std::cin.badbit << std::endl;
    std::cout << "std::cin.failbit is " << std::cin.failbit << std::endl;
    std::cout << "std::cin.eofbit is " << std::cin.eofbit << std::endl;
    std::cout << "std::cin.goodbit is " << std::cin.goodbit << std::endl;

    std::cout << "std::cin.bad() is " << std::cin.bad() << std::endl;
    std::cout << "std::cin.fail() is " << std::cin.fail() << std::endl;
    std::cout << "std::cin.eof() is " << std::cin.eof() << std::endl;
    std::cout << "std::cin.good() is " << std::cin.good() << std::endl;

    std::cin.clear(); //将流中的所有条件状态复位，设置为有效
    std::cout << "after clear, cin:" << std::endl;
    std::cout << "std::cin.bad() is " << std::cin.bad() << std::endl;
    std::cout << "std::cin.fail() is " << std::cin.fail() << std::endl;
    std::cout << "std::cin.eof() is " << std::cin.eof() << std::endl;
    std::cout << "std::cin.good() is " << std::cin.good() << std::endl;

    std::cin.setstate(std::ios_base::badbit | std::ios_base::eofbit); //手动设置标志位
    std::cout << "after set, cin:" << std::endl;
    std::cout << "std::cin.bad() is " << std::cin.bad() << std::endl;
    std::cout << "std::cin.fail() is " << std::cin.fail() << std::endl;
    std::cout << "std::cin.eof() is " << std::cin.eof() << std::endl;
    std::cout << "std::cin.good() is " << std::cin.good() << std::endl;
    //bad, fail, eof任意一个置位，good都会失败

    std::cin.clear(std::cin.rdstate() & ~std::cin.failbit & ~std::cin.badbit); //也可以只清除特定的
    std::cout << "atfer clear some special, cin:" << std::endl;
    std::cout << "std::cin.bad() is " << std::cin.bad() << std::endl;
    std::cout << "std::cin.fail() is " << std::cin.fail() << std::endl;
    std::cout << "std::cin.eof() is " << std::cin.eof() << std::endl;
    std::cout << "std::cin.good() is " << std::cin.good() << std::endl;
    return 0;
}
