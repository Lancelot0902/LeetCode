/*
    问题描述：十六进制转八进制
*/

#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>

int main(int argc, char **argv)
{
    int n;
    std::cin >> n;
    std::vector<std::string> vec;
    std::map<char, std::string> hex;
    std::vector<std::string> bin;
    hex['0'] = "0000", hex['1'] = "0001", hex['2'] = "0010", hex['3'] = "0011", hex['4'] = "0100", hex['5'] = "0101";
    hex['6'] = "0110", hex['7'] = "0111", hex['8'] = "1000", hex['9'] = "1001", hex['A'] = "1010", hex['B'] = "1011";
    hex['C'] = "1100", hex['D'] = "1101", hex['E'] = "1110", hex['F'] = "1111";
    for (int i = 0; i != n; ++i)
    {
        std::string temp;
        std::cin >> temp;
        vec.push_back(temp);
    }
    for (int i = 0; i != n; ++i)
    {
        if (vec[i].size() == 1 && vec[i] <= "8")
            std::cout << vec[i] << std::endl;
        else
        {
            std::string str;
            for (int j = 0; j != vec[i].size(); ++j)
            {
                str += hex[vec[i][j]];
            }
            std::reverse(str.begin(), str.end());
            bin.push_back(str);
        }
    }

    for (int i = 0; i != bin.size(); ++i)
    {
        int j = 0;
        std::string ans;
        while (j < bin.size())
        {
            std::string str = bin[i].substr(j, 3);
            std::string temp;
            if (str == "000")
                temp = "0";
            if (str == "001")
                temp = "1";
            if (str == "010")
                temp = "2";
            if (str == "011")
                temp = "3";
            if (str == "100")
                temp = "4";
            if (str == "101")
                temp = "5";
            if (str == "110")
                temp = "6";
            if (str == "111")
                temp = "7";
            ans += temp;
            j += 3;
        }
        std::reverse(ans.begin(), ans.end());
        std::cout << ans << std::endl;
    }
    return 0;
}
