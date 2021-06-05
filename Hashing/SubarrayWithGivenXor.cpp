typedef long long int ll;
int Solution::solve(vector<int> &A, int B)
{
    ll ans = 0, n = A.size();
    vector<int> xr(n);
    xr[0] = A[0];
    map<int, int> m;
    for (int i = 1; i < n; i++)
    {
        xr[i] = xr[i - 1] ^ A[i];
    }
    for (int i = 0; i < n; i++)
    {
        ll y = B ^ xr[i];

        if (xr[i] == B)
        {
            ans++;
        }
        if (m.find(y) != m.end())
        {
            ans += m[y];
        }
        m[xr[i]]++;
    }
    return ans;
}
