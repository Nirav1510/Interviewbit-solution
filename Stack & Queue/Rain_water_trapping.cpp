#include <bits/stdc++.h>
using namespace std;

int trap(vector<int> &A){
    int n=A.size();
    int maxL[n];
    int maxR[n];
    
    maxL[0]=A[0];
    for(int i=1;i<n;i++){
        maxL[i]=max(maxL[i-1],A[i]);
    }
    
    maxR[n-1]=A[n-1];
    for(int i=n-2;i>=0;i--){
        maxR[i]=max(maxR[i+1],A[i]);
    }
    
    int water[n];
    for(int i=0;i<n;i++){
        water[i]=min(maxL[i],maxR[i])-A[i];
    }
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=water[i];
    }
    return sum;
}

int main(){
    
    vector<int> A={3,0,0,2,0,4};
    cout<<trap(A)<<endl;

    return 0;
}