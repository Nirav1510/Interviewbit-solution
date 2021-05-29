#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool isValid(int A,vector<int> &C,ll mid){
    int p=1;
    int sum=0;
    for(int i=0;i<C.size();i++){
        sum+=C[i];
        if(sum>mid){
            p++;
            sum=C[i];
        }
    }
    if(p>A) return false;
    return true;
}

int paint(int A, int B, vector<int> &C) {
    ll n=C.size();
    ll sum=0;
    int mE=INT_MIN;
    for(int i=0;i<n;i++){
        mE=max(mE,C[i]);
        sum+=C[i];
    }
    ll low=mE,high=sum,mid;
    ll ans;
    while(low<=high){
        mid=low+(high-low)/2;
        
        if(isValid(A,C,mid)){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    ans=ans*B;
    ans=ans%10000003;
    return ans;
}

int main()
{
    vector<int> C = {10, 20, 50, 40, 60, 90, 30};
    int a,b;
    cin >> a >> b;
    int res = paint(a,b,C);
    cout << res << endl;

    return 0;
}
