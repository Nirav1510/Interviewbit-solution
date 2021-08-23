bool compare(int x,int y){
    string a=to_string(x)+to_string(y);
    string b=to_string(y)+to_string(x);
    
    return a>b;
}

string Solution::largestNumber(const vector<int> &A) {
    
    int n=A.size();
    vector<int> v=A;
    sort(v.begin(),v.end(),compare);
    
    string ans;
    for(auto i:v){
        ans+=to_string(i);
    }
    int count=0;
    for(auto i:ans){
        if(i=='0'){
            count++;
        }
    }
    
    if(count==ans.size()){
        return "0";
    }
    return ans;
}
