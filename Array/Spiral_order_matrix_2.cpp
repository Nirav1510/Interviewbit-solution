#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<vector<int>> generateMatrix(int A)
{
    vector<vector<int>> ans(A, vector<int>(A));
    int val = 1;
    int k = 0; // row index
    int l = 0; // column index
    int m = A, n = A;

    while (k < m && l < n)
    {
        for (int i = l; i < n; i++)
        {
            ans[k][i] = val;
            val++;
        }
        k++;

        for (int i = k; i < m; i++)
        {
            ans[i][n - 1] = val;
            val++;
        }
        n--;

        if (k < m)
        {
            for (int i = n - 1; i >= l; i--)
            {
                ans[m - 1][i] = val;
                val++;
            }
            m--;
        }
        if (l < n)
        {
            for (int i = m - 1; i >= k; i--)
            {
                ans[i][l] = val;
                val++;
            }
            l++;
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> res = generateMatrix(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}