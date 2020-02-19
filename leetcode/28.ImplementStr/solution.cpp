#include <iostream>
#include <string>

int strStr(std::string haystack, std::string needle)
{
    if (needle.empty())
        return 0;
    for (int i = 0; i != haystack.size(); ++i)
    {
        if (haystack[i] == needle[0])
        {
            if (haystack.substr(i, needle.size()) == needle)
                return i;
        }
    }
    return -1;
}
