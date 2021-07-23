void dfs(int i, int j, int n, int m, vector<string> &A)
{
    if (i >= 0 and i < n and j >= 0 and j < m and A[i][j] == 'X')
    {
        A[i][j] = '#';

        dfs(i + 1, j, n, m, A);
        dfs(i - 1, j, n, m, A);
        dfs(i, j - 1, n, m, A);
        dfs(i, j + 1, n, m, A);
    }
}

int black(vector<string> &A)
{
    int n = A.size();
    int m = A[0].size();
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (A[i][j] == 'X')
            {
                ans++;
                dfs(i, j, n, m, A);
            }
        }
    }
    return ans;
}