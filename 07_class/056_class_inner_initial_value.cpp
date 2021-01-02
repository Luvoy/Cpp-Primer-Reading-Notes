//某些编译器不支持类内初始值
class Foo1
{

    Foo1();
    Foo1(int);

    int num;
};
Foo1() : num(0) {} //TODO  报错？
Foo1(int i) : num(i) {}

class Foo2
{

    Foo2() = default;
    Foo2(int i) : num(i) {}

    int num = 0;
};
int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
