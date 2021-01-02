//除法、取余运算碰上负数
//早期c++规定整数除法的结果四舍五入
//现在一律整除，切掉小数点后

//m、n是整数且n非0，那么(m/n)*n+m%n=m
//(-m)/n=m/(-n)=-(m/n)
// m%(-n) = m%n
// (-m)%n = -(m%n)
// (-m)%(-n) = -(m%(-n))=-(m%n)
#include <iostream>
int main(int argc, char const *argv[])
{
    std::cout << "21 % 6 = " << 21 % 6 << std::endl;
    std::cout << "-21 % 6 = " << -21 % 6 << std::endl;
    std::cout << "21 % -6 = " << 21 % -6 << std::endl;
    std::cout << "-21 % -6 = " << -21 % -6 << std::endl;
    return 0;
}
