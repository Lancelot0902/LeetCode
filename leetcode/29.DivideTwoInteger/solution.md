### 29. Divide Two Integer

此题的边界要单独处理，其次就是让除数不断逼近被除数
举个例子：11 除以 3 。
首先11比3大，结果至少是1， 然后我让3翻倍，就是6，发现11比3翻倍后还要大，那么结果就至少是2了，那我让这个6再翻倍，得12，11不比12大，吓死我了，差点让就让刚才的最小解2也翻倍得到4了。但是我知道最终结果肯定在2和4之间。也就是说2再加上某个数，这个数是多少呢？我让11减去刚才最后一次的结果6，剩下5，我们计算5是3的几倍，也就是除法，看，递归出现了。

https://leetcode-cn.com/problems/divide-two-integers/solution/po-su-de-xiang-fa-mei-you-wei-yun-suan-mei-you-yi-/

```
long div(long a, long b)
{
    if (a < b)
        return 0;
    long count = 1;
    long bb = b;
    while ((bb + bb) <= a)
    {
        count = count + count;
        bb = bb + bb;
    }
    return count + div(a - bb, b);
}

int divide(int dividend, int divisor)
{
    if (dividend == 0)
        return 0;
    if (divisor == 1)
        return dividend;
    if (divisor == -1)
    {
        if (dividend == INT_MIN)
            return INT_MAX;
        else
            return -dividend;
    }
    long a = dividend;
    long b = divisor;
    bool flag = true;
    if ((a > 0 && b < 0) || (a < 0 && b > 0))
        flag = false;
    a = a > 0 ? a : -a;
    b = b > 0 ? b : -b;
    long res = div(a, b);
    if (flag)
        return res > INT_MAX ? INT_MAX : res;
    else
        return -res < int_min ? INT_MIN : res;
}
```
