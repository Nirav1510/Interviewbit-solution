int Solution::solve(vector<vector<int>> &A)
{
    int n = A.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int j = 0; j < n; j++)
    {
        dp[n - 1][j] = A[n - 1][j];
    }

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 0; j < n; j++)
        {
            dp[i][j] = A[i][j] + max(dp[i + 1][j], dp[i + 1][j + 1]);
        }
    }
    return dp[0][0];
}
