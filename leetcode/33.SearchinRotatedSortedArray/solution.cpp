#include <iostream>
#include <vector>

int binary(std::vector<int> &nums, int l, int r, int target)
{
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (nums[mid] == target)
            return mid;
        if (nums[mid] < target)
            l = mid + 1;
        if (nums[mid] > target)
            r = mid - 1;
    }
    return -1;
}

int pivot(std::vector<int> &nums)
{
    int l = 0;
    int r = nums.size();
    int mid = (l + r) / 2;
    while (l <= r)
    {
        if (nums[mid] > nums[0])
            if (nums[mid] > nums[mid + 1])
                return mid + 1;
            else
                l = mid + 1;
        if (nums[mid] < nums[0])
            if (nums[mid] < nums[mid - 1])
                return mid;
            else
                r = mid - 1;
    }
    return 0;
}

int search(std::vector<int> &nums, int target)
{
    if (target < nums.front() && target > nums.back())
        return -1;
    if (nums.front() < nums.back())
        return binary(nums, 0, nums.size(), target);
    int p = pivot(nums);
    if (target > nums.front())
        return binary(nums, 0, p - 1, target);
    else
        return binary(nums, p, nums.size() - 1, target);
}
