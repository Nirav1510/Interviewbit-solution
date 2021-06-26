int dp[101][101];
int uniquePathsWithObstacles(vector<vector<int>> &A)
{
    int m = A.size();
    int n = A[0].size();
    memset(dp, 0, sizeof(dp));
    if (A[0][0] == 0)
        dp[1][1] = 1;
    else
        dp[1][1] = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
                continue;
            if (A[i][j] == 0)
            {
                dp[i + 1][j + 1] = dp[i][j + 1] + dp[i + 1][j];
            }
        }
    }

    return dp[m][n];
}
