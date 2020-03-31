#include <iostream>
#include <vector>
double findMedianSortedArrays(std::vector<int> &nums1, std::vector<int> &nums2)
{
    int m = nums1.size();
    int n = nums2.size();
    std::vector<int> temp;
    int i, j = 0;
    while (i != m && j != n)
    {
        if (nums1[i] <= nums2[j])
        {
            temp.push_back(nums1[i++]);
        }
        else
        {
            temp.push_back(nums2[j++]);
        }
    }
    if (i == m && j != n)
    {
        while (j != n)
            temp.push_back(nums2[j++]);
    }
    else if (i != m && j == n)
    {
        while (i != m)
            temp.push_back(nums1[i++]);
    }
    if ((m + n) % 2 == 0)
    {
        return (temp[(m + n) / 2] + temp[(m + n) / 2 - 1]) / 2;
    }
    else
    {
        return temp[(m + n) / 2];
    }
}
