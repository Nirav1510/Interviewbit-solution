#define pii pair<int, int>
int spanningTree(int V, vector<vector<int>> adj[])
{
    priority_queue<pii, vector<pii>, greater<pii>> q;
    int source = 0;
    q.push({0, source}); //(wt,node)
    int cost = 0;

    vector<bool> vis(V, 0);

    while (!q.empty())
    {
        auto best = q.top();
        q.pop();

        int node = best.second;
        int wt = best.first;

        if (vis[node])
        {
            continue;
        }

        cost += wt;
        vis[to] = 1;

        for (auto nbr : adj[node])
        {
            if (!vis[nbr[0]])
            {
                q.push({nbr[1], nbr[0]});
            }
        }
    }
    return cost;
}