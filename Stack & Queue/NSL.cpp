#include <bits/stdc++.h>
using namespace std;

vector<int> prevSmaller (vector<int> &A) {
    vector<int> v;
    stack<int> s;
    for(int i=0;i<A.size();i++){
        if(s.size()==0){
            v.push_back(-1);
        }
        else if(s.size()>0 && s.top()<A[i]){
            v.push_back(s.top());
        }
        else if(s.size()>0 && s.top()>=A[i]){
            while(s.size()>0 && s.top()>=A[i]){
                s.pop();
            }
            if(s.size()==0){
                v.push_back(-1);
            }
            else{
                v.push_back(s.top());
            }
        }
        s.push(A[i]);
    }
    return v;
}

int main(){
    vector<int> A={4,5,2,10,8};

    vector<int> ans=prevSmaller(A);
    for(int i=0;i<A.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;

}