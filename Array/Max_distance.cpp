#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int maxDistance(vector<int> &A)
{
    int n = A.size();
    int r[n]; //r = right max of array
    r[n - 1] = A[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        r[i] = max(r[i + 1], A[i]);
    }
    int ans = 0, i = 0, j = 0;
    while (i < n && j < n)
    {
        if (A[i] <= r[j])
        {
            ans = max(ans, j - i);
            j++;
        }
        else
        {
            i++;
        }
    }
    return ans;
}
int main()
{

    vector<int> A = {3, 5, 4, 1, 8, 2, 7};
    int res = maxDistance(A);
    cout << res << endl;
    return 0;
}
