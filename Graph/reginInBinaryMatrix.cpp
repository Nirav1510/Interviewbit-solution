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

bool isSafe(vector<vector<int>> &A, int i, int j, int n, int m)
{
    if (i >= 0 && i < n && j >= 0 && j < m && A[i][j] == 1)
        return true;
    return false;
}
int bfs(vector<vector<int>> &A, int x, int y, int n, int m)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    int X[] = {0, 0, 1, -1, 1, 1, -1, -1};
    int Y[] = {1, -1, 0, 0, -1, 1, 1, -1};
    int c = 0, newX, newY, i;
    A[x][y] = 0;
    while (!q.empty())
    {
        pair<int, int> temp = q.front();
        q.pop();
        c++;
        for (i = 0; i < 8; i++)
        {
            newX = X[i] + temp.first;
            newY = Y[i] + temp.second;
            if (isSafe(A, newX, newY, n, m))
            {
                A[newX][newY] = 0;
                q.push({newX, newY});
            }
        }
    }
    return c;
}
int Solution::solve(vector<vector<int>> &A)
{

    int n = A.size();
    int m = A[0].size();
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (A[i][j] == 1)
            {
                ans = max(ans, bfs(A, i, j, n, m));
            }
        }
    }
    return ans;
}