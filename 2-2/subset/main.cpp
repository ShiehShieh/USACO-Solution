/*
 ID: ShiehShieh
 PROG: subset
 LANG: C++11
 */
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


//vector<vector<int>>	dp;
vector<int> allMax;
int total = 0, result = 0;
int N = 0;


void knapsack(int i, int j) {
	int max = allMax[i - 1];

	if (i == 0)
	{
		/* code */
		return;
	}
	if (j < 0)
	{
		/* code */
		return;
	}
	if (max < j)
	{
		/* code */
		return;
	}
	if (j == 0)
	{
		/* code */
//		cout << "Find it." << endl;
		++result;

		return;
	}

//	dp[i][j] = j;

	knapsack(i - 1, j);
	knapsack(i - 1, j - i);
}


int main(int argc, char const *argv[])
{
	ifstream inf("subset.in");
	ofstream ouf("subset.out");

	inf >> N;

	for (int i = 1; i <= N; ++i)
	{
		/* code */
		int max = 0;
		for (int j = 1; j <= i; ++j)
		{
			/* code */
			max += j;
		}
		allMax.push_back(max);
		total += i;
	}

	if (total % 2)
	{
		/* code */
		ouf << 0 << endl;

		exit(0);
	}

//	for(int i : allMax) {
//		cout << i << endl;
//	}

//	vector<int> tem(total / 2 + 1);

//	for (int i = 0; i <= N; ++i)
//	{
		/* code */
//		dp.push_back(tem);
//	}

//	cout << dp.size() << endl;
//	cout << dp[N - 1].size() << endl;
//	cout << dp[N].size() << endl;

	knapsack(N, total / 2);

//	for(vector<int> v : dp) {
//		for(int i : v) {
//			cout << i << ' ' << flush;
//		}
//		cout << endl;
//	}

	ouf << result << endl;

	return 0;
}
