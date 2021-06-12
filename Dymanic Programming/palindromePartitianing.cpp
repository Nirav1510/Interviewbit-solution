int dp[502][502];

bool isPalindrome(string s, int i, int j)
{
    if (i >= j)
        return true;
    while (i < j)
    {
        if (s[i] != s[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int solve(string s, int i, int j)
{
    if (i >= j)
        return 0;

    if (isPalindrome(s, i, j))
    {
        return 0;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int ans = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int left, right;

        if (dp[i][k] != -1)
        {
            left = dp[i][k];
        }
        else
        {
            left = solve(s, i, k);
        }
        if (dp[k + 1][j] != -1)
        {
            right = dp[k + 1][j];
        }
        else
        {
            right = solve(s, k + 1, j);
        }
        int temp = 1 + left + right;
        ans = min(ans, temp);
    }
    return dp[i][j] = ans;
}

int minCut(string s)
{
    memset(dp, -1, sizeof(dp));
    int n = s.length();
    int res = solve(s, 0, n - 1);

    return res;
}

int main()
{
    string str;
    cin >> str;
    cout << minCut(str) << endl;
    return 0;
}