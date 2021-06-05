int Solution::solve(vector<int> &A)
{
    int n = A.size();
    int sum = 0, ans = 0;
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        if (A[i] == 0)
        {
            sum--;
        }
        else
        {
            sum++;
        }
        if (sum == 1)
        {
            ans = i + 1;
        }
        else if (m.find(sum) == m.end())
        {
            m[sum] = i;
        }
        if (m.find(sum - 1) != m.end())
        {
            ans = max(ans, i - m[sum - 1]);
        }
    }
    return ans;
}
