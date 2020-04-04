#include <iostream>

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
