vector<int> Solution::equal(vector<int> &A)
{
    vector<int> ans;
    unordered_map<int, pair<int, int>> m;
    int n = A.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int sum = A[i] + A[j];

            if (m.find(sum) != m.end())
            {
                int a = m[sum].first;
                int b = m[sum].second;
                if (a < b && i < j && a < i && b != i && b != j)
                {
                    vector<int> temp = {a, b, i, j};
                    if (ans.empty() || temp < ans)
                    {
                        ans = temp;
                    }
                }
            }
            else
            {
                m[sum] = {i, j};
            }
        }
    }
    return ans;
}
