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
//method 2
int findPivot(const vector<int> &A)
{
    int l = 0, h = A.size() - 1;
    while (l <= h)
    {
        int mid = h - (h - l) / 2;
        if (A[mid] > A[0])
            l = mid + 1;
        else
            h = mid - 1;
    }
    return h;
}
int isPresent(const vector<int> &A, int l, int h, int val)
{

    while (l <= h)
    {
        int mid = h - (h - l) / 2;
        if (A[mid] == val)
            return mid;
        else if (A[mid] < val)
            l = mid + 1;
        else
            h = mid - 1;
    }
    return -1;
}
int search1(const vector<int> &A, int B)
{
    int pivot = findPivot(A);
    if (B == A[pivot])
        return pivot;
    else if (B < A[0])
        return isPresent(A, pivot + 1, A.size() - 1, B);
    else
        return isPresent(A, 0, pivot, B);
}
int main()
{
    vector<int> A = {10, 20, 50, 40, 60, 90, 30};
    int b;
    cin >> b;
    int res = search(A, b);
    int res1 = search1(A, b);
    cout << res << endl;
    cout << res1 << endl;

    return 0;
}
