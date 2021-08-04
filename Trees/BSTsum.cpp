long long int MOD = 1e9+7;
long long int fact(int n)
{
    if(n==0) return 1;
    long long int f=1;
    for(long long int i=1;i<=n;i++)
    {
        f=f*i;
        f%=MOD;
    }
    return f;
}
int Solution::solve(int n) {
    long long int sum=0,f=fact(n-1);
    for(long long int i=1;i<=n;i++)
    {
        long long int m=(i*(i-1))/2;
        m%=MOD;
        m*=f;
        m%=MOD;
        sum+=m;
        sum%=MOD;
    }
    return sum;
}
