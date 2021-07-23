void dfs(int src, stack<int> &list, vector<bool> &vis, vector<int> adj[])
{
    vis[src] = 1;

    for (auto nbr : adj[src])
    {
        if (!vis[nbr])
        {
            dfs(nbr, list, vis, adj);
        }
    }
    list.push(src);
}

vector<int> topoSort(int V, vector<int> adj[])
{
    stack<int> list;
    vector<bool> vis(V, 0);

    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            dfs(i, list, vis, adj);
        }
    }
    vector<int> v;
    while (!list.empty())
    {
        v.push_back(list.top());
        list.pop();
    }
    return v;
}

//bfs khan's algo

vector<int> topoSort(int V, vector<int> adj[])
{
    vector<int> res;

    vector<int> inorder(V, 0);
    queue<int> q;

    for (int i = 0; i < V; i++)
    {
        for (int u : adj[i])
        {
            inorder[u]++;
        }
    }

    for (int i = 0; i < V; i++)
    {
        if (inorder[i] == 0)
        {
            q.push(i);
        }
    }

    while (q.empty() == false)
    {
        int u = q.front();

        res.push_back(u);

        for (int v : adj[u])
        {
            inorder[v]--;

            if (inorder[v] == 0)
            {
                q.push(v);
            }
        }

        q.pop();
    }

    return res;
}