//dfs solution

bool check(int node, int parent, int color, vector<int> &vis, vector<int> adj[])
{
    vis[node] = color;

    for (auto nbr : adj[node])
    {
        if (!vis[nbr])
        {
            if (!(check(nbr, node, 3 - color, vis, adj)))
            {
                return false;
            }
        }
        else if (nbr != parent && color == vis[nbr])
        {
            return false;
        }
    }
    return true;
}

bool isBipartite(int V, vector<int> adj[])
{

    vector<int> vis(V + 1, 0);
    int color = 1;
    for (int i = 0; i < V; i++)
    {
        if (vis[i] == 0)
        {
            bool flag = check(i, -1, color, vis, adj);
            if (!flag)
            {
                return false;
            }
        }
    }
    return true;
}

//bfs solution

bool bfsHelper(int src, int color, vector<vector<int>> &graph, vector<int> &visited)
{
    queue<int> q;
    q.push(src);
    visited[src] = color;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        int clr = visited[node];

        for (auto nbr : graph[node])
        {
            if (!visited[nbr])
            {
                q.push(nbr);
                visited[nbr] = 3 - clr;
            }

            else
            {
                if (visited[nbr] == clr)
                    return false;
            }
        }
    }

    return true;
}

bool isBipartite(vector<vector<int>> &graph)
{

    int n = graph.size();
    vector<int> visited(n, 0);

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if (!bfsHelper(i, 1, graph, visited))
                return false;
        }
    }

    return true;
}