int Solution::solve(vector<int> &A, int B) {
    int i=0,j=0,prefix=0;
    int count=0,ans=0;
    map<int,int> mp;
    
    while(j<A.size()){
        mp[A[j]]++;
        if(mp[A[j]]==1){
            count++;
        }
        
        if(count>B){
            mp[A[i]]--;
            i++;
            count--;
            prefix=0;
        }
        
        while(mp[A[i]]>1){
            mp[A[i]]--;
            i++;
            prefix++;
        }
        
        if(count==B){
            ans+=prefix+1;
        }
        j++;
    }
    return ans;
}
