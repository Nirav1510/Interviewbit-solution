#include <iostream>
#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int solve(vector<int> &A,int B){
    unordered_map<int,int> m;
    int n=A.size(),i=0;
    for(int i=0;i<n;i++){
        m[A[i]]++;
    }
    if(m.size()==n && B==0){
        return 0;
    }
    for(int i=0;i<n;i++){
        int a=A[i]+B;
        if(m.find(a)!=m.end()){
            return 1;
        }
    }
    return 0;
}
int main() {
	vector<int> A={1,5,3};
    int ans=solve(A,2);
    cout<<ans<<endl;
	return 0;
}
