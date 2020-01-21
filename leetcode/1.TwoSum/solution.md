### 1.TwoSum

解法1：暴力法
```
vector<int> twoSum(vector<int>& nums, int target) 
{
    std::vector<int> ans;
    for (int i = 0; i != nums.size(); ++i)
    {
        for (int j = i + 1; j != nums.size(); ++j)
        {
            if(nums[i] + nums[j] == target)
            {
                ans.push_back(i);
                ans.push_back(j);
            }
        }
    }
    return ans;
}
```
时间复杂度 n<sup>2

--------------------------------------------------------

解法2：two-pass  map

* 第一次遍历使用map保存每个数的下标
* 第二次遍历查找map

```
std::vector<int> twoSum(std::vector<int> &nums, int target)
{
    std::map<int, int> indices;
    std::vector<int> ans;
    for (int i = 0; i != nums.size();++i)
    {
        indices[nums[i]] = i;
    }
    for (int i = 0; i != nums.size();++i)
    {
        int temp = target - nums[i];
        if(indices.find(temp) != indices.end())
        {
            if(indices.at(temp) != i)
            {
                ans.push_back(i);
                ans.push_back(indices[temp]);
                break;
            }
        }
    }
    return ans;
}
```
时间复杂度：O（n）

空间复杂度：O（n）

--------------------------------------------------------

解法3：one-pass map

省去第一次初始化map，直接在遍历中补充map

```
std::vector<int> twoSum(std::vector<int> &nums, int target)
{
    std::map<int, int> indices;
    std::vector<int> ans;
    for (int i = 0; i != nums.size();++i)
    {
        int temp = target - nums[i];
        if(indices.find(temp) == indices.end())
        {
            indices[nums[i]] = i;
        }
        else
        {
            ans.push_back(i);
            ans.push_back(indices.at(temp));
        }
    }
    return ans;
}
```
时间复杂度：O（n）

空间复杂度：O（n）
