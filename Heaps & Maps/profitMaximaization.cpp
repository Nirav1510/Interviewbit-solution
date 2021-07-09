int solve(vector<int> &A, int B)
{
    int ans = 0;
    priority_queue<int> p;
    for (auto i : A)
    {
        p.push(i);
    }

    while (B--)
    {
        int c = p.top();
        ans += c;
        p.pop();
        p.push(--c);
    }
    return ans;
}