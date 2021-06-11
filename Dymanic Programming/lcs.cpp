#include <bits/stdc++.h>
using namespace std;

long long int dp[1006][1006];
//top down Approch
long long int LCS(string x, string y, int m, int n)
{

    for (int i = 0; i < m + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            if (i == 0 && j == 0)
            {
                dp[i][j] = 0;
            }
        }
    }

    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (x[i - 1] == y[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
}

int solve(string A, string B)
{
    int m = A.length(), n = B.length();
    long long int ans = LCS(A, B, m, n);
    return ans;
}
