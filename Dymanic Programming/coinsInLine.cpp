int dp[501][501];

int solve(int i, int j, vector<int> A, int sum)
{
    if (i + 1 == j)
    {
        return max(A[i], A[j]);
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    dp[i][j] = max(sum - solve(i + 1, j, A, sum - A[i]), sum - solve(i, j - 1, A, sum - A[j]));

    return dp[i][j];
}

int Solution::maxcoin(vector<int> &A)
{
    int n = A.size();
    int sum = 0;
    for (auto i : A)
    {
        sum += i;
    }
    memset(dp, -1, sizeof(dp));
    return solve(0, n - 1, A, sum);
}
