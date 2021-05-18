#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int value(char c)
{
    if (c == 'I'){
        return 1;
    }
    if (c == 'V'){
        return 5;}
    if (c == 'X'){
        return 10;}
    if (c == 'L'){
        return 50;}
    if (c == 'C'){
        return 100;}
    if (c == 'D'){
        return 500;}
    if (c == 'M'){
        return 1000;}
    return -1;
}

//method 1
int romanToInteger(string A)
{
    int ans=0;
    for(int i=0;i<A.length();i++){
        int s1=value(A[i]);
        if(i+1<A.length()){
            int s2=value(A[i+1]);
            if(s1>=s2){
                ans=ans+s1;
            }
            else{
                ans=ans+s2-s1;
            }
        }
        else{
            ans=ans+s1;
        }
    }
    return ans;
}

//method 2
int romanToInteger2(string s)
{
    int i = 0, n = s.length();
    int ans = 0;
    map<char, int> m;
    m['I'] = 1;
    m['V'] = 5;
    m['X'] = 10;
    m['L'] = 50;
    m['C'] = 100;
    m['D'] = 500;
    m['M'] = 1000;
    while (i < n - 1)
    {
        if (m[s[i]] < m[s[i + 1]])
        {
            ans -= m[s[i]];
        }
        else
        {
            ans += m[s[i]];
        }
        i++;
    }
    ans += m[s[i]];
    return ans;
}

int main()
{
    string st;
    cin >> st;
    int res = romanToInteger(st);
    int res2 = romanToInteger2(st);

    cout << res << endl;
    cout << res2 << endl;
    
    return 0;
}