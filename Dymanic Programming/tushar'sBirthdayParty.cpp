int helper(int W, vector<int> wt, vector<int> val, vector<int> A)
{
    int n = wt.size();
    int dp[n + 1][W + 1];
    for (int i = 0; i < n + 1; i++)
        dp[i][0] = 0;

    for (int j = 0; j < W + 1; j++)
        dp[0][j] = 1000000;

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < W + 1; j++)
        {
            if (wt[i - 1] <= j)
            {
                dp[i][j] = min(val[i - 1] + dp[i][j - wt[i - 1]], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    int mincost = 0;
    for (int i : A)
    {
        mincost += dp[n][i];
    }
    return mincost;
}

int Solution::solve(const vector<int> &A, const vector<int> &wt, const vector<int> &val)
{
    int W = *max_element(A.begin(), A.end());

    int ans = helper(W, wt, val, A);
    return ans;
}
