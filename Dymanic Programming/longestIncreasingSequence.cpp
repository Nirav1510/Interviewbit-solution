int Solution::lis(const vector<int> &A)
{
    int n = A.size();
    if (n == 1)
        return 1;
    if (n == 0)
        return 0;
    vector<int> dp(n, 1);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (A[i] > A[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    int ans = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, dp[i]);
    }
    return ans;
}

int lcs(vector<int> A, vector<int> B)
{
    int n = A.size(), m = B.size();
    int dp[n + 1][m + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (A[i - 1] == B[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][m];
}

int Solution::lis(const vector<int> &A)
{
    set<int> s;
    //sort(B.begin(), B.end());
    for (auto i : A)
    {
        s.insert(i);
    }
    vector<int> B;
    for (auto it : s)
    {
        B.push_back(it);
    }
    return lcs(A, B);
}

// O(nlogn) O(n)

class Solution
{
public:
    int lengthOfLIS(vector<int> &A)
    {
        int n = A.size();
        vector<int> res;
        for (int i = 0; i < n; i++)
        {
            auto it = lower_bound(res.begin(), res.end(), A[i]);
            if (it == res.end())
                res.push_back(A[i]);

            else
                *it = A[i];
        }

        return res.size();
    }
};

// tabular O(n^2) * O(n)

// dp[i] = Len if LIS ending at A[i]

class Solution
{
public:
    int lengthOfLIS(vector<int> &A)
    {
        int n = A.size();
        vector<int> dp(n, 1);
        int maxLen = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (A[j] < A[i])
                    dp[i] = max(dp[i], dp[j] + 1);
            }

            maxLen = max(maxLen, dp[i]);
        }

        return maxLen;
    }
};

// LCS with sorted unique

int Solution::lis(const vector<int> &A)
{
    vector<int> a = A;
    sort(a.begin(), a.end());
    auto it = unique(a.begin(), a.end());
    a.resize(distance(a.begin(), it));

    int n = a.size(), m = A.size();
    int dp[n + 1][m + 1];

    for (int i = 0; i < n + 1; i++)
        dp[i][0] = 0;

    for (int j = 0; j < m + 1; j++)
        dp[0][j] = 0;

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (a[i - 1] == A[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];

            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[n][m];
}