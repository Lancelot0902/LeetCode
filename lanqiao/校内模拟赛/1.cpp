/*
    1200000有多少个约数（只计算正约数）
 */

#include <iostream>

int main(int argc, char **argv)
{
    int sum = 0;
    for (int i = 1; i <= 1200000; ++i)
        if (1200000 % i == 0)
            sum += 1;
    std::cout << sum;
    return 0;
}
