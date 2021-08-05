int Solution::solve(vector<int> &A, int B) {
    int n=A.size();
    if(n==0 || n==1 || B==0) return 0;
    if(B>n) B = n;
    vector<vector<int>> dp(B+1,vector(n,0));
    for(int i=1;i<=B;i++)
    {
        int diff=INT_MIN;
        for(int j=1;j<n;j++)
        {
            diff=max(diff,dp[i-1][j-1]-A[j-1]);
            dp[i][j]=max(dp[i][j-1],diff+A[j]);
        }
    }
    return dp[B][A.size()-1];
}
