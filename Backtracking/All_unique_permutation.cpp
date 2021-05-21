#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void permute(map<int, int>& m, vector<vector<int>>& result, vector<int>& temp, int start) {
    if(start == temp.size()) {
        result.push_back(vector<int>(temp.begin(), temp.end()));
    } 
    else {
        for(auto &x: m) {
            if(x.second > 0) {
                m[x.first] = x.second - 1;
                temp[start] = x.first;
                permute(m, result, temp, start + 1);
                m[x.first] = x.second + 1;
            }
        }
    }
}

vector<vector<int>> uniquePermute(vector<int> &A) {
    vector<vector<int>> result;
        map<int, int> m;
        vector<int> temp(A.size());
        
        for(int num: A)
            m[num]++;
        
        permute(m, result, temp, 0);
        return result;
}

int main()
{
    vector<int> A={2,6,4,2,6};
    vector<vector<int>> res = uniquePermute(A);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}