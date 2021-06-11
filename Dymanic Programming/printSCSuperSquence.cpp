string SCS(string x, string y)
{
    int n = x.size(), m = y.size();
    int dp[n + 1][m + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (x[i - 1] == y[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];

            else
                dp[i][j] = max(dp[i - 1][j], d[i][j - 1]);
        }
    }

    int i = n, j = m;
    string ans = "";
    while (i > 0 && j > 0)
    {
        if (x[i - 1] == y[j - 1])
        {
            ans.push_back(x[i - 1]);
            i--, j--;
        }

        else
        {
            if (dp[i - 1][j] < dp[i][j - 1])
            {
                ans.push_back(y[j - 1]);
                j--;
            }

            else
            {
                ans.push_back(x[i - 1]);
                i--;
            }
        }
    }

    while (i > 0)
    {
        ans.push_back(x[i - 1]);
        i--;
    }

    while (j > 0)
    {
        ans.push_back(y[j - 1]);
        j--;
    }

    reverse(ans.begin(), ans.end());

    return ans;
}
