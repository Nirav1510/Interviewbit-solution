#include<bits/stdc++.h>
#define pii pair<int, int>
using namespace std;
vector<vector<pii>> adj;
vector<bool> vis;
//prims algo
int prims(int A, vector<vector<int>> &B)
{

    adj.clear();
    vis.clear();

    adj.resize(A + 1);
    vis.resize(A + 1);

    vis.assign(A + 1, 0);

    for (auto it : B)
    {
        adj[it[0] - 1].push_back({it[1] - 1, it[2]});
        adj[it[1] - 1].push_back({it[0] - 1, it[2]});
    }
    int ans = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    int src = 0;
    pq.push({0, src}); //(wt,node);

    while (!pq.empty())
    {
        auto best = pq.top();
        pq.pop();

        int to = best.second;
        int wt = best.first;

        if (vis[to])
        {
            continue;
        }

        ans += wt;
        vis[to] = 1;

        for (auto nbr : adj[to])
        {
            if (!vis[nbr.first])
            {
                pq.push({nbr.second, nbr.first});
            }
        }
    }
    return ans;
}

//Kruksal's Algo

vector<int> parent(100005), sizze(100005);
int findpar(int node)
{
    if (parent[node] == -1)
        return node;
    return parent[node] = findpar(parent[node]);
}
void unionn(int u, int v)
{
    int paru = findpar(u);
    int parv = findpar(v);
    if (sizze[u] < sizze[v])
    {
        parent[paru] = parv;
        sizze[v] += sizze[u];
    }
    else
    {
        parent[parv] = paru;
        sizze[u] += sizze[v];
    }
}
int kruksal(int A, vector<vector<int>> &B)
{
    parent.clear();
    sizze.clear();
    vector<vector<int>> edgeList;

    for (int i = 0; i < B.size(); i++)
    {
        edgeList.push_back({B[i][2], B[i][0], B[i][1]});
    }

    for (int i = 1; i <= A; i++)
    {
        parent[i] = -1;
        sizze[i] = 1;
    }

    sort(edgeList.begin(), edgeList.end());
    cout << edgeList.size() << endl;
    int ans = 0;
    for (auto it : edgeList)
    {
        int w = it[0];
        int u = it[1];
        int v = it[2];
        if (findpar(u) != findpar(v))
        {
            unionn(u, v);
            ans += w;
        }
    }
    return ans;
}

int main()
{
    int A = 4;
    vector<vector<int>> B = {{1, 2, 1},
                             {2, 3, 2},
                             {3, 4, 4},
                             {1, 4, 3}};

    cout << kruksal(A, B) << endl;
    cout << prims(A, B) << endl;

    return 0;
}