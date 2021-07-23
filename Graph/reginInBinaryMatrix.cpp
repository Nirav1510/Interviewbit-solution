//dfs

void dfs(int i, int j, vector<vector<int>> &A, int &count)
{
    if (i >= 0 and i < A.size() and j >= 0 and j < A[0].size() and A[i][j] == 1)
    {
        A[i][j] = 2;
        int rowNbr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int colNbr[] = {-1, 0, 1, -1, 1, -1, 0, 1};

        for (int k = 0; k < 8; k++)
        {
            int r = i + rowNbr[k], c = j + colNbr[k];
            if (r >= 0 and r < A.size() and c >= 0 and c < A[0].size() && A[r][c] == 1)
            {
                count++;
                dfs(r, c, A, count);
            }
        }
    }
}

int Solution::solve(vector<vector<int>> &A)
{
    int n = A.size(), m = A[0].size();

    int res = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (A[i][j] == 1)
            {
                int count = 1;
                dfs(i, j, A, count);
                res = max(res, count);
            }
        }
    }
    return res;
}

//bfs

int Solution::solve(vector<vector<int>> &A)
{
    int n = A.size(), m = A[0].size();
    vector<vector<bool>> vis(n, vector<bool>(m, 0));
    int ans = 0, curr = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && A[i][j] == 1)
            {
                queue<pair<int, int>> q;
                q.push({i, j});
                vis[i][j] = 1;
                curr = 1;
                while (!q.empty())
                {
                    int y = q.front().first, x = q.front().second;
                    q.pop();

                    vector<int> dy({1, 1, 0, -1, -1, -1, 0, 1});
                    vector<int> dx({0, 1, 1, 1, 0, -1, -1, -1});

                    for (int k = 0; k < 8; k++)
                    {
                        if (x + dx[k] >= 0 && x + dx[k] < m && y + dy[k] >= 0 && y + dy[k] < n)
                        {
                            if (!vis[y + dy[k]][x + dx[k]] && A[y + dy[k]][x + dx[k]] == 1)
                            {
                                vis[y + dy[k]][x + dx[k]] = 1;
                                q.push({y + dy[k], x + dx[k]});
                                curr++;
                            }
                        }
                    }
                }

                ans = max(ans, curr);
            }
        }
    }

    return ans;
}