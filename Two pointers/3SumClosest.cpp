int Solution::threeSumClosest(vector<int> &A, int B) {
    if(A.size() < 3){
        return 0;
    }
    
    sort(A.begin(), A.end());
    
    int i = 0;
    int sum, minDiff = INT_MAX;
    
    for(int i=0; i< A.size()-2;i++){
        int left = i+1;
        int right = A.size()-1;
        while(left<right){
            int temp = A[i]+A[left]+A[right];
            int diff = abs(temp-B);
            if(diff == 0){
                return B;
            }
            if(diff < minDiff){
                minDiff = diff;
                sum = temp;
            }
            if(temp < B){
                left++;
            }
            else{
                right--;
            }
        }
    }
    
    return sum;
}
