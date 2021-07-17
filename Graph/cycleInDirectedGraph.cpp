// unordered_map<int, vector<int> > adj;

bool isCycle(int node, vector<bool> &vis, vector<bool> &stack, vector<vector<int>> &adj)
{

    vis[node] = true;
    stack[node] = true;

    for (int nbr : adj[node])
    {
        if (stack[nbr] == true)
        {
            return true;
        }
        else if (vis[nbr] == false)
        {
            if (isCycle(nbr, vis, stack, adj))
            {
                return true;
            }
        }
    }
    // for(auto nbr : adj[node]){
    //     if(vis[nbr] && stack[nbr])
    //         return 1;

    //     else if(!vis[nbr]){
    //         if(isCycle(nbr,vis,stack))
    //             return 1;
    //     }
    // }
    stack[node] = false;
    return false;
}

int solve(int A, vector<vector<int>> &B)
{

    // adj.clear();
    vector<vector<int>> adj(A + 1);
    for (int i = 0; i < B.size(); i++)
    {
        adj[B[i][0]].push_back(B[i][1]);
    }
    vector<bool> vis(A + 1, 0);
    vector<bool> stack(A + 1, 0);

    for (int i = 1; i <= A; i++)
    {
        if (!vis[i])
        {
            if (isCycle(i, vis, stack, adj))
            {
                return 1;
            }
        }
    }
    return 0;
}
