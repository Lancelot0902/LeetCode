### 844. Backspace String Compare

没什么算法，直接解就可以了，也可以用一个栈来辅助

```
void backspace(std::string &s)
{
    for (auto it = s.begin(); it < s.end(); ++it)
    {
        while (*it == '#')
        {
            if (it != s.begin())
                it = s.erase(it - 1);
            it = s.erase(it);
        }
    }
}

bool backspaceCompare(std::string S, std::string T)
{
    backspace(S);
    backspace(T);
    if (S == T)
        return true;
    else
        return false;
}
```
