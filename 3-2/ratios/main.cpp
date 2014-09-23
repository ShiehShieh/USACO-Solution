/*
 ID: ShiehShieh
 PROG: ratios
 LANG: C++11
 */

/*
USER: Xie zhijie [xie51081]
TASK: ratios
LANG: C++11

Compiling...
Compile: OK

Executing...
   Test 1: TEST OK [0.054 secs, 3500 KB]
   Test 2: TEST OK [0.024 secs, 3500 KB]
   Test 3: TEST OK [0.035 secs, 3500 KB]
   Test 4: TEST OK [0.043 secs, 3500 KB]
   Test 5: TEST OK [0.038 secs, 3500 KB]
   Test 6: TEST OK [0.049 secs, 3500 KB]

All tests OK.
 */

#include <fstream>
#include <string>
#include <iostream>
#include <map>
#include <vector>


using namespace std;


int main(int argc, char const *argv[])
{
	ifstream inf("ratios.in");
	ofstream ouf("ratios.out");
	int k = 0, first = 0, second = 0, third = 0, minOne = 1000, index = 100000000;
	vector<int> target, output;
	vector<vector<int>> source(3);
	vector<vector<int>> result;

	for (int i = 0; i < 3; ++i)
	{
		inf >> k;
		if (k == 0)
		{
			target.push_back(100000000);
		}else {
			target.push_back(k);
		}
	}

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			inf >> k;
			source[i].push_back(k);
		}
	}

	for (int i = 0; i < 100; ++i)
	{
		for (int j = 0; j < 100; ++j)
		{
			for (int l = 0; l < 100; ++l)
			{
				if (i == 0 && j == 0 && l == 0)
				{
					continue;
				}

				first = i * source[0][0] + j * source[1][0] + l * source[2][0];
				second = i * source[0][1] + j * source[1][1] + l * source[2][1];
				third = i * source[0][2] + j * source[1][2] + l * source[2][2];

				if (first % target[0] != 0 || second % target[1] != 0 || third % target[2] != 0)
				{
					continue;
				}

				if ((target[0] == 100000000 || target[1] == 100000000 || first / target[0] == second / target[1]) && (target[1] == 100000000 || target[2] == 100000000 || second / target[1] == third / target[2]) && (target[0] == 100000000 || target[2] == 100000000 || first / target[0] == third / target[2]))
				{
					vector<int> local;
					local.push_back(i);
					local.push_back(j);
					local.push_back(l);
					local.push_back(first / target[0]);
					result.push_back(local);
				}
			}
		}
	}

	for (int i = 0; i < result.size(); ++i)
	{
		k = result[i][0] + result[i][1] + result[i][2];

		if (k < minOne)
		{
			minOne = k;
			index = i;
		}
	}

	if (index == 100000000)
	{
		ouf << "NONE" << endl;
	}else {
		ouf << result[index][0] << ' '
			 << result[index][1] << ' '
			 << result[index][2] << ' '
			 << result[index][3] << endl;
	}

	return 0;
}
