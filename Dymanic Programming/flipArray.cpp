int Solution::solve(const vector<int> &wt)
{
    int n = wt.size();
    int sum = 0;
    for (auto i : wt)
    {
        sum += i;
    }
    sum /= 2;
    int dp[n + 1][sum + 1];

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (i == 0)
            {
                dp[i][j] = INT_MAX - 1;
            }
            if (j == 0)
            {
                dp[i][j] = 0;
            }
        }
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (wt[i - 1] <= j)
            {
                dp[i][j] = min(1 + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    int k = sum;
    while (dp[n][k] == INT_MAX - 1)
    {
        k--;
    }
    return dp[n][k];
}
