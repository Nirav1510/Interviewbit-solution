vector<int> Solution::solve(int A, int B, int C, int D)
{
    vector<int> dp(1, 1);
    int i = 0, j = 0, k = 0;

    while (D--)
    {
        int curr = min(dp[i] * A, min(dp[j] * B, dp[k] * C));
        dp.push_back(curr);
        if (curr == dp[i] * A)
            i++;
        if (curr == dp[j] * B)
            j++;
        if (curr == dp[k] * C)
            k++;
    }
    dp.erase(dp.begin() + 0);
    return dp;
}
