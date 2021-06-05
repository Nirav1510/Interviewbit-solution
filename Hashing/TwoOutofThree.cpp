vector<int> Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C)
{
    unordered_map<int, int> mp;
    vector<int> ans;

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());

    for (int i = 0; i < A.size(); i++)
    {
        if (i > 0 && A[i - 1] == A[i])
            continue;

        mp[A[i]]++;
        ans.push_back(A[i]);
    }

    for (int i = 0; i < B.size(); i++)
    {
        if (i > 0 && B[i - 1] == B[i])
            continue;

        mp[B[i]]++;
        ans.push_back(B[i]);
    }

    for (int i = 0; i < C.size(); i++)
    {
        if (i > 0 && C[i - 1] == C[i])
            continue;

        mp[C[i]]++;
        ans.push_back(C[i]);
    }

    vector<int> res;

    sort(ans.begin(), ans.end());

    for (int i = 0; i < ans.size(); i++)
    {
        if (i > 0 && ans[i - 1] == ans[i])
            continue;

        if (mp[ans[i]] > 1)
            res.push_back(ans[i]);
    }

    return res;
}

// Method 2

vector<int> Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C)
{
    vector<int> ans;
    unordered_map<int, set<int>> m;

    for (auto i : A)
    {
        m[i].insert(1);
    }
    for (auto i : B)
    {
        m[i].insert(2);
    }
    for (auto i : C)
    {
        m[i].insert(3);
    }

    for (auto i : m)
    {
        if (i.second.size() > 1)
        {
            ans.push_back(i.first);
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}
