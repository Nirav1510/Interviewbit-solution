bool isSubSequence(string A, string B)
{
    int n = A.length(), m = B.length();
    int j = 0;
    for (int i = 0; i < m; i++)
    {
        if (A[j] == B[i])
        {
            j++;
        }
    }
    return (j == n);
}