#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &A, int B) {
    int i=0,j=0,sum=0,ans=0;
    int n=A.size();
    while(j<n){
        sum+=A[j];
        
        while(sum>=B){
            sum-=A[i];
            i++;
        }
        ans+=(j-i+1);
        j++;
    }
    return ans;
}

int main(){
    vector<int> A={2,5,6};
    int res=solve(A,10);
    cout<<res<<endl;

    return 0;
}
