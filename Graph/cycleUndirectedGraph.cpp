bool dfs(int node, vector<int> adj[], vector<bool> &visited, int parent)
{
    visited[node] = true;
    for (auto nbr : adj[node])
    {
        if (nbr != parent && visited[nbr])
        {
            return true;
        }
        if (!visited[nbr] && dfs(nbr, adj, visited, node))
        {
            return true;
        }
    }
    return false;
}

int solve(int A, vector<vector<int>> &B)
{
    vector<int> adj[A + 1];
    vector<bool> visited(A + 1, false);
    for (int i = 0; i < B.size(); i++)
    {
        adj[B[i][0]].push_back(B[i][1]);
        adj[B[i][1]].push_back(B[i][0]);
    }
    for (int i = 1; i <= A; i++)
    {
        if (!visited[i] && dfs(i, adj, visited, -1))
            return 1;
    }

    return 0;
}
