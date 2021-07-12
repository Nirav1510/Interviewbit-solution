priority_queue<double> left;                                   //max_heap
priority_queue<double, vector<double>, greater<double>> right; //min heap
MedianFinder()
{
    
}

void addNum(int num)
{
    if (left.empty() || num < left.top())
    {
        left.push(num);
    }
    else
    {
        right.push(num);
    }
    //arranging size of left and right
    //right.size()<=left.size()<=1+right.size()
    if (left.size() > 1 + right.size())
    {
        right.push(left.top());
        left.pop();
    }
    else if (left.size() < right.size())
    {
        left.push(right.top());
        right.pop();
    }
}

double findMedian()
{
    return left.size() > right.size() ? left.top() : (left.top() + right.top()) / 2;
}