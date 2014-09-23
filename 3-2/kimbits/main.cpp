/*
 ID: ShiehShieh
 PROG: kimbits
 LANG: C++11
 */
#include <fstream>
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cstring>


using namespace std;


long dp[33][33];
int N, L, I, k;
string result;


void shaper() {
	for (int i = N; i > 0; --i)
	{
		if (dp[i - 1][L] <= I)
		{
			result[result.length() - i] = '1';

			I -= dp[i - 1][L];
			--L;
		}else {
			result[result.length() - i] = '0';
		}
	}

	return;
}


int main(int argc, char const *argv[])
{
	ifstream inf("kimbits.in");
	ofstream ouf("kimbits.out");
	N = 0, L = 0, I = 0, k = 1;

	inf >> N >> L >> I;

	result.resize(N, '0');

	if (I == 1)
	{
		for (int i = 0; i < N; ++i)
		{
			ouf << '0' << flush;
		}

		ouf << endl;

		return 0;
	}

	for (int i = 0; i < 33; ++i)
	{
		if (i == 0)
		{
			for (int j = 0; j < 33; ++j)
			{
				dp[i][j] = 1;
			}
		}else {
			for (int j = 0; j < 33; ++j)
			{
				dp[i][j] = 2;
			}
			dp[i][0] = 1;
		}
	}

	for (int i = 2; i < 33; ++i)
	{
		for (int j = 1; j < 33; ++j)
		{
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
		}
	}

	I -= 1;

	shaper();

	ouf << result << endl;

	return 0;
}
