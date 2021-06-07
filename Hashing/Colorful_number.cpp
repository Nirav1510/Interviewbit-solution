#include <bits/stdc++.h>
using namespace std;

int colorful(int A)
{
    string str = to_string(A);
    unordered_set<int> s;
    int l = str.length();
    for (int i = 0; i < l; i++)
    {
        int product = 1;
        for (int j = i; j < l; j++)
        {
            product = product * (int)(str[j] - '0');

            if (s.find(product) != s.end())
            {
                return 0;
            }
            else
            {
                s.insert(product);
            }
        }
    }
    return 1;
}

int main()
{
    int n;
    cin >> n;
    cout << colorful(n) << endl;
    return 0;
}