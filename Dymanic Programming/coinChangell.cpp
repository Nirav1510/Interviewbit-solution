#include <bits/stdc++.h>
using namespace std;

int minCoinsRecursion(vector<int> &coins, int n, int amt)
{
    if (!amt)
        return 0;

    if (!n)
        return -1;

    if (coins[n - 1] <= amt)
        return min(1 + minCoinsRecursion(coins, n, amt - coins[n - 1]),
                   minCoinsRecursion(coins, n - 1, amt));

    else
        return minCoinsRecursion(coins, n - 1, amt);
}

int minCoins(vector<int> &coins, int n, int v)
{

    int dp[n + 1][v + 1];

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < v + 1; j++)
        {
            if (j == 0 && i != 0)
            {
                dp[i][j] = 0;
            }
            if (i == 0)
            {
                dp[i][j] = INT_MAX - 1;
            }
            if (i == 1)
            {
                if (j % coins[0] == 0)
                {
                    dp[i][j] = j / coins[0];
                }
                else
                {
                    dp[i][j] = INT_MAX - 1;
                }
            }
        }
    }

    for (int i = 2; i < n + 1; i++)
    {
        for (int j = 1; j < v + 1; j++)
        {
            if (coins[i - 1] <= j)
            {
                dp[i][j] = min(dp[i][j - coins[i - 1]] + 1, dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][v] == INT_MAX - 1 ? -1 : dp[n][v];
}

int minCoinsSpaceOptimised(vector<int> &coins, int n, int amt)
{

    int dp[amt + 1];

    for (int i = 0; i < amt + 1; i++)
        dp[i] = INT_MAX - 1;

    dp[0] = 0;

    for (int coin : coins)
    {
        for (int i = coin; i < amt + 1; i++)
            dp[i] = min(1 + dp[i - coin], dp[i]);
    }

    return dp[amt] == INT_MAX - 1 ? -1 : dp[amt];
}

int main()
{
    int n;
    cin >> n;
    int v;
    cin >> v;
    vector<int> coins(n);
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    cout << minCoins(coins, n, v) << endl;
    cout << minCoinsRecursion(coins, n, v) << endl;
    cout << minCoinsSpaceOptimised(coins, n, v) << endl;

    return 0;
}