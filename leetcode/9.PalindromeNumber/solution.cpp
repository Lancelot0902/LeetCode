#include <iostream>

bool isPalindrome(int x)
{
    if (x < 0)
        return false;
    long long temp = 0;
    int a = x;
    while (a != 0)
    {
        temp = temp * 10 + a % 10;
        a /= 10;
    }
    return temp == x;
}