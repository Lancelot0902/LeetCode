/*
    小明要组织一台晚会，总共准备了 n 个节目。然后晚会的时间有限，他只能最终选择其中的 m 个节目。
　　这 n 个节目是按照小明设想的顺序给定的，顺序不能改变。
　　小明发现，观众对于晚上的喜欢程度与前几个节目的好看程度有非常大的关系，他希望选出的第一个节目尽可能好看，在此前提下希望第二个节目尽可能好看，依次类推。
　　小明给每个节目定义了一个好看值，请你帮助小明选择出 m 个节目，满足他的要求。
 */

#include <iostream>
#include <algorithm>
#include <vector>

int main(int argc, char **argv)
{
    int n, m;
    std::cin >> n >> m;
    std::vector<int> nums;
    std::vector<int> ans;
    for (int i = 0; i != n; ++i)
    {
        int temp;
        std::cin >> temp;
        nums.push_back(temp);
    }
    for (int i = 0; i != m; ++i)
        ans.push_back(nums[i]);
    std::vector<int>::iterator it = std::min_element(ans.begin(), ans.end());
    for (int i = m; i != n; ++i)
    {
        if (*it < nums[i])
        {
            ans.erase(it);
            ans.push_back(nums[i]);
            it = std::min_element(ans.begin(), ans.end());
        }
    }
    for (int i = 0; i != m; ++i)
        std::cout << ans[i] << " ";
    return 0;
}
