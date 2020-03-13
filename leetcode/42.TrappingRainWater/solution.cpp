#include <iostream>
#include <vector>

int trap(std::vector<int> &height)
{
    if (height.empty())
        return 0;
    int ans = 0;
    int n = height.size();
    for (int i = 1; i != n; ++i)
    {
        int max_left = 0;
        int max_right = 0;
        for (int j = i; j >= 0; --j)
            max_left = std::max(max_left, height[j]);
        for (int j = i; j != n; ++j)
            max_right = std::max(max_right, height[j]);
        ans += std::min(max_right, max_left) - height[i];
    }
    return ans;
}

int trap(std::vector<int> &height)
{
    if (height.empty())
        return 0;
    int ans = 0;
    int n = height.size();
    std::vector<int> max_left(n);
    std::vector<int> max_right(n);

    max_left[0] = height[0];
    for (int i = 1; i != n; ++i)
        max_left[i] = std::max(max_left[i - 1], height[i]);

    max_right[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; --i)
        max_right[i] = std::max(max_right[i + 1], height[i]);

    for (int i = 1; i != n; ++i)
        ans += std::min(max_left[i], max_right[i]) - height[i];
    return ans;
}

int trap(std::vector<int> &height)
{
    if(height.empty())
        return 0;
    int left = 0;
    int right = height.size() - 1;
    int max_left = 0;
    int max_right = 0;
    int ans = 0;

    while (left < right)
    {
        if(height[left] < height[right])
        {
            if (height[left] > max_left)
                max_left = height[left];
            else
                ans += max_left - height[left];
            left += 1;
        }
        else
        {
            if(height[right] > max_right)
                max_right = height[right];
            else
                ans += max_right - height[right];
            right -= 1;
        }
    }
    return ans;
}
