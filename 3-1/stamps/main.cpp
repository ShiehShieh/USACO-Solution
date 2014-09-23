/*
 ID: ShiehShieh
 PROG: stamps
 LANG: C++11
 */
#include <fstream>
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <cstring>


using namespace std;


int max(int a, int b) {

	if (a < b) {

		return b;

	}else {

		return a;

	}
}


int main(int argc, char const *argv[])
{
	ifstream inf("stamps.in");
	ofstream ouf("stamps.out");
	int K = 0, N = 0, k = 0, minOne = 1000000000;
	int result[2000000];
	vector<int> allPossible;

	memset(result, 0, 2000000);

	inf >> K >> N;

	inf >> k;
	while(inf) {
		allPossible.push_back(k);
		inf >> k;
	}

	for (int i = 1; i < 2000000; ++i)
	{
		minOne = 1000000000;
		for (int j = 0; j < allPossible.size(); ++j)
		{
			if (i < allPossible[j])
			{
				continue;
			}
			k = result[i - allPossible[j]] + 1;
			if (k < minOne)
			{
				minOne = k;
			}
		}

		if (minOne > K)
		{
			break;
		}

		result[i] = minOne;
	}

	for (int i = 1; i < 2000000; ++i)
	{
		if (result[i] == 0)
		{
			k = i - 1;

			break;
		}
	}

	ouf << k << endl;

	return 0;
}
