#include <iostream>
#include <vector>
/*double findMedianSortedArrays(std::vector<int> &nums1, std::vector<int> &nums2)
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
*/

double findMedianSortedArrays(std::vector<int> &nums1, std::vector<int> &nums2)
{
}

int main(int argc, char **argv)
{
    std::vector<int> num1{1, 3};
    std::vector<int> num2{2};
    std::cout << findMedianSortedArrays(num1, num2);
    system("pause");
    return 0;
}