#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &A)
{
    unordered_map<int, int> m;
    for (int i = 0; i < A.size(); i++)
    {
        if (m.find(A[i]) != m.end())
        {
            int index = m[A[i]];
            A[index]++;
            m[A[index]] = index;
        }
        m[A[i]] = i;
    }
    return A;
}

int main()
{
    vector<int> A = {1, 3, 4, 5, 2, 3, 2, 4, 6, 7, 6, 3, 2, 1, 6, 9};
    vector<int> res = solve(A);

    for (auto i : res)
    {
        cout << i << " ";
    }
    return 0;
}