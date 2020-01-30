#include <iostream>
#include <vector>

int maxArea(std::vector<int> &height)
{
    int res = 0;
    for (int i = 0; i < height.size() - 1; ++i)
    {
        for (int j = i + 1; j < height.size(); ++j)
        {
            if (height[i] < height[j])
            {
                if (height[i] * (j - i) > res)
                    res = height[i] * (j - i);
            }
            else
            {
                if (height[j] * (j - i) > res)
                    res = height[j] * (j - i);
            }
        }
    }
    return res;
}

int maxArea(std::vector<int> &height)
{
    int i = 0;
    int j = height.size() - 1;
    int ans = 0;
    while (i != j)
    {
        if (height[i] < height[j])
        {
            if (ans < height[i] * (j - i))
                ans = height[i] * (j - i);
            i += 1;
        }
        else
        {
            if (ans < height[j] * (j - i))
                ans = height[j] * (j - i);
            j -= 1;
        }
    }
    return ans;
}
