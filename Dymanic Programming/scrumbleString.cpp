unordered_map<string, bool> m;

bool solve(string a, string b)
{
    int n = a.length();
    if (a.compare(b) == 0)
    {
        return 1;
    }
    if (n <= 1)
        return 0;

    string key = a + "_" + b;
    bool flag = 0;
    if (m.find(key) != m.end())
    {
        return m[key];
    }

    for (int i = 1; i < n; i++)
    {
        string firstSwapKey = a.substr(0, i) + "_" + b.substr(n - i, n);
        string secondSwapKey = a.substr(i, n) + "_" + b.substr(0, n - i);
        string firstNormalKey = a.substr(0, i) + "_" + b.substr(0, i);
        string secondNormalKey = a.substr(i, n) + "_" + b.substr(i, n);
        int fsk;
        int ssk;
        int fnk;
        int snk;
        if (m.find(firstSwapKey) != m.end())
        {
            fsk = m[firstSwapKey];
        }
        else
        {
            fsk = solve(a.substr(0, i), b.substr(n - i, n));
            m[firstSwapKey] = fsk;
        }
        if (m.find(secondSwapKey) != m.end())
        {
            ssk = m[secondSwapKey];
        }
        else
        {
            ssk = solve(a.substr(i, n), b.substr(0, n - i));
            m[secondSwapKey] = ssk;
        }
        if (m.find(firstNormalKey) != m.end())
        {
            fnk = m[firstNormalKey];
        }
        else
        {
            fnk = solve(a.substr(0, i), b.substr(0, i));
            m[firstNormalKey] = fnk;
        }
        if (m.find(secondNormalKey) != m.end())
        {
            snk = m[secondNormalKey];
        }
        else
        {
            snk = solve(a.substr(i, n), b.substr(i, n));
            m[secondNormalKey] = snk;
        }
        if ((fsk == 1 && ssk == 1) || (fnk == 1 && snk == 1))
        {
            flag = 1;
            break;
        }
    }
    return m[key] = flag;
}

int isScramble(const string a, const string b)
{
    int n = a.length(), l = b.length();
    m.clear();
    if (n != l)
        return 0;
    if (n == 0 && l == 0)
        return 1;

    int res = solve(a, b);

    return res;
}
