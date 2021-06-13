typedef long long int ll;
int Solution::solve(vector<int> &A)
{
    int n = A.size();
    ll s = 0;
    for (auto i : A)
    {
        s += i;
    }
    bool dp[n + 1][s + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < s + 1; j++)
        {
            if (i == 0)
            {
                dp[i][j] = 0;
            }
            if (j == 0)
            {
                dp[i][j] = 1;
            }
        }
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < s + 1; j++)
        {
            if (A[i] <= j)
            {
                dp[i][j] = (dp[i - 1][j] || dp[i - 1][j - A[i]]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    vector<ll> v;
    for (ll i = 0; i <= s / 2; i++)
    {
        if (dp[n][i] == 1)
        {
            v.push_back(i);
        }
    }
    ll ans = INT_MAX;
    for (auto i : v)
    {
        ans = min(ans, s - 2 * i);
    }
    return ans;
}
