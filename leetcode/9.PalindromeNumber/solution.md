### 9.Palindrome Number

没什么算法，从个位开始将每一位提出来再组成一个新的数，判断新旧两数是否相等

```
bool isPalindrome(int x)
{
    if(x < 0)
        return false;
    long long temp = 0;
    int a = x;
    while(a != 0)
    {
        temp = temp * 10 + a % 10;
        a /= 10;
    }
    return temp == x;
}
```