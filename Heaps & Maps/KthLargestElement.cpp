vector<int> solve(vector<int> &A, int B)
{
    // sort(A.begin(),A.end());
    // vector<int> ans;
    // int i = A.size()-1;
    // while(B--) {
    //     ans.push_back(A[i]);
    //     i--;
    // }
    // return ans;
    priority_queue<int, vector<int>, greater<int>> minh;
    int n = A.size();
    for (int i = 0; i < n; i++)
    {
        minh.push(A[i]);
        if (minh.size() > B)
        {
            minh.pop();
        }
    }
    vector<int> ans;
    while (!minh.empty())
    {
        ans.push_back(minh.top());
        minh.pop();
    }
    return ans;
}