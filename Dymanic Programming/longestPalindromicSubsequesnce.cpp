int dp[1006][1006];
int lcs(string a, string b)
{
    int m = a.length(), n = b.length();

    memset(dp, 0, sizeof(0));
    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
}

int Solution::solve(string A)
{
    string a = A;
    reverse(a.begin(), a.end());
    string b = a;
    a = A;
    return lcs(a, b);
}
