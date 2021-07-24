vector<vector<int>> adj;
int d;
int diameter(int src)
{
    int curr = 0;
    for (auto nbr : adj[src])
    {
        int dist = diameter(nbr);
        d = max(d, curr + dist);
        curr = max(dist, curr);
    }
    return curr + 1;
}

int Solution::solve(vector<int> &A)
{
    int V = A.size();
    adj.clear();

    adj.resize(V);

    int root = 0;
    for (int i = 0; i < V; i++)
    {
        if (A[i] != -1)
        {
            adj[A[i]].push_back(i);
        }
        else
        {
            root = A[i];
        }
    }
    d = 0;
    diameter(root);

    return d;
}
