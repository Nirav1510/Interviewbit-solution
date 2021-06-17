// O(n^2)

int Solution::solve(vector<vector<int>> &A)
{
    int n = A.size();
    sort(A.begin(), A.end());
    vector<int> dp(n, 1);

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if ((A[i][0] > A[j][1]) && (dp[i] < dp[j] + 1))
            {
                dp[i] = dp[j] + 1;
            }
        }
    }
    return *max_element(dp.begin(), dp.end());
}

// O(nlogn)

static bool cmp(vector<int> &a, vector<int> &b)
{
    return a[1] < b[1];
}

int findLongestChain(vector<vector<int>> &pairs)
{
    sort(pairs.begin(), pairs.end(), cmp);
    int n = pairs.size();
    int res = 0;
    for (int i = 0, j = 0; j < n; j++)
    {
        if (j == 0 || pairs[i][1] < pairs[j][0])
        {
            res++;
            i = j;
        }
    }
    return res;
}
