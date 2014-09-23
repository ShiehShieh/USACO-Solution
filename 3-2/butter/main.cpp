/*
 ID: ShiehShieh
 PROG: butter
 LANG: C++11
 */
#include <fstream>
#include <string>
#include <iostream>
#include <map>
#include <vector>


using namespace std;


int N, P, C;


long theMatrix[1000][1000];


int main(int argc, char const *argv[])
{
	ifstream inf("butter.in");
	ofstream ouf("butter.out");
	long k = 0, a = 0, b = 0, minOne = 100000000;

	vector<long> theNumberOFCow;

	inf >> N >> P >> C;

	for (int i = 0; i < N; ++i)
	{
		inf >> k;
		theNumberOFCow.push_back(k);
	}

	for (int i = 0; i < C; ++i)
	{
		inf >> a >> b >> k;
		theMatrix[a][b] = k;
		theMatrix[b][a] = k;
	}

	for (int i = 0; i <= P; ++i)
	{
		for (int j = 0; j <= P; ++j)
		{
			if (theMatrix[i][j] == 0 && i != j)
			{
				theMatrix[i][j] = 100000000;
			}
		}
	}

	for (int l = 1; l <= P; ++l)
	{
		for (int i = 1; i <= P; ++i)
		{
			for (int j = i; j <= P; ++j)
			{
				if (theMatrix[i][l] + theMatrix[l][j] < theMatrix[i][j])
				{
					theMatrix[i][j] = theMatrix[i][l] + theMatrix[l][j];
					theMatrix[j][i] = theMatrix[i][j];
				}
			}
		}
	}

	for (int i = 1; i <= P; ++i)
	{
		k = 0;
		for(long j : theNumberOFCow) {
			k +=  theMatrix[i][j];
		}

		if (k < minOne)
		{
			minOne = k;
		}
	}

	ouf << minOne << endl;

	return 0;
}
