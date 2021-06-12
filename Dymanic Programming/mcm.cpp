int dp[101][101];
int solve(int arr[], int i, int j)
{
    if (i >= j)
    {
        return 0;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int mn = INT_MAX;
    for (int k = i; k <= j - 1; k++)
    {
        int temp = solve(arr, i, k) + solve(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];
        mn = min(mn, temp);
    }
    return dp[i][j] = mn;
}

int matrixMultiplication(int n, int arr[])
{

    memset(dp, -1, sizeof(dp));
    int ans = solve(arr, 1, n - 1);

    return ans;
}