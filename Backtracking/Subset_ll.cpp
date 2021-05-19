void subset(vector<int> ip, vector<int> op, vector<vector<int>> &v)
{
    if (ip.size() == 0)
    {
        sort(op.begin(), op.end());
        v.push_back(op);
        return;
    }
    vector<int> op1 = op;
    vector<int> op2 = op;

    op2.push_back(ip[0]);
    ip.erase(ip.begin() + 0);

    subset(ip, op1, v);
    subset(ip, op2, v);
}

vector<vector<int>> subsetsWithDup(vector<int> &A)
{
    vector<vector<int>> v;
    vector<int> op;
    subset(A, op, v);
    vector<vector<int>> ans;
    map<vector<int>, int> m;
    for (int i = 0; i < v.size(); i++)
    {
        if (m[v[i]] == 0)
        {
            m[v[i]]++;
            ans.push_back(v[i]);
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}
