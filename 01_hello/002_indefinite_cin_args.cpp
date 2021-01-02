//不定量的输入个数
//使用重定向: On Windows:
// 02.exe < 02_data.txt
// 或者: On Unix:
// 02.out < 02_data.txt
#include <iostream>
int main(int argc, char **argv)
{
    std::cout << argc << std::endl;
    std::cout << argv[0] << std::endl;
    std::cout << "Input some numbers and input EOF to finish: (On Windows, Ctrl+Z; On Unix, Ctrl+D)" << std::endl;
    int sum = 0;
    int v = 0;
    while (std::cin >> v)
    {
        sum += v;
    }
    std::cout << "Sum: " << sum << std::endl;
}