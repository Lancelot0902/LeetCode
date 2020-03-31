### 46. Permutations

一道经典的全排列的题，使用深度优先搜索所有的组合，因为题目说了数组中不含重复的数，所以不需要对数组排序，有两种方法可以进行广度的遍历
* 使用一个数组来记录nums中的数是否被使用，若被使用则跳过，否则加入到temp
* 利用交换，将遍历到的某个数和此次循环开头的数交换，比如[1,2,3]，第一层从1开始遍历，当需要将2放到头部时和1交换，[2,1,3]就可以了

```
void dfs(std::vector<int> &nums, std::vector<std::vector<int>> &ans, std::vector<int> temp, int begin)
{
    if (begin == nums.size())
    {
        ans.push_back(temp);
    }
    else
    {
        for (int i = begin; i != nums.size(); ++i)
        {
            temp.push_back(nums[i]);
            std::swap(nums[i], nums[begin]);
            dfs(nums, ans, temp, begin + 1);
            std::swap(nums[i], nums[begin]);
            temp.pop_back();
        }
    }
}

std::vector<std::vector<int>> permute(std::vector<int> &nums)
{
    std::vector<std::vector<int>> ans;
    std::vector<int> temp;
    dfs(nums, ans, temp, 0);
    return ans;
}
```
