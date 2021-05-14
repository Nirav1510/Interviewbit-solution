#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll solve(vector<ll> &v){
    ll n=v.size();
    unordered_map<ll,ll> m;
    for(ll i=0;i<n;i++){
        m[v[i]]++;
    }
    for(ll i=0;i<n;i++){
        if(m[v[i]]>1){
            return v[i];
            break;
        }
    }
    return -1;
}

int main(){
    vector<ll> v={0, 10, 5, 4, 9, 120,5,6};
    ll ans=solve(v);

    cout<<ans<<endl;
    return 0;
}