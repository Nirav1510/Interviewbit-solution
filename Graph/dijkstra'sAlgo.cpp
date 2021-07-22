#define pii pair<int, int>
#define INF 100000
vector<int> dijkstra(int V, vector<vector<int>> adj[], int s)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<int> dis(V, INF);

    dis[s] = 0;
    pq.push({0, s}); //(dis,node)

    while (!pq.empty())
    {
        int distance = pq.top().first;
        int prev = pq.top().second;
        pq.pop();

        for (auto nbr : adj[prev])
        {
            int next = nbr[0];
            int nextdis = nbr[1];

            if (dis[next] > dis[prev] + nextdis)
            {
                dis[next] = dis[prev] + nextdis;
                pq.push({dis[prev], next});
            }
        }
    }
    return dis;
}
