int dp[101][10001];

int superEggDropHelp(int e, int f)
{
    if (e == 1 || f == 0 || f == 1)
        return f;

    if (dp[e][f] == -1)
    {
        int low = 1, high = f;
        int ans = INT_MAX;
        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (dp[e - 1][mid - 1] == -1)
                dp[e - 1][mid - 1] = superEggDropHelp(e - 1, mid - 1);

            if (dp[e][f - mid] == -1)
                dp[e][f - mid] = superEggDropHelp(e, f - mid);

            int temp = max(1 + dp[e - 1][mid - 1], 1 + dp[e][f - mid]);

            if (dp[e - 1][mid - 1] < dp[e][f - mid])
                low = mid + 1;

            else
                high = mid - 1;

            ans = min(ans, temp);
        }

        dp[e][f] = ans;
    }
    return dp[e][f];
}

//2nd 

int dp[101][10001];
int esolve(int e, int f){
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
            left=esolve(e-1,mid-1);
            dp[e-1][mid-1]=left;
        }
        if(dp[e][f-mid]!=-1){
            right=dp[e][f-mid];
        }
        else{
            right=esolve(e,f-mid);
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

int Solution::solve(int e, int f)
{
    memset(dp, -1, sizeof(dp));
    int res = superEggDropHelp(e, f);

    return res;
}
