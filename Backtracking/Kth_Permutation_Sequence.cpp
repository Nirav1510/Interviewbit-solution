#include <bits/stdc++.h>
#define ll long long int
using namespace std;

string getPermutation(int n, int k)
{
    // vector<int> v;
    // int fact=1;
    // for(int i=1;i<n;i++){
    //     fact*=i;
    //     v.push_back(i);
    // }
    // v.push_back(n);
    // k=k-1;
    // string ans="";
    // while(true){
    //     ans=ans+to_string(v[k/fact]);
    //     v.erase(v.begin()+k/fact);
    //     if(v.size()==0) break;
    //     k=k%fact;
    //     fact=fact/v.size();
    // }
    // return ans;

    vector<int> v;
    string s;
    for (int i = 1; i <= n; i++)
        v.push_back(i);
    for (int i = 1; i <= k - 1; i++)
        next_permutation(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
        s = s + to_string(v[i]);
    return s;
}

int main()
{
    int n, k;
    cin >> n >> k;
    string res = getPermutation(n, k);
    cout << res << endl;
    return 0;
}
