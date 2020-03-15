/*
    小明对类似于 hello 这种单词非常感兴趣，这种单词可以正好分为四段，第一段由一个或多个辅音字母组成，第二段由一个或多个元音字母组成，第三段由一个或多个辅音字母组成，第四段由一个或多个元音字母组成。
　　给定一个单词，请判断这个单词是否也是这种单词，如果是请输出yes，否则请输出no。
 */

#include <iostream>
#include <string>

int main(int argc, char **argv)
{
    std::string s;
    std::cin >> s;
    std::string a, b, c, d;
    int i = 0;
    for (i = 0; i < s.size(); ++i)
    {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
            break;
        else
            a += s[i];
    }
    for (i; i < s.size(); ++i)
    {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
            b += s[i];
        else
            break;
    }
    for (i; i < s.size(); ++i)
    {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
            break;
        else
            c += s[i];
    }
    for (i; i < s.size(); ++i)
    {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
            d += s[i];
        else
            break;
    }
    if (a.empty() || b.empty() || c.empty() || d.empty())
        std::cout << "no";
    else if (a + b + c + d == s)
        std::cout << "yes";
    else
        std::cout << "no";
    return 0;
}
