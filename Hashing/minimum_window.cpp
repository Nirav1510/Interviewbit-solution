#include <bits/stdc++.h>
#define ll long long int
using namespace std;

string minWindow(string A, string B) {
    int l=B.length();
    if(A.length()==0 || A.length()<l) return "";
    unordered_map<char,int> m;
    for(int i=0;i<l;i++){
        m[B[i]]++;
    }
    int i=0,j=0,count=0;
    int minlength=INT_MAX,mini=0;
    
    while(j<A.length()){
        
        if(m.find(A[j])!=m.end()){
            m[A[j]]--;
            if(m[A[j]]>=0){
                count++;
            }
        }
        
        while(count==l){
            
            if(minlength>j-i+1){
                minlength=j-i+1;
                mini=i;
            }
            
            if(m.find(A[i])!=m.end()){
                m[A[i]]++;
                if(m[A[i]]>0){
                    count--;
                }
            }
            i++;
        }
        j++;
    }
    
    if(minlength>A.length()) return "";
    
    return A.substr(mini,minlength);
}


int main() {
	string s= "ADOBECODEBANC";
    string t= "ABC";

	string ans=minWindow(s,t);
    for(auto i:ans){
        cout<<i;
    }
	return 0;
}
