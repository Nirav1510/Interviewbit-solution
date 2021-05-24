#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int largestRectangleArea(vector<int> &A)
{
    int n = A.size();
    if (n == 1)
        return A[0];
    vector<int> left;
    vector<int> right;
    stack<pair<int, int>> s;
    //nearest smallest left
    for (int i = 0; i < n; i++)
    {
        if (s.empty())
            left.push_back(-1);
        else if (!s.empty() && s.top().first < A[i])
            left.push_back(s.top().second);
        else if (!s.empty() && s.top().first >= A[i])
        {
            while (!s.empty() && s.top().first >= A[i])
            {
                s.pop();
            }
            if (s.empty())
                left.push_back(-1);
            else
                left.push_back(s.top().second);
        }
        s.push({A[i], i});
    }
    while (!s.empty())
    {
        s.pop();
    }
    //nearest smallest right
    for (int i = n - 1; i >= 0; i--)
    {
        if (s.empty())
        {
            right.push_back(n);
        }
        else if (!s.empty() && s.top().first < A[i])
        {
            right.push_back(s.top().second);
        }
        else if (!s.empty() && s.top().first >= A[i])
        {
            while (!s.empty() && s.top().first >= A[i])
            {
                s.pop();
            }
            if (s.empty())
            {
                right.push_back(n);
            }
            else
            {
                right.push_back(s.top().second);
            }
        }
        s.push({A[i], i});
    }
    reverse(right.begin(), right.end());
    //calculating area
    int area = 0;
    for (int i = 0; i < n; i++)
    {
        left[i] = right[i] - left[i] - 1;
        area = max(area, left[i] * A[i]);
    }
    return area;
}

int main(){
    vector<int> A={2, 1, 5, 6, 15, 3,7,4,10};
    int res=largestRectangleArea(A);

    cout<<res<<endl;
    return 0;
}