int dp[101][10001];

int solve(int e, int f){
    if(f==1 || f==0 || e==1) return f;
    
    if(dp[e][f]!=-1){
        return dp[e][f];
    }
    
    int ans=INT_MAX;
    int l=1,h=f;
    
    while(l<=h){
        int mid=l+(h-l)/2;
        int left,right;
        
        if(dp[e-1][mid-1]!=-1){
            left=dp[e-1][mid-1];
        }
        else{
            left=solve(e-1,mid-1);
            dp[e-1][mid-1]=left;
        }
        if(dp[e][f-mid]!=-1){
            right=dp[e][f-mid];
        }
        else{
            right=solve(e,f-mid);
            dp[e][f-mid]=right;
        }
        int temp=1+max(left,right);
        if(left<right){
            l=mid+1;
        }
        else{
            h=mid-1;
        }
        ans=min(ans,temp);
    }
    return dp[e][f]=ans;
}

int Solution::Solve(int e, int f) {
    memset(dp,-1,sizeof(dp));
    int res=solve(e,f);
    
    return res;
}

int Solution::minDistance(string A, string B)
{
    int n = A.length(), m = B.length();

    int dp[n + 1][m + 1];

    for (int i = 0; i < n + 1; i++)
        dp[i][0] = i;

    for (int j = 0; j < m + 1; j++)
        dp[0][j] = j;

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (A[i - 1] == B[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
            {
                dp[i][j] = min(1 + dp[i][j - 1], min(1 + dp[i - 1][j - 1], 1 + dp[i - 1][j]));
            }
        }
    }

    return dp[n][m];
}
