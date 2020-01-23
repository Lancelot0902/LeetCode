#include <iostream>
#include <string>
#include <vector>

int myAtoi(std::string str)
{
    int i = 0;
    int sign = 1;
    long ans = 0;
    while (str[i] == ' ')
        i += 1;
    if (i == str.size())
        return ans;
    sign = str[i++] == '-' ? -1 : 1;
    if (str[i] >= '0' && str[i] <= '9')
    {
        while (i != str.size() && (str[i] >= '0' && str[i] <= '9'))
        {
            ans = ans * 10 + str[i] - '0';
            if (ans * sign > INT_MAX || ans * sign < INT_MIN)
                return (sign == 1) ? INT_MAX : INT_MIN;
            i += 1;
        }
    }
    return ans * sign;
}