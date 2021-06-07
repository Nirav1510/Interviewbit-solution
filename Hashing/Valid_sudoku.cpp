int isValidSudoku(const vector<string> &A)
{
    unordered_map<int, unordered_set<char>> row, col, box;

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            int temp = A[i][j];
            if (temp != '.')
            {

                if (row[i].find(temp) != row[i].end() || col[j].find(temp) != col[j].end())
                {
                    return 0;
                }
                int b = (i / 3) * 3 + (j / 3);

                if (box[b].find(temp) != box[b].end())
                {
                    return 0;
                }
                row[i].insert(temp);
                col[j].insert(temp);
                box[b].insert(temp);
            }
        }
    }
    return 1;
}