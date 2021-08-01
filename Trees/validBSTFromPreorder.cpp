int Solution::solve(vector<int> &arr)
{
    int root = INT_MIN;
    stack<int> s;
    for (int i = 0; i < arr.size(); i++)
    {

        if (arr[i] < root)
        {
            return 0;
        }

        while (!s.empty() && s.top() < arr[i])
        {
            root = s.top();
            s.pop();
        }

        s.push(arr[i]);
    }
    return 1;
}