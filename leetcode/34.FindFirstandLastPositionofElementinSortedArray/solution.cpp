#include <iostream>
#include <vector>

void search(std::vector<int> &nums, std::vector<int> &ans, int l, int r, int target)
{
    if (l > r)
        return;
    int mid = (l + r) / 2;
    if (nums[mid] == target)
    {
        if (ans.empty())
            ans.push_back(mid);
        else if (mid < ans.front())
            ans.insert(mid, ans.begin());
        else if (mid > ans.back())
            ans.push_back(mid);
        search(nums, ans, l, mid - 1, target);
        search(nums, ans, mid + 1, r, target);
    }
    if (nums[mid] < target)
        search(nums, ans, mid + 1, r, target);
    if (nums[mid] > target)
        search(nums, ans, l, mid - 1, target);
}

std::vector<int> searchRange(std::vector<int> &nums, int target)
{
    std::vector<int> ans;
    search(nums, ans, 0, nums.size() - 1, target);
    if (ans.empty())
        return {-1, -1};
    else
        return {ans.front(), ans.back()};
}
