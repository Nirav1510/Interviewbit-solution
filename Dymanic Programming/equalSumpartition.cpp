#include <bits/stdc++.h>
using namespace std;

int subsetSum(int n, int arr[], ll s)
{
    ll dp[n + 1][s + 1];

    for (int j = 0; j < s + 1; j++)
    {
        dp[0][j] = 0;
    }
    for (int i = 0; i < n + 1; i++)
    {
        dp[i][0] = 1;
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < s + 1; j++)
        {
            if (arr[i - 1] <= j)
            {
                dp[i][j] = (dp[i - 1][j - arr[i - 1]] || dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][s];
}

int equalPartition(int n, int arr[])
{
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    if (sum % 2 != 0)
        return 0;
    else if (sum % 2 == 0)
    {
        return subsetSum(n, arr, sum / 2);
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin > arr[i];
    }

    cout << equalPartition(n, arr) << endl;

    return 0;
}