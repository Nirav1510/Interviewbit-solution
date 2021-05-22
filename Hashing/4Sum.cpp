#include <bits/stdc++.h>
#define ll long long int
using namespace std;

vector<vector<int>> fourSum(vector<int> &A, int B)
{
    sort(A.begin(), A.end());
    int n = A.size();
    vector<vector<int>> ans;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {

            int temp = B - A[i] - A[j];
            int left = j + 1;
            int right = n - 1;

            while (left < right)
            {
                int sum = A[left] + A[right];

                if (sum < temp)
                    left++;
                else if (sum > temp)
                    right--;
                else
                {
                    vector<int> pair(4, 0);
                    pair[0] = A[i];
                    pair[1] = A[j];
                    pair[2] = A[left];
                    pair[3] = A[right];
                    //sort(pair.begin(),pair.end());
                    ans.push_back(pair);

                    while (left < right && A[left] == pair[2])
                        ++left;
                    while (left < right && A[right] == pair[3])
                        --right;
                }
            }
            while (j < n - 1 && A[j + 1] == A[j])
                ++j;
        }
        while (i < n - 1 && A[i + 1] == A[i])
            ++i;
    }
    //sort(ans.begin(),ans.end());
    return ans;
}

int main()
{

    vector<int> A = {4, 3, 2, 1, 2, 1, 4, 3, 4, 1};
    int B;
    cin >> B;
    vector<vector<int>> res = fourSum(A, B);
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    //cout<<res<<endl;
    return 0;
}
