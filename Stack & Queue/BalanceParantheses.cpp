#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int solve(string A)
{
    stack<char> s;
    for (int i = 0; i < A.length(); i++)
    {
        if (A[i] == '(')
        {
            s.push(A[i]);
        }
        else
        {
            if (s.size() == 0)
            {
                return 0;
            }
            s.pop();
        }
    }
    if (s.empty())
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    string s = "(()()()()))";
    int res = solve(s);
    cout << res << endl;
    return 0;
}