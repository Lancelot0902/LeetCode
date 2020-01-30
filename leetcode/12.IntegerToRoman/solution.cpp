#include <iostream>
#include <string>
#include <vector>

std::string intToRoman(int num)
{
    std::string res = "";
    while (num != 0)
    {
        if (num >= 1000)
        {
            res += 'M';
            num -= 1000;
            continue;
        }

        if (num >= 900)
        {
            res += "CM";
            num -= 900;
            continue;
        }

        if (num >= 500)
        {
            res += 'D';
            num -= 500;
            continue;
        }

        if (num >= 400)
        {
            res += "CD";
            num -= 400;
            continue;
        }

        if (num >= 100)
        {
            res += "C";
            num -= 100;
            continue;
        }

        if (num >= 90)
        {
            res += "XC";
            num -= 90;
            continue;
        }

        if (num >= 50)
        {
            res += "L";
            num -= 50;
            continue;
        }

        if (num >= 40)
        {
            res += "XL";
            num -= 40;
            continue;
        }

        if (num >= 10)
        {
            res += "X";
            num -= 10;
            continue;
        }

        if (num >= 9)
        {
            res += "IX";
            num -= 9;
            continue;
        }

        if (num >= 5)
        {
            res += "V";
            num -= 5;
            continue;
        }

        if (num >= 4)
        {
            res += "IV";
            num -= 4;
            continue;
        }

        if (num >= 1)
        {
            res += 'I';
            num -= 1;
            continue;
        }
    }
    return res;
}