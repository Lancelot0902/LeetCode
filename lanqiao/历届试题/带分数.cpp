#include <iostream>
#include <vector>
#include <algorithm>

int sum(int l, int r, int *vec)
{
    if (l > r)
        return 1;
    int n = 0;
    for (int i = l; i <= r; ++i)
    {
        n = n * 10 + vec[i];
    }
    return n;
}

int size(int n)
{
    int count = 0;
    while (n)
    {
        count += 1;
        n /= 10;
    }
    return count;
}

int main(int argc, char **argv)
{
    int n, a, b, c;
    std::cin >> n;
    int vec[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int res = 0;
    do
    {
        for (int i = 0; i != size(n); ++i)
        {
            for (int j = i; j != 8; ++j)
            {
                a = sum(0, i, vec);
                b = sum(i + 1, j, vec);
                c = sum(j + 1, 8, vec);
                if (n == a + b / c && b % c == 0)
                {
                    res += 1;
                }
            }
        }
    } while (std::next_permutation(vec, vec + 9));
    std::cout << res;
    return 0;
}
