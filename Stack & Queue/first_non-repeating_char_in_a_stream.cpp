#include <bits/stdc++.h>
using namespace std;

string solve(string A) {
    string ans="";
    int charCount[26]={0};
    queue<char> q;
    
    for(int i=0;i<A.length();i++){
        q.push(A[i]);
        charCount[A[i]-'a']++;
        
        while(!q.empty()){
            if(charCount[q.front()-'a']>1){
                q.pop();
            }
            else{
                ans+=q.front();
                break;
            }
        }
        if(q.empty()){
            ans+='#';
        }
    }
    return ans;
}

int main(){
    string s;
    cin>>s;
    string res=solve(s);

    cout<<res<<endl;
    return 0;
}