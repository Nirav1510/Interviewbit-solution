int dfs(int src, int curr, vector<int> &A, int c, vector<vector<int>> &adj, vector<int> &vis)
{
    vis[src] = 1;
    int ans = 0;
    bool isLeaf = 1;
    if (A[src])
        curr++;
    if (curr > c)
        return 0;

    for (auto nbr : adj[src])
    {
        if (!vis[nbr])
        {
            isLeaf = 0;
            ans += dfs(nbr, curr, A, c, adj, vis);
        }
    }
    if (isLeaf)
        return 1;
    return ans;
}

int Solution::solve(vector<int> &A, vector<vector<int>> &B, int C)
{

    int V = A.size();
    vector<vector<int>> adj(V + 1);
    vector<int> vis(V + 1, 0);
    for (auto it : B)
    {
        adj[it[0] - 1].push_back(it[1] - 1);
        adj[it[1] - 1].push_back(it[0] - 1);
    }

    return dfs(0, 0, A, C, adj, vis);
}
