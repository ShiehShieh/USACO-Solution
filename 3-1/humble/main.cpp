/*
 ID: ShiehShieh
 PROG: humble
 LANG: C++11
 */
#include <fstream>
#include <string>
#include <iostream>
#include <set>
#include <vector>


using namespace std;


int K, N;


int main(int argc, char const *argv[])
{
	ifstream inf("humble.in");
	ofstream ouf("humble.out");
	long k = 0, minOne = 100000000000;
	vector<long> allPrime, index, result, local;

	K = 0, N = 0;

	inf >> K >> N;

	inf >> k;
	while(inf) {
		allPrime.push_back(k);
		inf >> k;
	}

	result.push_back(1);

	for (int i = 0; i < K; ++i)
	{
		index.push_back(0);
	}

	local.resize(K);

	while(result.size() <= N) {
		int whichOne = 0;
		minOne = 100000000000;
		for (int j = 0; j < allPrime.size(); ++j)
		{
			k = result[index[j]] * allPrime[j];

			local[j] = k;
		}

		for (int i = 0; i < K; ++i)
		{
			if (local[i] < minOne)
			{
				minOne = local[i];
				whichOne = i;
			}
		}

		++index[whichOne];

		if (minOne > result.back())
		{
			result.push_back(minOne);
		}
	}

	ouf << result.back() << endl;

	return 0;
}
