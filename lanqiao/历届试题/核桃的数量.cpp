#include <iostream>
#include <algorithm>

int main(int argc, char **argv)
{
    int a, b, c;
    std::cin >> a >> b >> c;
    int m = std::max(a, std::max(b, c));
    while (1)
    {
        if (m % a == 0 && m % b == 0 && m % c == 0)
        {
            std::cout << m;
            return 0;
        }
        else
            m += m;
    }
    return 0;
}
