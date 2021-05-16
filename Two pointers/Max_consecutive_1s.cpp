#include <iostream>
#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int solve(vector<int> &A, int B) {
    int n=A.size();
    int j=0, i=0, count=0;
    int ans=INT_MIN;
    while(j<n){
        if(A[j]==0){
            count++;
        }
        while(count>B){
            if(A[i]==0)count--;
            i++;
        }
        ans=max(ans, j-i+1);
        j++;
    }
    return ans;
}
int main() {
 
	vector<int> A={1, 0, 0, 1, 0, 1, 0, 1, 0, 1};
	int res=solve(A,2);
	cout<<res<<endl;
	return 0;
}
