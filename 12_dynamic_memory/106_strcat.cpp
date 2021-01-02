//练习12.23
//连接两个const char *，返回动态的char数组

#include <new>
#include <string>
char *my_strcat(const char *s1, const char *s2)
{ //caller should delete
    size_t len_1 = 0, len_2 = 0;
    for (; *(s1 + len_1); ++len_1)
        ;
    for (; *(s2 + len_2); ++len_2)
        ;
    char *ret = new char[len_1 + len_2];
    for (size_t i = 0; i < len_1; ++i)
        *(ret + i) = *(s1 + i);
    for (size_t i = 0; i < len_2; ++i)
        *(ret + len_1 + i) = *(s2 + i);
    return ret;
}

#include <iostream>
int main(int argc, char const *argv[])
{
    const char *s1 = "Hello";
    const char *s2 = "World";
    char *s3 = my_strcat(s1, s2);
    std::cout << s3 << std::endl;
    delete[] s3;

    return 0;
}
