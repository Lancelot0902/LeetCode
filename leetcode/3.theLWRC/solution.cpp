#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string>
/*
int lengthOfLongestSubstring(std::string s)
{
    if(s.size() == 0)
        return 0;
    int max = 0;
    std::vector<char> ref;
    int i = 0;
    int begin = 1;
    while(i != s.size())
    {
        if(find(ref.begin(),ref.end(),s[i]) == ref.end())
        {
            ref.push_back(s[i]);
            if(ref.size() > max)
                max = ref.size();
            i += 1;
        }
        else
        {
            ref.clear();
            i = begin;
            begin += 1;
        }
    }
    return max;
}*/

/*
int lengthOfLongestSubstring(std::string s)
{
    int ans = 0;
    std::vector<char> temp;
    int i = 0;
    int j = 0;
    while (i != s.size() && j != s.size())
    {
        if (find(temp.begin(), temp.end(), s[j]) == temp.end())
        {
            temp.push_back(s[j++]);
            ans = temp.size() > ans ? temp.size() : ans;
        }
        else
        {
            temp.erase(temp.begin());
            i++;
        }
    }
    return ans;
}*/

int lengthOfLongestSubstring(std::string s)
{
    if (s.size() < 2)
        return s.size();
    std::map<char, int> temp;
    std::vector<char> dp(s.size(), -1);
    int max = 0;
    dp[0] = 1;
    temp[s[0]] = 0;
    for (int i = 1; i != s.size(); ++i)
    {
        if (temp.find(s[i]) != temp.end())
        {
            if (dp[i - 1] < i - temp[s[i]])
            {
                dp[i] = dp[i - 1] + 1;
            }
            else
            {
                dp[i] = i - temp[s[i]];
            }
        }
        else
        {
            dp[i] = dp[i - 1] + 1;
        }
        max = dp[i] > max ? dp[i] : max;
        temp[s[i]] = i;
    }
    return max;
}
