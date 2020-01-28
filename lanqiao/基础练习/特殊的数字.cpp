/*
    问题描述：编程求所有满足条件的三位十进制数
*/

#include <iostream>

int main(int argc,char** argv)
{
    for (int i = 100; i != 1000;i++)
    {
        int temp = i;
        int a = temp % 10;
        temp /= 10;
        int b = temp % 10;
        temp /= 10;
        int c = temp % 10;

        if(a*a*a+b*b*b+c*c*c == i)
            std::cout << i << std::endl;
    }
    return 0;
}
