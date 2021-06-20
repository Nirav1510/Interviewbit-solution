int Solution::numDistinct(string s, string t)
{
    int n = s.length(), m = t.length();
    unsigned long long dp[n + 1][m + 1];

    for (int j = 0; j < m + 1; j++)
    {
        dp[0][j] = 0;
    }

    for (int i = 0; i < n + 1; i++)
    {
        dp[i][0] = 1;
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (s[i - 1] == t[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][m];
}
