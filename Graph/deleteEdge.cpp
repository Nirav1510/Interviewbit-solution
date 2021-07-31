#define M 1000000007
#define ll long long int

void dfs(vector<int> adj[], int src, int parent, ll &ans, ll sum, vector<int> &A)
{
    int x = A[src - 1];
    for (auto nbr : adj[src])
    {
        if (nbr != parent)
        {
            dfs(adj, nbr, src, ans, sum, A);
            x += A[nbr - 1];
        }
    }
    A[src - 1] = x;
    if (src == 1)
        return;
    ans = max(ans, (x * (sum - x)) % M) % M;
}

int Solution::deleteEdge(vector<int> &A, vector<vector<int>> &B)
{
    int n = A.size();
    vector<int> adj[n + 1];
    for (auto &x : B)
    {
        adj[x[0]].push_back(x[1]);
        adj[x[1]].push_back(x[0]);
    }
    ll totalsum = 0;
    for (auto &x : A)
    {
        totalsum += x;
    }
    ll ans = 0;
    dfs(adj, 1, 0, ans, totalsum, A);
    return ans;
}
