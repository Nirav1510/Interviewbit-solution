#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(vector<int> &A, vector<int> &op, vector<int> &freq, vector<vector<int>> &ans)
{
    if (op.size() == A.size())
    {
        ans.push_back(op);
        return;
    }
    for (int i = 0; i < A.size(); i++)
    {
        if (!freq[i])
        {
            op.push_back(A[i]);
            freq[i] = 1;
            solve(A, op, freq, ans);
            freq[i] = 0;
            op.pop_back();
        }
    }
}

vector<vector<int>> permute(vector<int> &A)
{
    vector<vector<int>> ans;
    vector<int> op;
    int n = A.size();
    vector<int> freq(n);
    for (int i = 0; i < n; i++)
    {
        freq[i] = 0;
    }
    solve(A, op, freq, ans);
    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{
    vector<int> A = {1, 5, 6, 8};
    vector<vector<int>> res = permute(A);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}