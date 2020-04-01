### 136. Single Number

题目要找出在数组中只出现一次的数，有很多方法，暴力啊，排序啊，利用哈希表啊等等，但是题目对复杂度作了要求，时间上为线性复杂度，空间上不能使用额外的空间，所以以上方法就都不行了；这里是对异或运算符的应用，异或运算符有一个性质，满足交换定律，```a^b^a = a^a^b```，而且 ```a^a = 0```，```o^b = b```，利用这个性质就可以求出只出现一次的那个数

```
int singleNumber(std::vector<int> &nums)
{
    int ans = nums[0];
    if (nums.size() > 1)
        for (int i = 1; i != nums.size(); ++i)
            ans = ans ^ nums[i];
    return ans;
}
```

这个属于知识盲区了，学艺不精。。
