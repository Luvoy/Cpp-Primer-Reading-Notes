//行为像值的类
//copy的时候, 不是copy指针, 而是copy指针指向的内容
#include <iostream>
#include <string>
#include <vector>
#include <memory>
class HasPtr
{
public:
    HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}
    HasPtr(const HasPtr &origin) : ps(new std::string(*(origin.ps))), i(origin.i) {}
    HasPtr &operator=(const HasPtr &origin)
    {                                               //赋值必须保证, a = a这种自身赋值也是没有问题的
        auto p_new = new std::string(*(origin.ps)); //先拷贝到局部
        delete ps;                                  //释放左边的, 也就是当前的
        ps = p_new;                                 //让左边的等于之前的
        i = origin.i;
        return *this;
    }
    ~HasPtr() { delete ps; }

private:
    int i;
    std::string *ps;
};
class StrBlobPtr;
class StrBlob
{
    friend class StrBlobPtr;

public:
    using blob_size_t = std::vector<std::string>::size_type;

    StrBlob() : data(std::make_shared<std::vector<std::string>>()) {}
    StrBlob(std::initializer_list<std::string> il) : data(std::make_shared<std::vector<std::string>>(il)) {}
    StrBlob(const StrBlob &origin) : data(std::make_shared<std::vector<std::string>>(*(origin.data))) {}
    StrBlob &operator=(const StrBlob &origin)
    {
        auto p_new = std::make_shared<std::vector<std::string>>(*(origin.data));
        }

    blob_size_t size() const
    {
        return data->size();
    }

    bool empty() const
    {
        return data->empty();
    }

    void push_back(const std::string &t)
    {
        data->push_back(t);
    }

    void pop_back()
    {
        check(0, "pop_back on empty StrBlob");
        return data->pop_back();
    }

    const std::string &front() const
    {
        check(0, "front on empty const StrBlob");
        return data->front();
    }

    const std::string &back() const
    {
        check(0, "back on empty const StrBlob");
        return data->back();
    }

    std::string &front()
    {
        check(0, "front on empty StrBlob");
        return data->front();
    }

    std::string &back()
    {
        check(0, "back on empty StrBlob");
        return data->back();
    }

    // StrBlobPtr begin()
    // {
    //     return StrBlobPtr(*this);
    // }

    // StrBlobPtr end()
    // {
    //     return StrBlobPtr(*this, data->size());
    // }

private:
    std::shared_ptr<std::vector<std::string>> data;
    void check(blob_size_t i, const std::string &msg) const
    {
        if (i >= data->size())
            throw std::out_of_range(msg);
    }
};

class StrBlobPtr
{
public:
    StrBlobPtr() : curr(0) {}
    StrBlobPtr(StrBlob &a, StrBlob::blob_size_t sz = 0) : wptr(a.data), curr(sz) {}

    std::string &deref() const //解引用*
    {
        auto p = check(curr, "deref out of range");
        return (*p)[curr];
    }

    StrBlobPtr &increase() //类似于++
    {
        check(curr, "increase at end");
        ++curr;
        return *this;
    }

private:
    std::weak_ptr<std::vector<std::string>> wptr;
    StrBlob::blob_size_t curr;

    std::shared_ptr<std::vector<std::string>> check(StrBlob::blob_size_t i, const std::string &msg) const
    {
        auto p = wptr.lock();
        if (!p)
            throw std::runtime_error("unbound StrBlobPtr");
        if (i >= p->size())
            throw std::out_of_range(msg);
        return p;
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}
