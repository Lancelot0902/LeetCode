### 155. Min Stack

虽然很简单，但是第一次做让这么写的题（我做的题少 :) ）

我用了二维数组，规模是 N * 2 的，第二列用来存放当前位置之前的最小值

```
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
```
