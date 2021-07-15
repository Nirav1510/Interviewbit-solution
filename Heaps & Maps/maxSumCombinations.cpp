typedef long long int ll;
vector<int> solve(vector<int> &A, vector<int> &B, int C)
{
    int n = A.size();
    sort(A.rbegin(), A.rend());
    sort(B.rbegin(), B.rend());
    priority_queue<ll, vector<ll>, greater<ll>> p;

    for (int i = 0; i < C; i++)
    {
        int sum = A[i] + B[i];
        p.push(sum);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int sum = A[i] + B[j];
            if (i != j)
            {
                if (sum > p.top())
                {
                    p.pop();
                    p.push(sum);
                }
                else
                    break;
            }
        }
    }
    vector<int> ans;
    for (int i = 0; i < C; i++)
    {
        ans.push_back(p.top());
        p.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
