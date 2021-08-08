//Catalan no. logic

int Solution::numTrees(int A) {
    
    if(A<=2){
        return A;
    }
    vector<int> dp(A+1,0);
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<A+1;i++)
    {
        for(int j=0;j<i;j++)
        {
            dp[i]+=dp[j]*dp[i-j-1];
        }
    }
    return dp[A];
}
