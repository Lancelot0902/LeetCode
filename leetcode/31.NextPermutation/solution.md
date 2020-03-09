### 31. Next Permutation

这个题的算法还是挺有意思的

从右向左遍历找到 ```nums[i] > nums[i-1]``` 的 i-1 ，然后再向后遍历找到后面那些书中比 i-1 大的最小的数交换，然后再将后面那些数反序就可以了

```
void nextPermutation(std::vector<int> &nums)
{
    int i = 0;
    for (i = nums.size() - 1; i >= 1; --i)
    {
        if (nums[i] <= nums[i - 1])
            continue;
        else
        {
            int j = i;
            while (nums[j] > nums[i - 1] && j <= nums.size() - 1)
                j += 1;
            j -= 1;
            std::swap(nums[i - 1], nums[j]);
            std::sort(nums.begin() + i, nums.end());
            break;
        }
    }
    if (i == 0)
        std::sort(nums.begin(), nums.end());
    return;
}

```
