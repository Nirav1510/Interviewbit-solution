#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void helper(int A, vector<int> &res, int size, int num)
{
    if (num == size)
        return; //base

    int pow = num / 2;
    res.push_back(num ^ pow);
    helper(A, res, size, num + 1);
}

vector<int> grayCode(int A)
{
    vector<int> res;
    ll size = pow(2, A);
    helper(A, res, size, 0);
    return res;
}

int main()
{
    int A;
    cin >> A;
    vector<int> ans = grayCode(A);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
    return 0;
}