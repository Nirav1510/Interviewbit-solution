#include <bits/stdc++.h>
using namespace std;

bool cvtpalindrome(string &s)
{
    int n = s.length();
    int i = 0, j = n - 1;
    int flag = 1;
    while (i < j)
    {
        if (s[i] == s[j])
        {
            i++;
            j--;
        }
        else
        {
            if (s[i + 1] == s[j] && flag)
            {
                i += 2;
                j--;
            }
            else if (s[i] == s[j - 1] && flag)
            {
                j -= 2;
                i++;
            }
            else
                return 0;
            flag = 0;
        }
    }
    return 1;
}
int main()
{
    string s = "abecbea";

    bool flag = cvtpalindrome(s);
    if (flag)
    {
        cout << 1 << endl;
    }
    else
    {
        cout << 0 << endl;
    }
    return 0;
}