#include <set>
#include <string>
#include <iostream>
class Tag;
class Message
{
    friend class Tag;
    friend std::ostream &print_msg(std::ostream &os, const Message &m);

public:
    explicit Message(const std::string &s = "") : content(s)
    {
    }
    Message(const Message &origin_m);

    Message &operator=(const Message &right_m);

    ~Message();

    void add_to_tag(Tag &t);
    // void add_to_tags(std::initializer_list<Tag> il)
    // {//initializer_list中是常量，不能用常量去初始化非常量
    //     for (auto &i : il)
    //     {
    //         add_to_tag(i);
    //     }
    // }
    void rm_from_tag(Tag &t);

    std::string get_content()
    {
        return content;
    }

private:
    std::string content;
    std::set<Tag *> belong_tags;
};

class Tag
{
    friend class Message;
    friend std::ostream &print_tag(std::ostream &os, const Tag &t);

public:
    explicit Tag(const std::string &s = "") : tag_name(s)
    {
    }
    Tag(const Tag &origin_t) = delete;
    // : tag_name(origin_t.tag_name), include_msgs(origin_t.include_msgs)
    // {
    //     for (auto i : include_msgs)
    //         i->add_to_tag(*this);
    // }
    Tag &operator=(const Tag &right_t) = delete;
    // {
    //     for (auto i : include_msgs)
    //     {
    //         i->rm_from_tag(*this);
    //     }
    //     tag_name = right_t.tag_name;
    //     include_msgs = right_t.include_msgs;

    //     for (auto i : include_msgs)
    //     {
    //         i->add_to_tag(*this);
    //     }
    //     return *this;
    // }
    ~Tag()
    {
        for (auto i : include_msgs)
        {
            i->rm_from_tag(*this);
        }
    }
    void add_msg(Message *m)
    {
        include_msgs.insert(m);
    }
    void rm_msg(Message *m)
    {
        include_msgs.erase(m);
    }
    std::string get_tag_name()
    {
        return tag_name;
    }

private:
    std::string tag_name;
    std::set<Message *> include_msgs;
};

std::ostream &print_msg(std::ostream &os, const Message &m);
std::ostream &print_tag(std::ostream &os, const Tag &t);
Message::Message(const Message &origin_m) : content(origin_m.content), belong_tags(origin_m.belong_tags)
{
    for (auto i : origin_m.belong_tags)
    {
        i->add_msg(this);
    }
}
Message &Message::operator=(const Message &right_m)
{
    for (auto i : belong_tags) //对此条msg所属的tag中
        i->rm_msg(this);       //每个都删除此条msg
    content = right_m.content;
    belong_tags = right_m.belong_tags;

    for (auto i : right_m.belong_tags)
    {
        i->add_msg(this);
    }
    return *this;
}
Message::~Message()
{
    for (auto i : belong_tags) //对此条msg所属的tag中
        i->rm_msg(this);       //每个都删除此条msg
}
void Message::add_to_tag(Tag &t)
{
    belong_tags.insert(&t);
    t.add_msg(this);
}
void Message::rm_from_tag(Tag &t)
{
    belong_tags.erase(&t);
    t.rm_msg(this);
}
std::ostream &print_msg(std::ostream &os, const Message &m)
{
    os << "Message content: " << m.content << ", belongs to Tag(s): ";
    for (const auto i : m.belong_tags)
    {
        os << i->get_tag_name() << ", ";
    }
    os << std::endl;
    return os;
}

std::ostream &print_tag(std::ostream &os, const Tag &t)
{
    os << "****************************************" << std::endl;
    os << "Tag name: " << t.tag_name << ", includes message(s): " << std::endl;

    for (const auto i : t.include_msgs)
    {
        os << i->get_content() << std::endl;
    }
    os << "****************************************" << std::endl;
    return os;
}
int main(int argc, char const *argv[])
{
    Tag my_families("my_families");
    Tag my_friends("my_friends");
    Tag my_colleagues("my_colleagues");
    Tag my_classmates("my_classmates");
    Tag my_teachers("my_teachers");
    Tag my_boss("my_boss");

    Message m1("I love playing computer games.");
    Message m2("I love reading books.");
    Message m3("I love running.");
    Message m4("My monthly income is $3000");
    Message m5("I have a girlfriend");

    m1.add_to_tag(my_friends);
    m1.add_to_tag(my_classmates);

    m2.add_to_tag(my_families);
    m2.add_to_tag(my_colleagues);
    m2.add_to_tag(my_teachers);
    m2.add_to_tag(my_boss);

    m3.add_to_tag(my_friends);
    m3.add_to_tag(my_colleagues);
    m3.add_to_tag(my_boss);

    m4.add_to_tag(my_families);
    m4.add_to_tag(my_boss);

    m5.add_to_tag(my_friends);
    m5.add_to_tag(my_colleagues);
    m5.add_to_tag(my_classmates);

    print_msg(std::cout, m1);
    print_msg(std::cout, m2);
    print_msg(std::cout, m3);
    print_msg(std::cout, m4);
    print_msg(std::cout, m5);

    print_tag(std::cout, my_families);
    print_tag(std::cout, my_friends);
    print_tag(std::cout, my_colleagues);
    print_tag(std::cout, my_classmates);
    print_tag(std::cout, my_teachers);
    print_tag(std::cout, my_boss);

    Message m6;
    m6 = m1;

    print_msg(std::cout, m6);
    print_tag(std::cout, my_families);
    print_tag(std::cout, my_friends);
    print_tag(std::cout, my_colleagues);
    print_tag(std::cout, my_classmates);
    print_tag(std::cout, my_teachers);
    print_tag(std::cout, my_boss);

    return 0;
}
