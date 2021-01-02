//一次读取一行
#include <iostream>
#include <string>
int main(int argc, char const *argv[])
{
    //从输入流读取内容，遇到换行符结束，注意换行符确实被读入，但是string不存
    std::cout << "Input some words and input EOF to finish:"
                 " (On Windows, Ctrl+Z; On Unix, Ctrl+D)"
              << std::endl;
    std::string line;
    while (std::getline(std::cin, line))
    {
        std::cout << line << std::endl; //line没有换行，我们手动换行，并且刷新显示缓冲区
    }
    std::cout << "DONE" << std::endl;
}