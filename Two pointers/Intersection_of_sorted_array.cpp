#include<bits/stdc++.h>
using namespace std;

vector<int> intersect(const vector<int> &A, const vector<int> &B) {

    vector<int> res;
    int i = 0, j = 0;
    
    while(i < A.size() && j < B.size()){
        if(A[i] == B[j]){
            res.push_back(A[i]);
            i++;
            j++;
        }
        else if(A[i] < B[j]) i++;
        else j++;
    }
    
    return res;
}
int main(){
    vector<int> A={2,3,4,5,6,8};
    vector<int> B={2,5,6,9};
    vector<int> ans=intersect(A,B);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}