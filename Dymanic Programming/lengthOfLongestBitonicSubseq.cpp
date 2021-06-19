int Solution::longestSubsequenceLength(const vector<int> &A)
{
    //find LIS and LDS
    // ans=max(lis,lds)-1

    int n = A.size();
    if (n == 1)
        return 1;

    vector<int> lis(n, 1);
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (A[j] < A[i])
            {
                lis[i] = max(lis[i], 1 + lis[j]);
            }
        }
    }
    vector<int> lds(n, 1);
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (A[j] < A[i])
            {
                lds[i] = max(lds[i], 1 + lds[j]);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(lis[i] + lds[i] - 1, ans);
    }
    return ans;
}