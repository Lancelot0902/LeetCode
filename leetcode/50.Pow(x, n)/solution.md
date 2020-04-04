### 50. Pow(x, n)

利用分治的思想，只要 ```n>=2```，就可以继续继续递归

```
double Pow(double x, int n)
{
    if (n == 1)
        return x;
    else
    {
        if (n % 2 == 0)
            return Pow(x, n / 2) * Pow(x, n / 2);
        else
            return Pow(x, n / 2) * Pow(x, n / 2) * x;
    }
}

double myPow(double x, int n)
{
    if (n == 0)
        return 1;
    int m = n;
    if (n < 0)
    {
        x = 1 / x;
        if (n == INT_MIN)
            return myPow(x, INT_MAX) * x;
        else
            m = -n;
    }
    return Pow(x, m);
}
```

当 ```n = INT_MIN``` 时要特殊处理，因为 ```INT_MIN``` 的绝对值要比 ```INT_MAX``` 大 1，所以用 ```int``` 来接收会溢出，开始我是这样处理的
```
long m = -n;
```
因为等式右边已经大于了 ```INT_MAX```,所以右边的类型不能是 ```int```
