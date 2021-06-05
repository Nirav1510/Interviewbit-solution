int Solution::solve(vector<int> &A, int B, int C)
{
    unordered_map<int, int> m;
    int sum = 0, ans = 0;
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] == B)
        {
            sum += 1;
        }
        else if (A[i] == C)
        {
            sum -= 1;
        }
        if (sum == 0)
        {
            ans++;
        }
        if (m.find(sum) != m.end())
        {
            ans += m[sum];
        }
        m[sum]++;
    }
    return ans;
}
