vector<vector<int> > Solution::threeSum(vector<int> &A) {
    vector<vector<int>> ans;
    set<vector<int>> s;
    sort(A.begin(),A.end());
    if(A.size()<3) return ans;
    for(int i=0;i<A.size()-2;i++){
        if(i>0&&A[i]==A[i-1]) continue;
        long long int left=i+1;
        long long int right=A.size()-1;
        long long int x=A[i];
        while(left<right){
            long long int sum=x+A[left]+A[right];
            if(sum==0){
                vector<int> triplet={x,A[left],A[right]};
                s.insert(triplet);
                right--;
            }
            else if(sum<0) left++;
            else right--;
        }
    }
    for(auto i:s){
        ans.push_back(i);
    }
    return ans;
}
