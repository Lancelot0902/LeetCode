/*
    题目描述：给定一个年份，判断是不是闰年
*/

#include <iostream>

int main(int argc, char **argv)
{
    int year;
    std::cin >> year;
    if (year % 4 == 0 && year % 100 != 0)
        std::cout << "yes";
    else if (year % 400 == 0)
        std::cout << "yes";
    else
        std::cout << "no";
    return 0;
}