### 39. Combination Sum

很简单的一道回溯

```
void dfs(std::vector<int> &candidates, std::vector<std::vector<int>> &res, int target, std::vector<int> &temp, int begin)
{
    if (!target)
    {
        res.push_back(temp);
        return;
    }
    else
    {
        for (int i = begin; i != candidates.size() && candidates[i] <= target; ++i)
        {
            temp.push_back(candidates[i]);
            dfs(candidates, res, target - candidates[i], temp, i);
            temp.pop_back();
        }
    }
}

std::vector<std::vector<int>> combinationSum(std::vector<int> &candidates, int target)
{
    std::sort(candidates.begin(), candidates.end());
    std::vector<std::vector<int>> res;
    std::vector<int> temp;
    dfs(candidates, res, target, temp, 0);
    return res;
}

```
