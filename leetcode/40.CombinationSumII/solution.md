### 40. Combination Sum II

和上一题的思路一样，只不过要跳过相同的情况

```
void dfs(std::vector<int> &candidates, std::vector<std::vector<int>> &res, std::vector<int> &temp, int target, int begin)
{
    if (!target)
    {
        res.push_back(temp);
        return;
    }
    else if (begin < candidates.size())
    {
        for (int i = begin; i != candidates.size() && candidates[i] <= target; ++i)
        {
            if (i > begin && candidates[i] == candidates[i - 1])
                continue;
            temp.push_back(candidates[i]);
            dfs(candidates, res, temp, target - candidates[i], i + 1);
            temp.pop_back();
        }
    }
}

std::vector<std::vector<int>> combinationSum2(std::vector<int> &candidates, int target)
{
    std::sort(candidates.begin(), candidates.end());
    std::vector<std::vector<int>> res;
    std::vector<int> temp;
    dfs(candidates, res, temp, target, 0);
    return res;
}

```
