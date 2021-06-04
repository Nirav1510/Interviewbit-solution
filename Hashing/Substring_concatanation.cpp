#include <bits/stdc++.h>
#define ll long long int
using namespace std;

vector<int> findSubstring(string A, const vector<string> &B)
{
    int l = A.length();
    int m = B.size();
    int n = B[0].length();
    vector<int> ans;

    if (l < (m * n))
    {
        return ans;
    }
    unordered_map<string, int> word;
    for (string s : B)
    {
        word[s]++;
    }

    for (int i = 0; i <= l - (m * n); i++)
    {
        unordered_map<string, int> wordused;

        for (int j = i; j < i + (m * n); j += n)
        {
            string s = A.substr(j, n);

            if (word.find(s) == word.end())
            {
                break;
            }

            wordused[s]++;

            if (wordused[s] > word[s])
            {
                break;
            }
        }
        if (wordused == word)
        {
            ans.push_back(i);
        }
    }
    return ans;
}

int main()
{
    string A = "barfoothefoobarman";
    vector<string> B = {"foo", "bar"};
    vector<int> res = findSubstring(A, B);

    for (auto i : res)
    {
        cout << i << " ";
    }
    return 0;
}
