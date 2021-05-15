#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &A,int B){
    int i=0,j=A.size()-1;
    while(i<j){
        int mid=i+(j-i)/2;
        if(A[mid]==B){
            return mid;
        }
        else if(A[mid]<B){
            if(A[mid+1]>A[mid]){
                i=mid+1;
            }
            else{
                j=mid-1;
            }
        }
        else{
            if(A[mid+1]>A[mid]){
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }
    }
    return -1;
}

int main(){
    vector<int> A={3, 9, 10, 20, 17, 5, 1};
    int ans=solve(A,20);

    cout<<ans<<endl;
    return 0;
}