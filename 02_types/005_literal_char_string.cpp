//字符/字符串的字面常量量
//TODO
#include <iostream>
#include <locale>
int main(int argc, char const *argv[])
{
    std::string str1 = u8"我爱你I love you"; //utf8, 单个是char类型, 用8位编码一个unicode字符, 仅适用于字符串字面常量
    char16_t c1 = u'我';                     // unicode16, char16_t类型
    char32_t c2 = U'我';                     // unicode32, char32_t类型
    wchar_t c3 = L'我';                      // 宽字符, wchar_t类型
    const char16_t *str2 = u"我爱你I love you";
    const char32_t *str3 = U"我爱你I love you";
    const wchar_t *str4 = L"我爱你I love you";

    std::cout << str1 << std::endl;
    std::cout << c1 << std::endl;
    std::cout << c2 << std::endl;
    std::cout << c3 << std::endl;
    std::cout << str2 << std::endl;
    std::cout << str3 << std::endl;
    std::cout << str4 << std::endl;

    std::locale::global(std::locale(""));
    setlocale(LC_CTYPE, ""); // MinGW gcc.
    std::wcout.imbue(std::locale(""));
    // std::locale loc("");
    // std::locale loc("Chinese-simplified");
    //std::locale loc( "ZHI" );
    //std::locale loc( ".936" );
    // std::wcout.imbue(loc);

    std::wcout << str3 << std::endl;
    std::wcout << str4 << std::endl;
    std::wcout << str4 << std::endl;

    std::wstring str5 = L"我爱你I love you";
    std::wcout << c3 << std::endl;
    std::wcout << str5 << std::endl;
    return 0;
}
