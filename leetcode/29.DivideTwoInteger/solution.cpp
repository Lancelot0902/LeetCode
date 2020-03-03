#include <iostream>

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
