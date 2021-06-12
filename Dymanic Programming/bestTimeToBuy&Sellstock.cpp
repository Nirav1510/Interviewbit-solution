int maxProfit(const vector<int> &A)
{
    if (A.size() == 0)
        return 0;
    int ans = 0;
    int minvalue = INT_MAX;
    for (auto i : A)
    {
        minvalue = min(minvalue, i);
        ans = max(ans, i - minvalue);
    }
    return ans;
}
