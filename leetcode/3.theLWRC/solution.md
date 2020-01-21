### the longest substr without repeating

解法1：暴力

```
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
}

```
时间复杂度：n<sup>2 

空间复杂度：n

-------------------------------------

解法2：滑动窗口

与暴力法的思想差不多，不过在找到重复的时候没有直接舍弃之前得到的不重复的子串

所以在找到重复的时候要舍弃掉当前区间的首部即 [ i++, j ]；

```
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
}
```

-----------------------------

解法3：动态规划

字典temp记录s [ i ] 出现的位置

dp [ i ] 表示以s [ i ] 结尾的最长不重复子串的长度

dp [ i ] 和dp [ i-1 ]的关系
* s [ i ] 第一次出现 dp[ i ] = dp[ i - 1 ] + 1;
* s [ i ] 不是第一次出现
    * s [ i ] 出现在dp [ i-1 ] 维护的窗口中 dp[ i ] = dp[ i - 1 ] + 1;
    * s [ i ] 没有出现在dp [ i-1 ] 维护的窗口中 dp[ i ] = i - temp[ s[ i ] ];

```
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
```

时间复杂度 n

空间复杂度 n