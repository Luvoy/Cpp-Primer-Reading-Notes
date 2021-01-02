//istringstream,ostringstream, stringstream
//内存io，向string读写数据
#include <sstream>
#include <string>
#include <vector>
class PersonInfo
{
public:
    PersonInfo() = default;

    std::string name;
    std::vector<std::string> tels;

    void print_one_person(std::ostream &os) const
    {
        os << "name: " << name;
        if (!tels.empty())
        {
            os << ", tels: ";
            for (const auto &i : tels)
            {
                os << i << ", ";
            }
        }
    }
};
#include <iostream>
int main(int argc, char const *argv[])
{
    //创建类对象，并且用istringstream把输入中的数据读到对象中
    //也就是数据->内存
    std::vector<PersonInfo> person_info_vector_1;
    std::string line;
    std::istringstream iss;
    while (std::getline(std::cin, line))
    {
        PersonInfo p;
        // std::istringstream iss(line); //将字符串绑定到istringstream对象
        iss.clear();
        iss.str(line);
        iss >> p.name;
        std::string word;
        while (iss >> word)
            p.tels.push_back(word); //不定个数，用这种方式可以一直读取，istream的特性就是空格算一次

        person_info_vector_1.push_back(p);
    }

    for (const auto &i : person_info_vector_1)
    {
        i.print_one_person(std::cout);
        std::cout << std::endl;
    }

    return 0;
}
