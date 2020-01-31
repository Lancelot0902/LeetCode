#include <iostream>
#include <map>
#include <string>

int romanToInt(std::string s)
{
    int ans = 0;
    std::map<char, int> map;
    map['I'] = 1, map['V'] = 5, map['X'] = 10, map['L'] = 50;
    map['C'] = 100, map['D'] = 500, map['M'] = 1000;
    for (int i = 0; i != s.size(); ++i)
    {
        if (s[i] == 'I' && i < s.size() - 1)
        {
            if (s[i + 1] == 'V')
            {
                ans += 4;
                i += 1;
            }
            else if (s[i + 1] == 'X')
            {
                ans += 9;
                i += 1;
            }
            else
                ans += map[s[i]];
            continue;
        }
        if (s[i] == 'X' && i < s.size() - 1)
        {
            if (s[i + 1] == 'L')
            {
                ans += 40;
                i += 1;
            }
            else if (s[i + 1] == 'C')
            {
                ans += 90;
                i += 1;
            }
            else
                ans += map[s[i]];
            continue;
        }
        if (s[i] == 'C' && i < s.size() - 1)
        {
            if (s[i + 1] == 'D')
            {
                ans += 400;
                i += 1;
            }
            else if (s[i + 1] == 'M')
            {
                ans += 900;
                i += 1;
            }
            else
                ans += map[s[i]];
            continue;
        }
        ans += map[s[i]];
    }
    return ans;
}