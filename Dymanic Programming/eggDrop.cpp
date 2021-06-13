int dp[101][10001];

int superEggDropHelp(int e, int f)
{
    if (e == 1 || f == 0 || f == 1)
        return f;

    if (dp[e][f] == -1)
    {
        int low = 1, high = f;
        int ans = INT_MAX;
        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (dp[e - 1][mid - 1] == -1)
                dp[e - 1][mid - 1] = superEggDropHelp(e - 1, mid - 1);

            if (dp[e][f - mid] == -1)
                dp[e][f - mid] = superEggDropHelp(e, f - mid);

            int temp = max(1 + dp[e - 1][mid - 1], 1 + dp[e][f - mid]);

            if (dp[e - 1][mid - 1] < dp[e][f - mid])
                low = mid + 1;

            else
                high = mid - 1;

            ans = min(ans, temp);
        }

        dp[e][f] = ans;
    }
    return dp[e][f];
}

int Solution::solve(int e, int f)
{
    memset(dp, -1, sizeof(dp));
    int res = superEggDropHelp(e, f);

    return res;
}
