void bfs(vector<vector<bool>> &edge, vector<int> &dist)
{
    queue<int> q;
    q.push(1);
    dist[1] = 0;

    while (!q.empty())
    {
        int k = q.front();
        q.pop();

        for (int i = 1; i <= 100; i++)
        {
            if (edge[k][i] && dist[i] == -1)
            {
                q.push(i);
                dist[i] = dist[k] + 1;
            }
        }
    }
}

int snakeLadder(vector<vector<int>> &A, vector<vector<int>> &B)
{
    vector<vector<bool>> edge(101, vector<bool>(101, 0));
    unordered_map<int, int> jump;

    for (int i = 0; i < A.size(); i++)
    {
        jump[A[i][0]] = A[i][1] - A[i][0];
    }
    for (int j = 0; j < B.size(); j++)
    {
        jump[B[j][0]] = B[j][1] - B[j][0];
    }

    for (int i = 1; i <= 100; i++)
    {
        for (int dice = 1; dice <= 6; dice++)
        {
            int j = i + dice + jump[i + dice];
            if (j <= 100)
            {
                edge[i][j] = 1;
            }
        }
    }
    vector<int> dist(101, -1);
    bfs(edge, dist);
    return dist[100];
}