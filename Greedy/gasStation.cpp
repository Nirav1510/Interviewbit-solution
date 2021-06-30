int canCompleteCircuit(const vector<int> &gas, const vector<int> &cost)
{
    int g = 0, c = 0, start = 0, i, n = gas.size(), count = 0;
    for (i = 0; i < n; i++)
    {
        g += gas[i];
        c += cost[i];
    }
    if (g < c)
        return -1;
    g = 0;
    c = 0, i = 0;
    while (count < n)
    {
        g = g + gas[i];
        c = c + cost[i];
        count++;
        if (c > g)
        {
            g = 0;
            c = 0;
            count = 0;
            start = (i + 1) % n;
        }
        i = (i + 1) % n;
    }
    return start;
}