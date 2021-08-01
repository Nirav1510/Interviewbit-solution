#define ll long long int

bool isVowel(char c)
{
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int Solution::solve(string A)
{
    ll c = 0, v = 0;
    ll m = 1e9 + 7;
    for (int i = 0; i < A.size(); i++)
    {
        if (isVowel(A[i]))
        {
            v++;
        }
        else
        {
            c++;
        }
    }
    ll ans = ((v % m) * (c % m)) % m;
    return ans;
}
