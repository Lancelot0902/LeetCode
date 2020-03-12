#include <iostream>
#include <string>

std::string countAndSay(int n)
{
    if (n == 0 || n == 1)
        return "1";
    std::string s = "11";
    for (int i = 2; i != n; ++i)
    {
        char c = s[0];
        int num = 0;
        std::string str;
        for (int j = 0; j != s.size(); ++j)
        {
            if (s[j] == c)
            {
                num += 1;
            }
            else
            {
                str += std::to_string(num) + c;
                c = s[j];
                num = 1;
            }
            if (j == s.size() - 1)
                str += std::to_string(num) + c;
        }
        s = str;
    }
    return s;
}
