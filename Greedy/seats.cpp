int Solution::seats(string A)
{
    vector<int> v;
    int ans = 0;
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] == 'x')
        {
            v.push_back(i);
        }
    }
    int mid = v.size() / 2;
    int res = 0;
    for (int i = 0; i < v.size(); i++)
    {
        int start = v[i];
        int dest = v[mid] - (mid - i);
        res = (res + abs(dest - start)) % 10000003;
    }
    return res;
}
