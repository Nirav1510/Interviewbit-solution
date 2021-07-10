int nchoc(int A, vector<int> &B)
{
    int ans = 0;
    priority_queue<long long int> p;
    for (auto i : B)
    {
        p.push(i);
    }
    while (A--)
    {
        int temp = p.top();
        p.pop();
        ans = ans % (1000000007) + temp % (1000000007);
        p.push(temp / 2);
    }
    return (ans % (1000000007));
}
