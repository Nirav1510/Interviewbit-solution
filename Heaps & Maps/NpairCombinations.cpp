vector<int> solve(vector<int> &A, vector<int> &B)
{
    priority_queue<long long, vector<long long>, greater<int>> minHeap;
    sort(A.rbegin(), A.rend());
    sort(B.rbegin(), B.rend());
    long long summ = 0;

    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < B.size(); j++)
        {
            summ = A[i] + B[j];
            if (i == 0)
            {
                minHeap.push(summ);
            }
            else if (minHeap.top() < summ)
            {
                minHeap.pop();
                minHeap.push(summ);
            }
            else
            {
                break;
            }
        }
    }
    vector<int> ans(minHeap.size(), 0);
    int i = minHeap.size() - 1;
    while (!minHeap.empty())
    {
        ans[i--] = minHeap.top();
        minHeap.pop();
    }
    return ans;
}
