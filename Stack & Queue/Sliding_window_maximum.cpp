vector<int> slidingMaximum(const vector<int> &A, int B)
{
    deque<int> l;
    vector<int> v;
    int i = 0, j = 0;
    while (j < A.size())
    {

        while (l.size() > 0 && l.back() < A[j])
        {
            l.pop_back();
        }
        l.push_back(A[j]);

        if (j - i + 1 < B)
            j++;

        else if (j - i + 1 == B)
        {
            v.push_back(l.front());

            if (l.front() == A[i])
            {
                l.pop_front();
            }
            i++;
            j++;
        }
    }
    return v;
}

// using max heap
vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    vector<int> X;
    priority_queue<pair<int, int>> Q;
    int i = 0, j = 0;
    for (i = 0; i < k; i++)
    {
        Q.push({nums[i], i});
    }
    X.push_back(Q.top().first);

    for (i = k; i < nums.size(); i++)
    {
        Q.push({nums[i], i});
        while (Q.top().second <= j)
            Q.pop();
        X.push_back(Q.top().first);
        j++;
    }
    return X;
}