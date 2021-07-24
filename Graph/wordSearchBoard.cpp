bool search(int i, int j, int k, vector<string> &v, string &s)
{
    if (k >= s.length())
        return true;
    if (i < 0 || j < 0 || i >= v.size() || j >= v[0].size() || v[i][j] != s[k])
        return false;
    return search(i - 1, j, k + 1, v, s) || search(i, j + 1, k + 1, v, s) || search(i + 1, j, k + 1, v, s) || search(i, j - 1, k + 1, v, s);
}
int Solution::exist(vector<string> &A, string B)
{

    int n = A.size();
    int m = A[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (search(i, j, 0, A, B))
                return true;
        }
    }
    return false;
}