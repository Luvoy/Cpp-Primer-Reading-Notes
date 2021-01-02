#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <ostream>
#include <memory>
#include <map>
#include <set>

class QueryResult;
class TextQuery
{
    friend class QueryResult;

public:
    using line_num_t = std::vector<std::string>::size_type;
    TextQuery() = default;
    TextQuery(std::ifstream &ifs)
    {
        std::string line;
        while (std::getline(ifs, line))
        { //处理每一行
            sp->push_back(line);
            line_num_t n = sp->size() - 1;

            //将行拆分为很多单词
            std::istringstream iss(line);
            std::string word;
            while (iss >> word)
            {
                auto &mapped = word_line_map[word];
                if (!mapped) //首次是值初始化，mapped为空
                    mapped = std::make_shared<std::set<line_num_t>>();
                mapped->insert(n);
            }
        }
    }
    QueryResult query(const std::string &query_word) const
    {
        static std::shared_ptr<std::set<line_num_t>> nodata;
        auto loc_map_iter = word_line_map.find(query_word);
        if (loc_map_iter == word_line_map.end())
            return QueryResult(query_word, sp, nodata);
        else
            return QueryResult(query_word, sp, loc_map_iter->second);
    }

private:
    std::shared_ptr<std::vector<std::string>> sp;
    std::map<std::string, std::shared_ptr<std::set<line_num_t>>> word_line_map;
};

class QueryResult
{
    friend std::ostream &print(std::ostream &os, const QueryResult &qr);

public:
    QueryResult() = default;
    QueryResult(const std::string &s, std::shared_ptr<std::vector<std::string>> sp_f,
                std::shared_ptr<std::set<TextQuery::line_num_t>> sp_l) : query_word(s), sp_file(sp_f), sp_line(sp_l) {}

private:
    const std::string query_word;
    std::shared_ptr<std::vector<std::string>> sp_file;
    std::shared_ptr<std::set<TextQuery::line_num_t>> sp_line;
};

std::ostream &print(std::ostream &os, const QueryResult &qr)
{
    os << qr.query_word << " occurs " << qr.sp_line->size() << " time(s), " << std::endl;
    for (auto num : *(qr.sp_line))
    { //对于set里面每一个
        os << "\tline " << num + 1 << ": " << *(qr.sp_file->cbegin() + num) << std::endl;
        //                               spfile是智能指针，cbegin是vector的迭代器，加上偏移量再解引用是string
    }
    return os;
}

#include <iostream>
void run_query(std::ifstream &ifs)
{
    TextQuery tq(ifs);
    while (true)
    {
        std::cout << "Enter the word to find, EOF to quit" << std::endl;
        std::string query_word;
        if (!(std::cin >> query_word))
            break;
        print(std::cout, tq.query(query_word)) << std::endl;
    }
}

int main(int argc, char const *argv[])
{
    std::ifstream f("./108_text_query.txt", std::ifstream::in);
    run_query(f);
    return 0;
}
