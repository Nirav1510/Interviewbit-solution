int res;

int dfs(int src, vector<int> adj[], vector<bool> &vis)
{
    vis[src] = 1;
    int currsz = 0;

    for (auto nbr : adj[src])
    {
        if (!vis[nbr])
        {
            int sz = dfs(nbr, adj, vis);
            if (sz % 2 == 0)
            {
                res++;
            }
            else
            {
                currsz += sz;
            }
        }
    }
    return currsz + 1;
}

int Solution::solve(int A, vector<vector<int>> &B)
{
    res = 0;
    vector<int> adj[A];
    vector<bool> vis(A, 0);
    for (auto it : B)
    {
        adj[it[0] - 1].push_back(it[1] - 1);
        adj[it[1] - 1].push_back(it[0] - 1);
    }
    int size = dfs(0, adj, vis);

    return res;
}
