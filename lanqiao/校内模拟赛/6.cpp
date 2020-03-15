/*
    在数列 a[1], a[2], ..., a[n] 中，如果对于下标 i, j, k 满足 0<i<j<k<n+1 且 a[i]<a[j]<a[k]，则称 a[i], a[j], a[k] 为一组递增三元组，a[j]为递增三元组的中心。
　　给定一个数列，请问数列中有多少个元素可能是递增三元组的中心。
 */

#include <iostream>
#include <vector>

int main(int argc, char **argv)
{
    int n;
    std::cin >> n;
    std::vector<int> nums;
    for (int i = 0; i != n; ++i)
    {
        int temp;
        std::cin >> temp;
        nums.push_back(temp);
    }
    int sum = 0;
    for (int i = 1; i < n - 1; ++i)
    {
        int flag1 = 0;
        int flag2 = 0;
        for (int l = i - 1; l >= 0; --l)
        {
            if (nums[i] > nums[l])
            {
                flag1 = 1;
                break;
            }
        }
        if (flag1)
        {
            for (int r = i + 1; r < n; ++r)
            {
                if (nums[r] > nums[i])
                {
                    flag2 = 1;
                    break;
                }
            }
        }
        if (flag2)
            sum += 1;
    }
    std::cout << sum;
    return 0;
}
