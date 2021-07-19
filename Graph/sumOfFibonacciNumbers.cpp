int fibsum(int A)
{
    if (A == 0)
        return 0;

    int a = 1, b = 1, sum = 1;
    while (a + b <= A)
    {
        sum = a + b;
        a = b;
        b = sum;
    }
    return 1 + fibsum(A - sum);
}

// using BS
int fibsum(int A)
{
    vector<int> v = {1, 2};
    while (v.back() <= A)
        v.push_back(v[v.size() - 1] + v[v.size() - 2]);
    int ans = 0;
    while (A > 0)
    {
        int index = (lower_bound(v.begin(), v.end(), A) - v.begin());
        ans++;
        if (v[index] == A)
            A = 0;
        else
            A -= v[index - 1];
    }
    return c;
}
