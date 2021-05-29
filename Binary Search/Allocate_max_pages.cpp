#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool isValid(vector<int> &v, int k, ll mid)
{
    ll std = 1;
    ll sum = 0;
    for (int i = 0; i < v.size(); i++)
    {
        sum += v[i];
        if (sum > mid)
        {
            std++;
            sum = v[i];
        }
    }
    if (std > k)
        return false;
    return true;
}

int books(vector<int> &v, int k)
{
    int n = v.size();
    if (n < k)
    {
        return -1;
    }

    int sum = 0, maxi = v[0];
    for (ll i = 0; i < n; i++)
    {
        maxi = max(maxi, v[i]);
        sum += v[i];
    }

    ll low = maxi, high = sum, mid;
    ll ans = -1;
    while (low <= high)
    {
        mid = low + (high - low) / 2;

        if (isValid(v, k, mid))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> v = {10, 20, 50, 40, 60, 90, 30};
    int k;
    cin >> k;
    int res = books(v, k);
    cout << res << endl;

    return 0;
}