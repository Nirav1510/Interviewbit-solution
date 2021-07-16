//Topological sort and BFS

int solve(int V, vector<int> &B, vector<int> &C)
{
    vector<vector<int>> adj(V);
    for (int i = 0; i < C.size(); i++)
    {
        adj[B[i] - 1].push_back(C[i] - 1);
    }
    vector<int> indegree(V, 0);
    for (int i = 0; i < V; i++)
    {
        for (auto nbr : adj[i])
        {
            indegree[nbr]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    //vector<int> toposort;
    int count = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        //toposort.push_back(node);
        for (auto nbr : adj[node])
        {
            if (indegree[nbr] > 0)
            {
                indegree[nbr]--;
                if (indegree[nbr] == 0)
                {
                    q.push(nbr);
                }
            }
        }
        count++;
    }
    return count == indegree.size();
}

//DFS

bool dfs(vector<bool> &done, vector<bool> &vis, vector<vector<int>> &adj, int node)
{
    vis[node] = true;
    bool ok = true;
    for (int e : adj[node])
    {
        if (vis[e] && !done[e])
            return false;
        if (!vis[e])
        {
            ok = ok & dfs(done, vis, adj, e);
        }
    }
    done[node] = true;
    return ok;
}
int solve(int A, vector<int> &B, vector<int> &C)
{
    vector<vector<int>> adj(A + 1);
    for (int i = 0; i < C.size(); i++)
    {
        adj[B[i]].push_back(C[i]);
    }
    vector<bool> done(A + 1), vis(A + 1);
    int n = A;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            bool canGo = dfs(done, vis, adj, i);
            if (!canGo)
                return 0;
        }
    }
    return 1;
}