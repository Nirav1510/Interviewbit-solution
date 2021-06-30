struct Job
{
    int id;     // Job Id
    int dead;   // Deadline of job
    int profit; // Profit if job is over before or on deadline
};

class Solution
{
public:
    static bool compare(Job x, Job y)
    {
        return x.profit > y.profit;
    }

    vector<int> JobScheduling(Job arr[], int n)
    {
        sort(arr, arr + n, compare);

        int md = arr[0].dead;
        for (int i = 1; i < n; i++)
        {
            md = max(md, arr[i].dead);
        }

        bool slot[md + 1];

        for (int i = 0; i < md + 1; i++)
        {
            slot[i] = false;
        }

        int currjob = 0, jobprofit = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = arr[i].dead - 1; j >= 0; j--)
            {
                if (slot[j] == false)
                {
                    slot[j] = true;
                    currjob++;
                    jobprofit += arr[i].profit;
                    break;
                }
            }
        }
        vector<int> ans;
        ans.push_back(currjob);
        ans.push_back(jobprofit);
        return ans;
    }
};