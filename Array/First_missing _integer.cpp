#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int firstMissingPositive(vector<int> &a)
{
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        if (a[i] > 0 && a[i] < n)
        {
            if (a[a[i] - 1] != a[i])
            {
                swap(a[a[i] - 1], a[i]);
                i--;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] != i + 1)
            return i + 1;
    }
    return n + 1;
}

int main()
{
    vector<int> a = {3, 4, -1, 1};
    int res = firstMissingPositive(a);

    cout << res << endl;
    return 0;
}