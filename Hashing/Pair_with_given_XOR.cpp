#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &A,int B){
    int n=A.size();
    int ans=0;
    unordered_set<int> s;
    for(int i=0;i<n;i++){
        if(s.find(B^A[i])!=s.end()){
            ans++;
        }
        s.insert(A[i]);
    }
    return ans;
}
int main(){
    vector<int> A={3, 6, 8, 10, 15, 50};
    int B=5;
    int res=solve(A,5);
    cout<<res<<endl;
    return 0;
}