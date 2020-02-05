/*
    问题描述：输出一串数字的正确读法
*/

#include <iostream>
#include <vector>
#include <string>

int main(int argc, char **argv)
{
    std::string str;
    std::cin >> str;
    if (str == "0")
    {
        std::cout << "ling";
        return 0;
    }
    std::string res;
    std::vector<std::string> vec{"shi", "bai", "qian", "wan"};
    std::vector<std::string> nums{"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
    int rank = 0;
    int n = str.size();
    bool flag = false;
    if (str[n - 1] != '0')
    {
        int index = str[n - 1] - '0' + 0;
        res += nums[index];
    }
    else
        flag = true;
    int it = 0;
    for (int i = n - 2; i >= 0; --i)
    {
        if (str[i] == '0')
        {
            if (!flag)
            {
                res = "ling " + res;
                flag = true;
            }
            if (it == 3)
                res = vec[3] + " " + res;
        }
        else
        {
            int index = str[i] - '0' + 0;
            if (index == 1 && it == 0)
            {
                if (i - 1 >= 0 && str[i - 1] == '0')
                    res = nums[index] + " " + vec[it] + " " + res;
                else
                    res = vec[it] + " " + res;
            }
            else
                res = nums[index] + " " + vec[it] + " " + res;
            flag = false;
        }
        if (it + 1 == 4)
        {
            it = 0;
            rank += 1;
            if (rank == 1)
                vec[3] = "yi";
        }
        else
            it += 1;
    }
    std::cout << res;
    return 0;
}
