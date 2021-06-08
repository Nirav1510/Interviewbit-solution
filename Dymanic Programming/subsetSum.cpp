#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &v, int sum)
{
    int n = v.size();
    int dp[n + 1][sum + 1];

    for (int j = 0; j < sum + 1; j++)
    {
        dp[0][j] = 0;
    }

    for (int i = 0; i < n + 1; i++)
    {
        dp[i][0] = 1;
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {

            if (v[i - 1] <= j)
            {
                dp[i][j] = (dp[i - 1][j - v[i - 1]] || dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][sum];
}

int main()
{
    vector<int> v = {3, 34, 4, 12, 5, 2};
    int target;
    cin >> target;
    cout << solve(v, target) << endl;
    return 0;
}