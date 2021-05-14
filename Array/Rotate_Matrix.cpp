#include <bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>> &A)
{
    int n = A.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(A[i][j], A[j][i]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        reverse(A[i].begin(), A[i].end());
    }
}

int main()
{
    vector<vector<int>> A = {{1, 2},
                             {3, 4}};
    solve(A);
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < A.size(); j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}