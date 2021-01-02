#include <iostream>
int f1(int &a)
{
    return ++a;
}
int f2(int &a)
{
    return ++a;
}
int f3(int &a)
{
    return ++a;
}
int f4(int &a)
{
    return ++a;
}
int main(int argc, char const *argv[])
{
    int a = 0;
    if (f1(a) && f2(a) && f3(a) == f4(a))

        printf("%d\n", a);
    return 0;
}
