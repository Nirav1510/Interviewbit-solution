#include <bits/stdc++.h>
#define ll long long int
using namespace std;

bool isPalindrome(string s)
{
    int i = 0, j = s.length() - 1;
    while (i < j)
    {
        if (s[i] != s[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

void solve(string A, vector<string> &op, vector<vector<string>> &ans)
{
    if (A.length() <= 0)
    {
        ans.push_back(op);
        return;
    }

    int n = A.length();
    for (int i = 0; i < n; i++)
    {

        string copyString = A;
        string firstPart = A.substr(0, i + 1);
        string secondPart = A.substr(i + 1, n - i);

        if (isPalindrome(firstPart))
        {
            op.push_back(firstPart);
            solve(secondPart, op, ans);
            // backtrack
            op.pop_back();
        }
    }
}

vector<vector<string>> partition(string A)
{
    vector<vector<string>> ans;
    vector<string> op;
    solve(A, op, ans);
    //sort(ans.begin(), ans.end());
    return ans;
}

int main()
{
    string st;
    cin >> st;
    vector<vector<string>> res = partition(st);
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