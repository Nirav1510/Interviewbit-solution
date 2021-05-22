#include <bits/stdc++.h>
#define ll long long int
using namespace std;

vector<int> twoSum(const vector<int> &A, int B)
{
    vector<int> ans;
    unordered_map<int, int> m;
    for (int i = 0; i < A.size(); i++)
    {
        if (m.find(B - A[i]) != m.end())
        {
            ans.push_back(m[B - A[i]] + 1);
            ans.push_back(i + 1);
            return ans;
        }
        if (m.find(A[i]) == m.end())
        {
            m[A[i]] = i;
        }
    }
    return ans;
}

int main()
{

    vector<int> A = {2, 7, 11, 15};
    int B;
    cin >> B;
    vector<int> res = twoSum(A, B);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}
