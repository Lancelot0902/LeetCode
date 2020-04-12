### 1046. Last Stone Weight

考察对优先队列的使用，priority_queue

```
int lastStoneWeight(std::vector<int> &stones)
{
    std::priority_queue<int> nums;
    for (auto it : stones)
        nums.push(it);
    while (nums.size() >= 2)
    {
        int i = nums.top();
        nums.pop();
        int j = nums.top();
        nums.pop();
        int k = std::abs(i - j);
        if (k)
            nums.push(k);
    }
    return nums.size() == 1 ? nums.top() : 0;
}
```
