/*
 ID: ShiehShieh
 PROG: inflate
 LANG: C++11
 */
#include <fstream>
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <cstring>


using namespace std;


int M, N;


long max(long a, long b) {

	if (a < b) {

		return b;

	}else {

		return a;

	}
}


int main(int argc, char const *argv[])
{
	ifstream inf("inflate.in");
	ofstream ouf("inflate.out");
	long k = 0, q = 0;
	long result[100000];

	memset(result, 0, 10000);

	M = 0, N = 0;

	inf >> M >> N;

	vector<pair<long, long>> allQuestion;
	inf >> k >> q;
	while(inf) {
		allQuestion.push_back(make_pair(k, q));
		inf >> k >> q;
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = allQuestion[i].second; j <= M; ++j)
		{
			result[j] = max(result[j], result[j - allQuestion[i].second] + allQuestion[i].first);
		}
	}

	ouf << result[M] << endl;

	return 0;
}
