### 11. Container With Most Water

解法1：暴力

```
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
```

时间复杂度：n<sup>2

----------------------------------------------

解法2：双指针

设置双指针 **i** , **j** 分别位于容器壁两端，根据规则移动指针（后续说明），并且更新面积最大值 res，直到 i == j 时返回 res

移动规则：

* 若height[i] < height[j]  则 i ++
* 若height[i] > height[i]  则 j - -

证明：

* 设每一状态下水槽面积为 **S(i, j)**,(0 <= i < j < n)(0<=i<j<n)，由于水槽的实际高度由两板中的短板决定，则可得面积公式 S(i, j) = min(h[i], h[j]) × (j - i)S(i,j)=min(h[i],h[j])×(j−i)

* 在每一个状态下，无论长板或短板收窄 1 格，都会导致水槽 底边宽度 -1

    * 若向内移动短板，水槽的短板 **min(h[i], h[j])** 可能变大，因此水槽面积 **S(i, j)** 可能增大

    * 若向内移动长板，水槽的短板 **min(h[i], h[j])** 不变或变小，下个水槽的面积一定小于当前水槽面积

https://leetcode-cn.com/problems/container-with-most-water/solution/container-with-most-water-shuang-zhi-zhen-fa-yi-do/

```
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
```
