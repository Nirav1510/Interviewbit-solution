#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int search(const vector<int> &A, int B)
{
    int n = A.size();
    int left = 0, right = n - 1;

    while (left <= right)
    {

        int mid = left + (right - left) / 2;
        if (A[mid] == B)
        {
            return mid;
        }
        else if (A[mid] > A[left])
        {
            if (A[mid] >= B && A[left] <= B)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        else
        {
            if (A[right] >= B && A[mid] <= B)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
    }
    return -1;
}
int main()
{
    vector<int> A = {10, 20, 50, 40, 60, 90, 30};
    int b;
    cin >> b;
    int res = search(A, b);
    cout << res << endl;

    return 0;
}