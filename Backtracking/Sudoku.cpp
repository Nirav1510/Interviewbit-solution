#include <bits/stdc++.h>
#define ll long long int
using namespace std;

bool isValid(vector<vector<char>> &A, int row, int col, char x)
{
    for (int i = 0; i < 9; i++)
    {
        if (A[i][col] == x)
        {
            return false;
        }
    }
    for (int i = 0; i < 9; i++)
    {
        if (A[row][i] == x)
        {
            return false;
        }
    }
    int curr_row = (row / 3) * 3, curr_col = (col / 3) * 3;
    for (int i = curr_row; i < curr_row + 3; i++)
    {
        for (int j = curr_col; j < curr_col + 3; j++)
        {
            if (A[i][j] == x)
            {
                return false;
            }
        }
    }
    return true;
}

void solve(vector<vector<char>> &A, vector<vector<char>> &ans, int i, int j)
{
    if (i == 9)
    {
        ans = A;
        return;
    }
    int next_i, next_j;
    if (j == A[0].size() - 1)
    {
        next_i = i + 1;
        next_j = 0;
    }
    else
    {
        next_i = i;
        next_j = j + 1;
    }
    if (A[i][j] != '.')
    {
        solve(A, ans, next_i, next_j);
    }
    else
    {
        for (char x = '1'; x <= '9'; x++)
        {
            if (isValid(A, i, j, x))
            {
                A[i][j] = x;
                solve(A, ans, next_i, next_j);
                A[i][j] = '.';
            }
        }
    }
}

void solveSudoku(vector<vector<char>> &A)
{
    vector<vector<char>> ans;
    solve(A, ans, 0, 0);
    A = ans;
}

int main(){
    vector<vector<char>> A=[ [53..7....],
                             [6..195...],
                             [.98....6.], 
                             [8...6...3], 
                             [4..8.3..1], 
                             [7...2...6], 
                             [.6....28.], 
                             [...419..5], 
                             [....8..79] ];
    solveSudoku(A);
    for(int i=0;i<A.size();i++){
        for(int j=0;j<A[i].size();j++){
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
