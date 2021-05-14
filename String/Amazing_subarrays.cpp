#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
ll m;
ll mod(ll x)
{
    return (((x % m) + m) % m);
}

ll subarrays(string &s)
{
    ll i = 0, ans = 0;
    ll l = s.length();
    while (i < l)
    {
        if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' || s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
        {
            ans += l - i;
        }
        i++;
    }
    return ans;
}

int main()
{
    string s = "ABECaacbyzrelq";
    m = 10003;
    ll res = subarrays(s);
    res = mod(res);
    cout << res << endl;

    return 0;
}