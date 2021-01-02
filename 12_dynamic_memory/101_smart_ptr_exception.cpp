//智能指针和异常处理
#include <iostream>
#include <memory>
#include <string>
#include <stdexcept>
class Connection
{
    friend Connection connect(std::string, unsigned);
    friend void disconnect(Connection *);

public:
    Connection() = default;

private:
    Connection(std::string s, unsigned u) : ip(s), port(u){};
    std::string ip = "0.0.0.0";
    unsigned port = 0;
};

Connection connect(std::string ip, unsigned port)
{
    return Connection(ip, port);
}

void disconnect(Connection *p)
{
    std::cout << "disconnect " << p->ip << ":" << p->port << std::endl;
}

void run()
{
    Connection c = connect("185.76.76.76", 8778);
    throw std::runtime_error("Unknow error");
    disconnect(&c);
}

void run_smart_ptr()
{
    Connection c = connect("192.168.1.1", 6666);
    std::shared_ptr<Connection> p(&c, disconnect); //可以使用自己定义的释放操作

    throw std::runtime_error("Unknow error");
    //如果单纯用new/delete，不用智能指针，抛出异常时，程序不能自己释放资源的
}

int main(int argc, char const *argv[])
{
    try
    {
        run();
    }
    catch (std::exception e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        run_smart_ptr();
    }
    catch (std::exception e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
