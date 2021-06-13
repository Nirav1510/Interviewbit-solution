// TLE code

unordered_map<string, int> mp;
int solve(string s, int i, int j, bool isTrue)
{
    if (i > j)
        return 0;
    if (i == j)
    {
        if (isTrue == 1)
        {
            return s[i] == 'T' ? 1 : 0;
        }
        else
        {
            return s[i] == 'F' ? 1 : 0;
        }
    }

    string temp = to_string(i) + " " + to_string(j) + " " + to_string(isTrue);

    if (mp.find(temp) != mp.end())
    {
        return mp[temp];
    }

    int ans = 0;

    for (int k = i + 1; k < j; k += 2)
    {
        int lt = solve(s, i, k - 1, 1);
        int lf = solve(s, i, k - 1, 0);
        int rt = solve(s, k + 1, j, 1);
        int rf = solve(s, k + 1, j, 0);

        if (s[k] == '&')
        {
            if (isTrue == 1)
            {
                ans += lt * rt;
            }
            else
            {
                ans += lt * rf + lf * rt + lf * rf;
            }
        }
        else if (s[k] == '|')
        {
            if (isTrue == 1)
            {
                ans += lt * rt + lt * rf + lf * rt;
            }
            else
            {
                ans += lf * rf;
            }
        }
        if (s[k] == '^')
        {
            if (isTrue == 1)
            {
                ans += lt * rf + lf * rt;
            }
            else
            {
                ans += lt * rt + lf * rf;
            }
        }
    }
    return mp[temp] = ans;
}

int countWays(int n, string s)
{
    mp.clear();
    int res = solve(s, 0, n - 1, 1);
    res = res % 1003;
    return res;
}

//recursive code

int ways(string s, int i, int j, bool T)
{

    if (i == j)
    {
        if (T)
            return s[i] == 'T' ? 1 : 0;
        return s[i] == 'T' ? 0 : 1;
    }

    int ans = 0;
    for (int k = i + 1; k < j; k += 2)
    {
        int lT = ways(s, i, k - 1, true), rT = ways(s, k + 1, j, true);
        int lF = ways(s, i, k - 1, false), rF = ways(s, k + 1, j, false);

        if (s[k] == '&')
        {
            if (T)
                ans += lT * rT;
            else
                ans += lT * rF + lF * rT + lF * rF;
        }
        else if (s[k] == '|')
        {
            if (T)
                ans += lT * rF + lF * rT + lT * rT;
            else
                ans += lF * rF;
        }

        else
        {
            if (T)
                ans += lT * rF + lF * rT;
            else
                ans += lF * rF + +lT * rT;
        }
    }
    return ans;
}
int countWays(int N, string s)
{
    return ways(s, 0, N - 1, true);
}

// Optimized code

int dp[201][201][2];
int solve(string s, int i, int j, bool isTrue)
{
    if (i > j)
        return 0;
    if (i == j)
    {
        if (isTrue == 1)
        {
            return s[i] == 'T' ? 1 : 0;
        }
        else
        {
            return s[i] == 'F' ? 1 : 0;
        }
    }

    if (dp[i][j][isTrue] != -1)
    {
        return dp[i][j][isTrue];
    }

    string temp = to_string(i) + " " + to_string(j) + " " + to_string(isTrue);

    int ans = 0;

    for (int k = i + 1; k < j; k += 2)
    {
        int lt, lf, rt, rf;

        if (dp[i][k - 1][1] != -1)
        {
            lt = dp[i][k - 1][1];
        }
        else
        {
            lt = solve(s, i, k - 1, 1);
        }
        if (dp[i][k - 1][0] != -1)
        {
            lf = dp[i][k - 1][0];
        }
        else
        {
            lf = solve(s, i, k - 1, 0);
        }
        if (dp[k + 1][j][1] != -1)
        {
            rt = dp[k + 1][j][1];
        }
        else
        {
            rt = solve(s, k + 1, j, 1);
        }
        if (dp[k + 1][j][0] != -1)
        {
            rf = dp[k + 1][j][0];
        }
        else
        {
            rf = solve(s, k + 1, j, 0);
        }

        if (s[k] == '&')
        {
            if (isTrue == 1)
            {
                ans += lt * rt;
            }
            else
            {
                ans += lt * rf + lf * rt + lf * rf;
            }
        }
        else if (s[k] == '|')
        {
            if (isTrue == 1)
            {
                ans += lt * rt + lt * rf + lf * rt;
            }
            else
            {
                ans += lf * rf;
            }
        }
        if (s[k] == '^')
        {
            if (isTrue == 1)
            {
                ans += lt * rf + lf * rt;
            }
            else
            {
                ans += lt * rt + lf * rf;
            }
        }
    }
    return dp[i][j][isTrue] = ans % 1003;
}

int countWays(int n, string s)
{
    memset(dp, -1, sizeof(dp));
    int res = solve(s, 0, n - 1, 1);
    res = res % 1003;
    return res;
}