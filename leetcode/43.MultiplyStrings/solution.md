### 43. Multiply Strings

最开始想到的解法就是用普通的竖式乘法，也就是一步一步来，但是这个有点麻烦，还得把两个string相加，所以考虑其他方法

![](https://pic.leetcode-cn.com/171cad48cd0c14f565f2a0e5aa5ccb130e4562906ee10a84289f12e4460fe164-image.png)

观察上面的图，可以看到每两个数相乘的结果所在位置是有规律的，``` num1[i] * num2[j] ```的结果最多也就是两位数，所以十位数所在位置为 ```res[i+j]```，个位数所在位置为 ```res[i+j+1]```

这个方法还真有焕然一新的感觉

```
std::string multiply(std::string num1, std::string num2)
{
    if (num1.empty() || num2.empty())
        return "";
    if (num1 == "0" || num2 == "0")
        return "0";
    int n = num1.size();
    int m = num2.size();
    std::string ret;
    std::vector<int> nums(m + n);
    for (int i = n - 1; i >= 0; --i)
    {
        int p = num1[i] - '0';
        for (int j = m - 1; j >= 0; --j)
        {
            int q = num2[j] - '0';
            int num = nums[i + j + 1] + p * q;
            nums[i + j + 1] = num % 10;
            nums[i + j] += num / 10;
        }
    }
    for (int i = 0; i != nums.size(); ++i)
    {
        if (i == 0 && nums[i] == 0)
            continue;
        else
            ret += nums[i] + '0';
    }
    return ret;
}
```
