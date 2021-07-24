int wordLadderLength(string start, string target, vector<string> &wordList)
{
    unordered_set<string> s;

    for (auto word : wordList)
    {
        s.insert(word);
    }

    if (s.find(target) == s.end())
    {
        return 0;
    }

    queue<string> q;
    q.push(start);
    int depth = 0;

    while (!q.empty())
    {

        depth++;
        int size = q.size();

        for (int i = 0; i < size; i++)
        {

            string curr = q.front();
            q.pop();

            for (int j = 0; j < curr.size(); j++)
            {

                string temp = curr;

                for (char c = 'a'; c <= 'z'; c++)
                {
                    temp[j] = c;

                    if (s.find(temp) == s.end())
                    {
                        continue;
                    }
                    if (temp == target)
                    {
                        return depth + 1;
                    }
                    s.erase(temp);
                    q.push(temp);
                }
            }
        }
    }
    return 0;
}