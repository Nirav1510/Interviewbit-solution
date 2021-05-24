stack<int> s;
int minEle;

MinStack::MinStack()
{
    while (!s.empty())
    {
        s.pop();
    }
    minEle = -1;
}

void MinStack::push(int x)
{
    if (s.empty())
    {
        s.push(x);
        minEle = x;
    }
    else
    {
        if (x >= minEle)
        {
            s.push(x);
        }
        else
        {
            s.push(2 * x - minEle);
            minEle = x;
        }
    }
}

void MinStack::pop()
{
    if (s.empty())
        minEle = -1;

    if (!s.empty())
    {
        if (s.top() > minEle)
        {
            s.pop();
        }
        else
        {
            minEle = 2 * minEle - s.top();
            s.pop();
        }
    }
}

int MinStack::top()
{
    if (s.empty())
    {
        return -1;
    }
    else
    {
        if (s.top() > minEle)
            return s.top();
        else
            return minEle;
    }
}

int MinStack::getMin()
{
    if (s.empty())
    {
        return -1;
    }
    return minEle;
}