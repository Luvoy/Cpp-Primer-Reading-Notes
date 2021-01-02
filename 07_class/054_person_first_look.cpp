#include <string>
struct Person
{
    std::string name;
    std::string address;
    unsigned short age;

    std::string get_name() const { return name; }
    std::string get_address() const { return address; }
    short get_age() const { return age; }
};
std::ostream &print(std::ostream &os, const Person &p)
{
    os << "name: " << p.name << ", address: " << p.address << ", age: " << p.age;
    return os;
}
#include <iostream>
std::istream &read(std::istream &is, Person &p)
{
    std::cout << "Please input an item of a person: name, address, age" << std::endl;
    is >> p.name >> p.address >> p.age;
    return is;
}
int main(int argc, char const *argv[])
{

    return 0;
}
