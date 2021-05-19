void subset(vector<int> ip, vector<int> op, vector<vector<int>> &ans)
{
    if (ip.size() == 0)
    {
        sort(op.begin(), op.end());
        ans.push_back(op);
        return;
    }
    vector<int> op1 = op;
    vector<int> op2 = op;
    op2.push_back(ip[0]);
    ip.erase(ip.begin() + 0);

    subset(ip, op1, ans);
    subset(ip, op2, ans);
}

vector<vector<int>> subsets(vector<int> &A)
{
    vector<vector<int>> ans;
    vector<int> op;
    subset(A, op, ans);
    sort(ans.begin(), ans.end());

    return ans;
}
