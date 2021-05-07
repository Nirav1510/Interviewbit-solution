#include <bits/stdc++.h>
using namespace std;

int braces(string A) {
    stack<char> st;
    for(int i=0;i<A.length();i++){
        if(A[i]=='+' || A[i]=='-' || A[i]=='*' || A[i]=='/'){
            st.push(A[i]);
        }
        else if(A[i]=='('){
            st.push(A[i]);
        }
        else if(A[i]==')'){
            if(st.top()=='('){
                return 1;
            }
            while(st.top()=='+' || st.top()=='-' || st.top()=='*' || st.top()=='/'){
                st.pop();
            }
            st.pop();
        }
    }
    return 0;
}

int main(){
    string S;
    cin>>S;
    
    int ans=braces(S);
    cout<<ans<<endl;

    return 0;
}