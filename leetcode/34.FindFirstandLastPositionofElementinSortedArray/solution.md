### 34. Find First and Last Position of Element in Sorted Array

本题在于对二分法的考察，我的算法是查找每一个target的位置，并加入到数组中，届时返回数组的头和尾

```
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

```

看了一下别人的二分，这篇文章讲的非常好，将二分讲的很透彻

[二分查找算法细节详解](https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/solution/er-fen-cha-zhao-suan-fa-xi-jie-xiang-jie-by-labula/#comment)
