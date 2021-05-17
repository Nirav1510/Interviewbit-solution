#include <algorithm>
#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll lengthOfLongestSubstring(string s)
{
    ll ans = INT_MIN;
    ll i = 0, j = 0;
    ll l = s.length();
    unordered_map<char, ll> m;
    while (j < l)
    {
        m[s[i]]++;

        if (m.size() < (j - i + 1))
        {
            while (m.size() < (j - i + 1))
            {
                m[s[i]]--;
                if (m[s[i]] == 0)
                {
                    m.erase(s[i]);
                }
                i++;
            }
        }
        ans = max(ans, j - i + 1);
        j++;
    }
    return ans;
}

int main()
{

    string st;
    cin >> st;
    ll res = lengthOfLongestSubstring(st);
    cout << res << endl;

    return 0;
}
