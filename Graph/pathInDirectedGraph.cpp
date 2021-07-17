bool helper(int target, int src, map<int, vector<int>> &adj, vector<bool> &visited)
{

    if (target == src)
        return true;
    visited[src] = true;

    for (auto nbr : adj[src])
    {
        if (!visited[nbr])
        {
            if (helper(target, nbr, adj, visited))
            {
                return true;
            }
        }
    }
    return false;
}

int solve(int A, vector<vector<int>> &B)
{

    map<int, vector<int>> adj;
    for (auto it : B)
    {
        adj[it[0]].push_back(it[1]);
    }
    vector<bool> visited(A + 1, false);
    return helper(A, 1, adj, visited);
}