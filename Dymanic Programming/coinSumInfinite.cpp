int Solution::coinchange2(vector<int> &coin, int sum)
{
    int n = coin.size();
    int mod = 1000007;
    int dp[sum + 1] = {0};
    dp[0] = 1;

    for (int i : coin)
    {
        for (int j = i; j < sum + 1; j++)
        {
            dp[j] += dp[j - i] % mod;
        }
    }
    return dp[sum] % mod;
}
