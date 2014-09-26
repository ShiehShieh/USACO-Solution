/*
USER: Xie zhijie [xie51081]
TASK: shopping
LANG: C++11

Compiling...
Compile: OK

Executing...
   Test 1: TEST OK [0.005 secs, 3532 KB]
   Test 2: TEST OK [0.003 secs, 3532 KB]
   Test 3: TEST OK [0.005 secs, 3532 KB]
   Test 4: TEST OK [0.011 secs, 3532 KB]
   Test 5: TEST OK [0.008 secs, 3532 KB]
   Test 6: TEST OK [0.011 secs, 3532 KB]
   Test 7: TEST OK [0.008 secs, 3532 KB]
   Test 8: TEST OK [0.016 secs, 3532 KB]
   Test 9: TEST OK [0.011 secs, 3532 KB]
   Test 10: TEST OK [0.022 secs, 3532 KB]
   Test 11: TEST OK [0.022 secs, 3532 KB]
   Test 12: TEST OK [0.014 secs, 3532 KB]

All tests OK.
YOUR PROGRAM ('shopping') WORKED FIRST TIME!  That's fantastic
-- and a rare thing.  Please accept these special automated
congratulations.
 */
/*
 ID: ShiehShieh
 PROG: shopping
 LANG: C++11
 */
#include <fstream>
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>


using namespace std;


int s, bs, allCostAndValue[200][6], indexArray[6], nowIndex;
int result[6][6][6][6][6];
int allNeeded[6];


int mapTheIndex(int input) {
	for (int i = 1; i <= nowIndex; ++i)
	{
		if (indexArray[i] == input)
		{
			return i;
		}
	}

	++nowIndex;
	indexArray[nowIndex] = input;

	return nowIndex;
}


int findTheMinimum(int a, int b, int c, int d, int e) {
	int minOne = 100000000;

	for (int i = 1; i <= s + bs; ++i)
	{
		if (a < allCostAndValue[i][1] || b < allCostAndValue[i][2] || c < allCostAndValue[i][3] || d < allCostAndValue[i][4] || e < allCostAndValue[i][5])
		{
			continue;
		}

		if (result[a - allCostAndValue[i][1]][b - allCostAndValue[i][2]][c - allCostAndValue[i][3]][d - allCostAndValue[i][4]][e - allCostAndValue[i][5]] + allCostAndValue[i][0] < minOne)
		{
			minOne = result[a - allCostAndValue[i][1]][b - allCostAndValue[i][2]][c - allCostAndValue[i][3]][d - allCostAndValue[i][4]][e - allCostAndValue[i][5]] + allCostAndValue[i][0];
		}
	}

	if (minOne == 100000000)
	{
		return result[a][b][c][d][e];
	}

	return minOne;
}


int main(int argc, char const *argv[])
{
	ifstream inf("shopping.in");
	ofstream ouf("shopping.out");
	int k = 0, p = 0, times = 0;

	inf >> s;

	for (int i = 1; i <= s; ++i)
	{
		inf >> times;

		for (int j = 0; j < times; ++j)
		{
			inf >> k >> p;

			allCostAndValue[i][mapTheIndex(k)] = p;
		}

		inf >> k;

		allCostAndValue[i][0] = k;
	}

	inf >> bs;

	for (int i = s + 1; i <= s + bs; ++i)
	{
		inf >> k >> allNeeded[i - s] >> times;

		p = 1;

		allCostAndValue[i][mapTheIndex(k)] = p;
		allCostAndValue[i][0] = times;
	}

	result[0][0][0][0][0] = 0;

	for (int a = 0; a <= allNeeded[1]; ++a)
	{
		for (int b = 0; b <= allNeeded[2]; ++b)
		{
			for (int c = 0; c <= allNeeded[3]; ++c)
			{
				for (int d = 0; d <= allNeeded[4]; ++d)
				{
					for (int e = 0; e <= allNeeded[5]; ++e)
					{
						result[a][b][c][d][e] = findTheMinimum(a, b, c, d, e);
					}
				}
			}
		}
	}

	ouf << result[allNeeded[1]][allNeeded[2]][allNeeded[3]][allNeeded[4]][allNeeded[5]] << endl;

	return 0;
}
/*
for (int i = 0; i < 10; ++i)
{
	for (int j = 0; j <= 5; ++j)
	{
		cout << allCostAndValue[i][j] << ' ' << flush;
	}
	cout << endl;
}

for (int i = 0; i < 6; ++i)
{
	cout << indexArray[i] << ' ' << flush;
}
cout << endl;

for (int i = 0; i < 6; ++i)
{
	cout << allNeeded[i] << ' ' << flush;
}
cout << endl;
*/
