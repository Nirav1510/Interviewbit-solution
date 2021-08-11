bool getbit(int n,int index){
    return ((n & (1<<index))!=0);
}

int setBit(int n,int index){
    return (n | (1 << index));
}

int Solution::singleNumber(const vector<int> &A) {

    int ans=0;
    
    for(int j=0;j<128;j++){
        int sum=0;
        for(int i=0;i<A.size();i++){
            if(getbit(A[j],i)){
                sum++;
            }
        }
        if(sum%3!=0){
            ans=setBit(ans,j);
        }
    }
    return ans;
}
