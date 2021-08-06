// O(nlogn)
int Solution::maximumGap(const vector<int> &A) {
    int n = A.size();
    
    if(A.size()<2){
        return 0;
    }
    
    priority_queue<int,vector<int>,greater<int>> pq;
    
    for(int i : A){
        pq.push(i);
    }
    
    int ans = 0;
    int prev = pq.top();
    pq.pop();
    
    while(!pq.empty()){
        ans=max(ans,pq.top()-prev);
        prev=pq.top();
        pq.pop();
    }
    return ans;
}

// O(n) bucket sort

int maximumGap(vector<int>& nums) {
    int n=nums.size();
    if(n<2) return 0;
    int bucketNo = n+1;
    int maxVal = *max_element(nums.begin(), nums.end());
    int minVal = *min_element(nums.begin(), nums.end());
    if(maxVal == minVal) return 0;
    int bucketSize = (maxVal - minVal)/n+1;
    
    vector<vector<int>> buckets(bucketNo);
    
    for(int i=0;i<n;i++){
        int index = (nums[i] - minVal)/bucketSize;
        buckets[index].push_back(nums[i]);
    }
    int prevVal  = minVal;
    int maxDiff = 0;
    
    for(auto b: buckets){
        sort(b.begin(), b.end());
        for(auto i: b){
             maxDiff = max(maxDiff, i-prevVal);
             prevVal = i;
        }
        
    }
        
    return maxDiff;
}
