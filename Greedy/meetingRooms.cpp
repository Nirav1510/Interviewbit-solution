int solve(vector<vector<int>> &A)
{

    int n = A.size();
    vector<int> start(n), finish(n);
    for (int i = 0; i < n; i++)
    {
        start[i] = A[i][0];
        finish[i] = A[i][1];
    }
    sort(start.begin(), start.end());
    sort(finish.begin(), finish.end());
    int i = 0, j = 0, ans = 0;
    while (i < n && j < n)
    {
        if (start[i] < finish[j])
        {
            ans++;
            i++;
        }
        else
        {
            i++;
            j++;
        }
        //ans=max(ans,room);
    }
    return ans;
}
