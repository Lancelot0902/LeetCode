#include <vector>

class MinStack
{
    std::vector<std::vector<int>> stack;

public:
    /** initialize your data structure here. */
    MinStack()
    {
    }

    void push(int x)
    {
        if (stack.empty())
            stack.push_back({x, x});
        else if (stack.back()[1] < x)
            stack.push_back({x, stack.back()[1]});
        else
            stack.push_back({x, x});
    }

    void pop()
    {
        stack.erase(stack.end() - 1);
    }

    int top()
    {
        return stack.back()[0];
    }

    int getMin()
    {
        return stack.back()[1];
    }
};