/*
 ID: ShiehShieh
 PROG: nocows
 LANG: C++11
 */
#include <fstream>
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cmath>


using namespace std;


vector<vector<int>> dp;


int work(int k, int n) {
	int allPossible = 0;

	if (n < 0)
	{
		/* code */
		return 0;
	}

	if (k == 1)
	{
		/* code */
		if (n != 1)
		{
			/* code */
			dp[k][n] = 0;
		}else {
			dp[k][n] = 1;
		}

		return dp[k][n];
	}

	for (int i = 2 * k - 3; i <= n ; )
	{
		/* code */
		for (int j = 1; j <= k - 2; )
		{
			/* code */
			allPossible += work(j, i);
			j += 2;
		}

		cout << allPossible << endl;

		dp[k][n] = work(k - 1, i) * work(k - 1, n - i - 1) + allPossible * work(k - 1, n - i - 1) * 2;
		i += 2;
	}

	cout << k << ' ' << n << endl;

	return dp[k][n];
}


int main(int argc, char const *argv[])
{
	ifstream inf("nocows.in");
	ofstream ouf("nocows.out");
	int N = 0, K = 0;

	inf >> N >> K;

	for (int i = 0; i < K + 1; ++i)
	{
		/* code */
		dp.push_back(vector<int>(N + 1, 0));
	}

	work(K, N);

	for(vector<int> v : dp) {
		for(int i : v) {
			cout << i << ' ' << flush;
		}
		cout << endl;
	}

	return 0;
}
