int Solution::solve(string A)
{
    unordered_set<char> s;
    for (int i = 0; i < A.length(); i++)
    {
        if (s.find(A[i]) != s.end())
        {
            s.erase(A[i]);
        }
        else
        {
            s.insert(A[i]);
        }
    }
    if (s.size() <= 1)
        return 1;
    return 0;
}
