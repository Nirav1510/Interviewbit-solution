void DFSRec(vector<vector<char>> &mat, int N, int M, int i, int j)
{
    if (i >= 0 and i < N and j >= 0 and j < M and mat[i][j] == '1')
    {
        mat[i][j] = '2';

        DFSRec(mat, N, M, i, j + 1);
        DFSRec(mat, N, M, i, j - 1);
        DFSRec(mat, N, M, i - 1, j);
        DFSRec(mat, N, M, i + 1, j);
        DFSRec(mat, N, M, i + 1, j + 1);
        DFSRec(mat, N, M, i + 1, j - 1);
        DFSRec(mat, N, M, i - 1, j - 1);
        DFSRec(mat, N, M, i - 1, j + 1);
    }
}

int numIslands(vector<vector<char>> &mat)
{
    int count = 0;

    int N = mat.size();
    int M = mat[0].size();

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (mat[i][j] == '1')
            {
                DFSRec(mat, N, M, i, j);

                count++;
            }
        }
    }

    return count;
}