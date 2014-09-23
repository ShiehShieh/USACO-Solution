/*
 ID: ShiehShieh
 PROG: money
 LANG: C++11
 */
#include <fstream>
#include <string>
#include <iostream>
#include <set>
#include <vector>


using namespace std;


int V = 0, N = 0;


int knapsack(set<long long>& allCoin, vector<long long>& result) {
	for(long long i : allCoin) {
		for (long long j = i; j <= N; ++j)
		{
			result[j] += result[j - i];
		}
	}

	return 0;
}

/*
void work(int& result, int sum, vector<int>& allCoin) {
	for (int i = 0; i < allCoin.size(); ++i)
	{
		int local = sum;
		cout << allCoin[i] << ' ' << local << endl;
		local += allCoin[i];

		if (local == N) {
			++result;

			return;
		}else if (local > N) {

			return;
		}else if (local < N) {
			work(result, local, allCoin);
		}
	}

	return;
}
*/

int main(int argc, char const *argv[])
{
	ifstream inf("money.in");
	ofstream ouf("money.out");
	int k = 0;
	set<long long> allCoin;

	inf >> V >> N;
	inf >> k;
	while(inf) {
		allCoin.insert(k);
		inf >> k;
	}

	vector<long long> result(N + 1, 0);
	result[0] = 1;

	knapsack(allCoin, result);

//	for(long int i : result) {
//		cout << i << endl;
//	}

	ouf << result[N] << endl;

	return 0;
}
