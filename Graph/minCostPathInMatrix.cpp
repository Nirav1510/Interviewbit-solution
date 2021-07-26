#define ppi pair<int, pair<int, int>>
bool isValid(int x, int y, int n)
{
    return (x >= 0 && x < n && y >= 0 && y < n);
}

int minimumCostPath(vector<vector<int>> &grid)
{
    int n = grid.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MAX));

    dp[0][0] = grid[0][0];
    int dx[] = {0, 0, -1, 1};
    int dy[] = {1, -1, 0, 0};

    priority_queue<ppi, vector<ppi>, greater<ppi>> pq;

    pq.push({grid[0][0], {0, 0}}); //(cost,(row,col))

    while (!pq.empty())
    {
        auto curr = pq.top();
        pq.pop();

        int i = curr.second.first;
        int j = curr.second.second;

        for (int k = 0; k < 4; k++)
        {
            int r = i + dx[k];
            int c = j + dy[k];

            if (isValid(r, c, n))
            {
                if (dp[i][j] + grid[r][c] < dp[r][c])
                {
                    dp[r][c] = dp[i][j] + grid[r][c];

                    pq.push({dp[r][c], {r, c}});
                }
            }
        }
    }
    return dp[n - 1][n - 1];
}