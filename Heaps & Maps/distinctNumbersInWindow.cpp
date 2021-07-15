vector<int> dNums(vector<int> &A, int B)
{
    int i = 0, j = 0;
    unordered_map<int, int> m;
    vector<int> ans;
    while (j < A.size())
    {

        m[A[j]]++;

        if (j - i + 1 < B)
            j++;

        else if (j - i + 1 == B)
        {
            ans.push_back(m.size());
            m[A[i]]--;
            if (m[A[i]] == 0)
            {
                m.erase(A[i]);
            }
            i++;
            j++;
        }
    }
    return ans;
}