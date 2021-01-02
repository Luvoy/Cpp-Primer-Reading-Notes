//输入不确定数量的string
//可使用重定向：On Windows：
//019.exe < 019_data.txt
//Or on Unix:
//019.out < 019_data.txt
#include <iostream>
#include <string>
int main(int argc, char const *argv[])
{
    std::cout << "Input some words and input EOF to finish:"
                 " (On Windows, Ctrl+Z; On Unix, Ctrl+D)"
              << std::endl;
    std::string word;
    while (std::cin >> word)
    {
        std::cout << word << std::endl;
    }
    std::cout << "DONE" << std::endl;
    return 0;
}
