#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int repeatedNumber(const vector<int> &A)
{
	int n = A.size();
	int c1 = 0, c2 = 0;
	int ele1 = INT_MAX, ele2 = INT_MAX;
	for (int i = 0; i < n; i++)
	{

		if (ele1 == A[i])
			c1++;
		else if (ele2 == A[i])
			c2++;

		else if (c1 == 0)
		{
			c1++;
			ele1 = A[i];
		}
		else if (c2 == 0)
		{
			c2++;
			ele2 = A[i];
		}
		else
		{
			c1--;
			c2--;
		}
	}
	c1 = 0;
	c2 = 0;

	for (int i = 0; i < n; i++)
	{
		if (ele1 == A[i])
			c1++;
		else if (ele2 == A[i])
			c2++;
	}

	if (c1 > n / 3)
		return ele1;
	else if (c2 > n / 3)
		return ele2;

	return -1;
}

int main()
{

	vector<int> A = {3, 3, 4, 2, 4, 4, 2, 4, 4};
	int res = repeatedNumber(A);
	cout << res << endl;

	return 0;
}
