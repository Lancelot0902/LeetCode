#include <iostream>
#include <vector>

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
