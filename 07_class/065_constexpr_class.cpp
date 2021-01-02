//字面值常量类
//数据成员都是字面值类型的聚合类
//或者：
//      数据成员全是字面值类型
//      至少一个constexpr构造函数
//      有初始值的数据成员：内置类型必须是常量表达式，类类型必须使用constexpr构造函数生成初始值
//      必须析构函数的默认定义
class Debug
{
public:
    constexpr Debug(bool b = true) : hw(b), io(b), other(b){}; //constexpr构造函数必须初始化所有成员
    constexpr Debug(bool h, bool i, bool o) : hw(h), io(i), other(o){};
    constexpr Debug(bool h, bool i) : Debug(h, i, false){}; //或者使用其他的constexpr构造函数

    constexpr bool any()
    {
        return hw || io || other;
    }

    void set_io(bool b) { io = b; };
    void set_hw(bool b) { hw = b; };
    void set_other(bool b) { other = b; };

private:
    bool hw;
    bool io;
    bool other;
};

int main(int argc, char const *argv[])
{
    constexpr Debug d1(false);
    const Debug d2(false, true);
    /* code */
    return 0;
}
