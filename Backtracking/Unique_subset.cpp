#include <bits/stdc++.h>
using namespace std;
void subset(string str, string output, vector<string> &v)
{
    if (str.length() == 0)
    {
        v.push_back(output);
        return;
    }
    string op1 = output;
    string op2 = output + str[0];
    str.erase(str.begin());
    subset(str, op1, v);
    subset(str, op2, v);
}
int main()
{
    string str, output = " ";
    cin >> str;
    vector<string> v;
    subset(str, output, v);
    vector<string> unique;
    map<string, int> m;
    for (int i = 0; i < v.size(); i++)
    {
        if (m[v.at(i)] == 0)
        {
            m[v.at(i)]++;
            unique.push_back(v.at(i));
        }
    }
    for (int i = 0; i < unique.size(); i++)
    {
        cout << unique.at(i) << " ";
    }
    cout << endl;
    return 0;
}