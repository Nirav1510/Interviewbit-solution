#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void Max_str(string A, int B, int index, string &ans)
{

    if (B == 0)
        return;

    for (int i = index; i < A.size() - 1; i++)
    {
        for (int j = i; j < A.size(); j++)
        {
            swap(A[i], A[j]);
            if (A >= ans)
                ans = A;
            Max_str(A, B - 1, index + 1, ans);
            swap(A[i], A[j]);
        }
    }
}

string solve(string A, int B)
{
    string ans = A;
    Max_str(A, B, 0, ans);
    return ans;
}

int main()
{
    string s;
    cin >> s;
    int n;
    cin >> n;
    string res = solve(s, n);
    cout << res << endl;
    return 0;
}