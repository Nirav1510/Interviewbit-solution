int subsetSum(int a[], int n, int sum)
{
    int dp[n + 1][sum + 1];

    for (int j = 0; j <= sum; j++)
        dp[0][j] = 0;
    for (int i = 0; i <= n; i++)
        tab[i][0] = 1;
 
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (a[i - 1] > j)
                dp[i][j] = dp[i - 1][j];
            else
            {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - a[i - 1]];
            }
        }
    }
    return dp[n][sum];
}