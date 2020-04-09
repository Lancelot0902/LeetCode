#include <string>

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
