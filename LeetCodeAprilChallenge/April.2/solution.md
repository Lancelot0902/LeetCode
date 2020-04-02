### 202. Happy Number

这个题需要找规律，我们使用一个set来保存每次运算后的结果，如果这个结果在set已经存在，那么这个数就会陷入死循环，直接返回false

```
bool isHappy(int n)
{
    std::set<int> nums;
    while (1)
    {
        int temp = 0;
        while (n)
        {
            temp += std::pow(n % 10, 2);
            n /= 10;
        }
        n = temp;
        if (n == 1)
            return true;
        if (nums.find(n) == nums.end())
            nums.insert(n);
        else
            return false;
    }
}
```
