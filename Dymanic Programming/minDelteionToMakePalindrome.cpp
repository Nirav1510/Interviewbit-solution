int dp[1001][1001];
int i, j;
int lcs(string a, string b)
{
    memset(dp, 0, sizeof(dp));
    int m = a.length();
    int n = m;
    for (i = 1; i < m + 1; i++)
    {
        for (j = 1; j < n + 1; j++)
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

int minimumNumberOfDeletions(string s)
{
    string a = s;
    reverse(a.begin(), a.end());
    string b = a;
    a = s;

    return s.length() - lcs(a, b);
}