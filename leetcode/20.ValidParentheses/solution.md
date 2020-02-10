### 20. Valid Parentheses

很简单的一道对占的应用

```
bool isValid(std::string s)
{
    std::vector<char> vec;
    for (int i = 0; i != s.size(); ++i)
    {
        if (vec.empty())
        {
            vec.push_back(s[i]);
            continue;
        }
        if (s[i] == ')' && vec.back() == '(')
        {
            vec.erase(vec.end() - 1);
            continue;
        }
        if (s[i] == '}' && vec.back() == '{')
        {
            vec.erase(vec.end() - 1);
            continue;
        }
        if (s[i] == ']' && vec.back() == '[')
        {
            vec.erase(vec.end() - 1);
            continue;
        }
        vec.push_back(s[i]);
    }
    if (vec.empty())
        return true;
    return false;
}

```
