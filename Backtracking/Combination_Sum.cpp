#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(int i, int B, vector<int> &A, vector<int> op, vector<vector<int>> &ans)
{
    if (i == A.size())
    {
        if (B == 0)
        {
            //sort(op.begin(),op.end());
            ans.push_back(op);
        }
        return;
    }
    if (A[i] <= B)
    {
        vector<int> op1 = op;
        op1.push_back(A[i]);
        solve(i, B - A[i], A, op1, ans);
        op1.pop_back();
    }
    solve(i + 1, B, A, op, ans);
}

vector<vector<int>> combinationSum(vector<int> &A, int B)
{

    vector<vector<int>> ans;
    vector<int> op;
    sort(A.begin(), A.end());
    solve(0, B, A, op, ans);
    vector<vector<int>> res;
    map<vector<int>, int> m;
    for (int i = 0; i < ans.size(); i++)
    {
        if (m[ans[i]] == 0)
        {
            m[ans[i]]++;
            res.push_back(ans[i]);
        }
    }
    sort(res.begin(), res.end());
    return res;
}

int main()
{
    vector<int> A = {10, 1, 2, 7, 6, 1, 5};
    vector<vector<int>> r = combinationSum(A, 8);
    for (int i = 0; i < r.size(); i++)
    {
        if (r[i].size() > 0)
        {
            cout << " ( ";
            for (int j = 0; j < r[i].size(); j++)
                cout << r[i][j] << " ";
            cout << ")";
        }
    }
    return 0;
}
