//peak element

int solve(vector<int> &a)
{
    int l = 0, h = a.size() - 1;
    while (l < h)
    {
        int mid = l + (h - l) / 2;
        if (a[mid] > a[mid + 1])
            h = mid;
        else
            l = mid + 1;
    }
    return a[l];
}

// peak index

int findPeakElement(vector<int> &a)
{
    int n = a.size();
    if (n <= 1)
    {
        return 0;
    }
    else if (n == 1)
    {
        return (a[0] > a[1] ? 0 : 1);
    }
    int i = 0, j = n - 1;
    while (i <= j)
    {
        int mid = i + (j - i) / 2;
        if (mid > 0 && mid < n - 1)
        {
            if (a[mid] > a[mid - 1] && a[mid] > a[mid + 1])
            {
                return mid;
            }
            else if (a[mid + 1] > a[mid])
            {
                i = mid + 1;
            }
            else
            {
                j = mid - 1;
            }
        }
        else if (mid == 0)
        {
            return (a[0] > a[1] ? 0 : 1);
        }
        else if (mid == n - 1)
        {
            return (a[n - 1] > a[n - 2] ? n - 1 : n - 2);
        }
    }
    return -1;
}