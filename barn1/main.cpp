/*
 ID: ShiehShieh
 PROG: barn1
 LANG: C++11
 */
#include <fstream>
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>


using namespace std;

int reduce(int result, vector<int>& diff) {
	int bigest = 0;
	vector<int>::iterator ii;
	for (vector<int>::iterator i = diff.begin(); i != diff.end(); ++i)
	{
		if (*i > bigest)
		{
			bigest = *i;
			ii = i;
		}
	}

	result = result - bigest + 1;
	diff.erase(ii);

	return result;
}


int main(int argc, char *argv[])
{
	ifstream inf("barn1.in");
	ofstream ouf("barn1.out");
	int M = 0, S = 0, C = 0;
	int k = 0;
	int result = 0;
	inf >> M >> S >> C;
	vector<int> eachone;
	vector<int> diff;
	for (int i = 0; i < C; ++i)
	{
		inf >> k;
		eachone.push_back(k);
	}

	sort(eachone.begin(), eachone.end());

	for (vector<int>::iterator i = eachone.begin(); i != eachone.end() - 1; ++i)
	{
		k = *(i + 1) - *i;
		diff.push_back(k);
	}

	inf.close();
//	for (int i = 0; i < C - 1; ++i)
//	{
//		cout << diff[i] << endl;
//	}

	result = eachone.back() - eachone.front() + 1;

	for (int e = 0; e < M - 1 && e < C - 1; ++e)
	{
		result = reduce(result, diff);
	}

	ouf << result << endl;

	return 0;
}
