int Solution::solve(vector<int> &A, int B)
{
    unordered_map<int, int> m;
    int sum = 0, ans = 0;

    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] % 2)
            A[i] = 1;
        else
            A[i] = 0;
    }
    for (int i = 0; i < A.size(); i++)
    {
        sum += A[i];
        if (sum == B)
            ans++;
        if (m.find(sum - B) != m.end())
        {
            ans += m[sum - B];
        }
        m[sum]++;
    }
    return ans;
}
