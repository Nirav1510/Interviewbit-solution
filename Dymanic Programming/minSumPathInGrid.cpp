//memoization

vector<vector<int>> dp;
int solve(vector<vector<int>> v, int i, int j)
{
    if (i < 0 || j < 0)
    {
        return INT_MAX;
    }
    if (i == 0 && j == 0)
    {
        return v[i][j];
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    return dp[i][j] = v[i][j] + min(solve(v, i - 1, j), solve(v, i, j - 1));
}

int Solution::minPathSum(vector<vector<int>> &A)
{
    int m = A.size(), n = A[0].size();
    dp.assign(m + 1, vector<int>(n + 1, -1));
    return solve(A, m - 1, n - 1);
}

//top-down

int minPathSum(vector<vector<int>> &grid)
{
    int n = grid.size(), m = grid[0].size();
    return pathSum(grid, n, m);
}
int pathSum(vector<vector<int>> &grid, int n, int m)
{
    int dp[n + 1][m + 1];

    for (int i = 0; i <= n; i++)
        dp[i][0] = INT_MAX;
    for (int j = 0; j <= m; j++)
        dp[0][j] = INT_MAX;
    dp[0][0] = dp[0][1] = dp[1][0] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i - 1][j - 1];
        }
    }
    return dp[n][m];
}
