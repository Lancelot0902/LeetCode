#include <iostream>
#include <string>
#include <vector>

std::string convert(std::string s, int numRows)
{
    std::vector<std::string> vec;
    std::string ans;
    vec.resize(numRows);
    int it = 0;
    bool direction = true;
    for (int i = 0; i != s.size(); ++i)
    {
        if (direction)
        {
            vec[it++] += s[i];
            if (it == numRows)
            {
                direction = false;
                it -= 2;
                continue;
            }
        }
        if (!direction)
        {
            vec[it--] += s[i];
            if (it == -1)
            {
                direction = true;
                it += 2;
                continue;
            }
        }
    }
    for (auto i : vec)
        ans += i;
    return ans;
}