typedef long long int ll;

//memoization+map O(n)

unordered_map<int, int> mp;
int mod;

int ways(string s, int i)
{
    if (i >= s.length())
        return 1;
    if (s[i] == '0')
        return 0;

    if (mp.find(i) != mp.end())
    {
        return mp[i];
    }

    int total = ways(s, i + 1) % mod;
    if (i + 2 <= s.length() && stoi(s.substr(i, 2)) <= 26)
    {
        total += ways(s, i + 2) % mod;
    }
    return mp[i] = total;
}

int numDecodings(string A)
{
    mp.clear();
    mod = 1e9 + 7;
    return ways(A, 0);
}

// array + O(n);

int t[101];

int solve(string &s, int i)
{
    if (i <= 0)
        return 1;

    if (t[i] != -1)
        return t[i];

    int first = 0, second = 0;

    if (s[i] != '0')
    {
        first = solve(s, i - 1);
    }

    if (s[i - 1] != '0')
    {
        string str = s.substr(i - 1, 2);
        int num = stoi(str);

        if (num <= 26)
        {
            second = solve(s, i - 2);
        }
    }

    return t[i] = first + second;
}

int numDecodings(string s)
{
    int n = s.length();

    if (s[0] == '0')
        return 0;

    memset(t, -1, sizeof(t));

    return solve(s, n - 1);
}

// tabular DP

int mod = 1e9 + 7;

int numDecodings(string s)
{
    int n = s.size();
    vector<int> dp(n + 1, 0);
    dp[n] = 1;

    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == '0')
        {
            dp[i] = 0;
            continue;
        }

        dp[i] = dp[i + 1];

        if ((i + 2 <= n) && stoi(s.substr(i, 2)) <= 26)
            dp[i] += dp[i + 2];
    }
    return dp[0];
}

// space-optimized

int mod = 1e9 + 7;

int numDecodings(string s)
{
    int n = s.size();
    int near = 1, far = 0;
    int curr = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        curr = near;

        if (s[i] == '0')
        {
            curr = 0;
        }

        if ((i + 2 <= n) && ((s[i] == '1') || (s[i] == '2' && s[i + 1] <= '6')))
            curr = (curr % mod + far % mod) % mod;

        far = near;
        near = curr;
    }
    return curr;
}