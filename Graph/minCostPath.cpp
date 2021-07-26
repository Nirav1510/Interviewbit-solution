int get(char c)
{
    if (c == 'U')
        return 0;
    if (c == 'R')
        return 1;
    if (c == 'D')
        return 2;
    return 3;
}
int Solution::solve(int A, int B, vector<string> &C)
{
    int ex = A - 1;
    int ey = B - 1;
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;
    q.push({0, get(C[0][0]), 0, 0});
    vector<vector<int>> visited(A, vector<int>(B, INT_MAX));
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    visited[0][0] = 0;
    int ans = INT_MAX;

    while (!q.empty())
    {
        auto f = q.top();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int x = f[2] + dx[i];
            int y = f[3] + dy[i];

            if (x >= 0 && y >= 0 && x < A && y < B)
            {

                if (i == f[1])
                {
                    if (visited[x][y] > visited[f[2]][f[3]])
                    {
                        visited[x][y] = visited[f[2]][f[3]];
                        q.push({visited[x][y], get(C[x][y]), x, y});
                    }
                }
                else
                {
                    if (visited[x][y] > visited[f[2]][f[3]] + 1)
                    {
                        visited[x][y] = visited[f[2]][f[3]] + 1;
                        q.push({visited[x][y], get(C[x][y]), x, y});
                    }
                }
            }
        }
    }
    return visited[A - 1][B - 1];
}