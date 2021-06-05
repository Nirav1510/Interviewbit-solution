vector<vector<int>> Solution::anagrams(const vector<string> &A)
{
    vector<vector<int>> ans;
    unordered_map<string, vector<int>> m;

    for (int i = 0; i < A.size(); i++)
    {
        string temp = A[i];
        sort(temp.begin(), temp.end());

        m[temp].push_back(i + 1);
    }

    for (auto i : m)
    {
        ans.push_back(i.second);
    }
    return ans;
}
