### 27. Remove Element

和前面那个题类似，区别就是前面那个题第一个元素不需要比较，而此题需要比较

```
int removeElement(std::vector<int> &nums, int val)
{
    int i = 0;
    for (int j = 1; j != nums.size(); ++j)
    {
        if (nums[j] != val)
        {
            nums[i] = nums[j];
            i += 1;
        }
    }
    return i;
}
```
