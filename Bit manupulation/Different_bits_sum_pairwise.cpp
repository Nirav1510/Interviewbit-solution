#include <bits/stdc++.h>
#define ll long long int 
using namespace std;

int cntBits(vector<int> &A) {
    ll n=A.size();
    ll ans=0;
    for(int i=0;i<32;i++){
        ll count=0;
        for(int j=0;j<n;j++){
            if(A[j] & 1<<i){
                //counting set bits in a A[j]
                count++;
            }
        }
        //count=no.of set bits(1)
        //n-count=no.of unset bits(0)
        ans+=count*(n-count)*2;
        //ans is multiply by 2 as there are two pairs like (1,3) and (3,1)  
    }
    ans=ans%1000000007;
    return ans;
}

int main(){
    vector<int> A={1,3,5};

    int res=cntBits(A);
    cout<<res<<endl;
    return 0;
}