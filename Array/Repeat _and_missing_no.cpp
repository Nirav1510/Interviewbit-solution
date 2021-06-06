#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
//method 1 maths

vector<int> repeatedNumber(const vector<int> &A)
{
    long long int n = A.size();
    long long int s = (n * (n + 1)) / 2;
    long long int sq = (n * (n + 1) * (2 * n + 1)) / 6;

    long long int sa = 0, sqa = 0;
    for (auto i : A)
    {
        sa += (long long int)i;
        sqa += (long long int)i * i;
    }
    long long int t1 = s - sa;
    long long int t2 = (sq - sqa) / t1;
    vector<int> ans;
    ans.push_back((t2 - t1) / 2);
    ans.push_back((t2 + t1) / 2);
    return ans;
}

//method 2 bit-wise xor
vector<int> repeatedNumber2(const vector<int> &A)
{
    int n = A.size();
    int xor1 = 0, x = 0, y = 0;
    for (int i = 1; i <= n; i++)
    {
        xor1 ^= i;
        xor1 ^= A[i - 1];
    }
    int set_bit = xor1 & ~(xor1 - 1);
    for (int i = 1; i <= n; i++)
    {
        if (A[i - 1] & set_bit)
            x ^= A[i - 1];
        else
            y ^= A[i - 1];
        if (i & set_bit)
            x ^= i;
        else
            y ^= i;
    }
    for (auto num : A)
    {
        if (num == x)
            return {x, y};
    }
    return {y, x};
}

//method 3 swap sort
vector<int> repeatedNumber3(vector<int> &A)
{
    int j = 0;
    while (j < A.size())
    {
        if (A[j] == j + 1 or A[A[j] - 1] == A[j])
            j++;
        else
            swap(A[j], A[A[j] - 1]);
    }
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] != i + 1)
            return {A[i], i + 1};
    }
}

int main()
{
    vector<int> A = {1, 2, 3, 4, 5, 5, 7};
    vector<int> r1 = repeatedNumber(A);
    vector<int> r2 = repeatedNumber2(A);
    vector<int> r3 = repeatedNumber3(A);
    for(auto i: r1){
        cout<<i<<" ";
    }
    return 0;
}