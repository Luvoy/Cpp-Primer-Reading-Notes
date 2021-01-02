//在switch内部定义变量会怎样
#include <iostream>
int main(int argc, char const *argv[])
{

    enum day
    {
        Monday,
        Tuesday,
        Wednesday,
        Thursday,
        Friday,
        Saturday,
        Sunday
    };
    day my_day = Wednesday;
    switch (my_day)
    {
    case Monday:
        // std::string s1;//错误，控制流绕过一个隐式初始化的变量
        // int i = 0;//错误，控制流绕过一个显式初始化的变量
        int j;
        static int k = 1;
        static int m;
        break;
    case Tuesday:
        // i++;
        // if (s1.empty())
        //     std::cout << "Empty str in Tuesday" << std::endl;
        ++j;
        ++m;
        ++k;
        break;
    case Wednesday:
        std::cout << "j = " << j << ", m = " << m << ", k = " << k << std::endl;
        //m被自动初始化为0，k有初始值，j野值

        break;
    case Thursday:
        //正确做法，如果确实要在case内定义变量
        //用{}括起来，并且各用各的
        {
            std::string s2;
            int ii = 0;
            int jj;
            static int kk = 1;
            static int mm;
            ii++;
            if (s2.empty())
                std::cout << "Empty str" << std::endl;
            jj = 3;
            ++mm;
            ++kk;
            std::cout << "jj = " << jj << ", mm = " << mm << ", kk = " << kk << std::endl;
        }
        break;
    case Friday:
    {
        // ii++;
        // if (s2.empty())
        //     std::cout << "Empty str" << std::endl;
        // ++jj;
        // ++mm;
        // ++kk;
        // std::cout << "jj = " << jj << ", mm = " << mm << ", kk = " << kk << std::endl;
        //这里再用就是not define了
    }
    break;
    case Saturday:
        break;
    case Sunday:
        break;
    default:
        break;
    }
    // std::cout << "j = " << j << ", m = " << m << ", k = " << k << std::endl;
    //在这个作用域内未定义jkm
    return 0;
}
