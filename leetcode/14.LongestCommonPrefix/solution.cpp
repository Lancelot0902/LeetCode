#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::string longestCommonPrefix(std::vector<std::string> &strs)
{
    std::sort(strs.begin(), strs.end(), [](std::string a, std::string b) -> bool { return a.size() < b.size(); });
    std::string res;
    if (strs.size() == 0)
        return res;
    if (strs.size() == 1)
        return strs[0];
    int num = 1;
    for (int i = 0; i != strs[0].size(); ++i)
    {
        for (int j = 1; j != strs.size(); ++j)
        {
            if (strs[0][i] == strs[j][i])
                num += 1;
        }
        if (num == strs.size())
        {
            res += strs[0][i];
            num = 1;
        }
        else
            break;
    }
    return res;
}
