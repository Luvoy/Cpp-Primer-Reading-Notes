//类中使用类型别名
//类中的mutable可变成员
//重载成员函数
//类中数据成员的初始值
#include <string>
#include <vector>
class Screen
{
    //这种带frien的友元的声明和定义是假的
    //要调用必须再单独声明一次
    friend class Window_mgr; //友元类，友元类的成员函数可以访问当前类的所有成员
    // friend void Window_mgr::clear(screen_index_t);//也可以声明其他类的成员函数作为友元函数
    //此时要注意顺序，先定义Window_mgr类，只声明clear函数，声明+定义Screen类，然后定义clear函数

public:
    using pos = std::string::size_type; //这个必须先定义后使用，跟成员属性和成员函数都不一样

    //构造函数
    Screen() = default;
    Screen(pos h, pos w, char c) : height(h), width(w), contents(w * h, c) {}
    Screen(pos h, pos w) : height(h), width(w) {}

    const char &get() const
    {
        call();
        return contents[cursor];
    }
    //成员函数也可以重载
    const char &get(pos row, pos col) const
    {
        call();
        return contents[row * width + col];
    }
    Screen &move(pos row, pos col)
    {
        call();
        cursor = row * width + col;
        return *this;
    }
    Screen &set(const char c)
    {
        call();
        contents[cursor] = c;
        return *this;
    }
    Screen &set(pos row, pos col, const char c)
    {
        call();
        contents[row * width + col] = c;
        return *this;
    }

    //const重载
    Screen &display(std::ostream &os)
    {
        call();
        private_display(os);
        return *this;
    }
    const Screen &display(std::ostream &os) const
    {
        call();
        private_display(os);
        return *this;
    }

    size_t show_call_count() const
    {
        return access_count;
    }

private:
    pos cursor = 0;
    pos height = 0;
    pos width = 0;
    std::string contents;
    mutable size_t access_count = 0; //可变数据成员，在const对象中，或者在const函数中，也可以修改

    void private_display(std::ostream &os) const
    {
        os << contents;
    }
    void call() const
    {
        ++access_count;
    }
};

class Window_mgr
{
public:
    Window_mgr() = default;
    using screen_index_t = std::vector<Screen>::size_type;
    void clear(screen_index_t i)
    {
        screen_vector[i].contents = std::string((screen_vector[i].height) * (screen_vector[i].width), ' ');
    }

private:
    std::vector<Screen> screen_vector{Screen(24, 40, ' '), Screen(10, 20)}; //初始化
};

#include <iostream>
int main(int argc, char const *argv[])
{
    Screen s1(5, 5, '*');
    s1.move(4, 0).set('#').display(std::cout);
    std::cout << std::endl;

    return 0;
}
