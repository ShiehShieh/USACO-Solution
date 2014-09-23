/*
 ID: ShiehShieh
 PROG: agrinet
 LANG: C++11
 */
#include <fstream>
#include <string>
#include <iostream>
#include <map>
#include <vector>


using namespace std;


int main(int argc, char const *argv[])
{
	ifstream inf("agrinet.in");
	ofstream ouf("agrinet.out");
	int N = 0, treeSize = 0, treeCost = 0, minOne = 100000000, index = 0, parent = 0;
	vector<vector<int>> matrix;

	inf >> N;

	for (int i = 0; i < N; ++i)
	{
		matrix.push_back(vector<int>(N, 0));
	}

	vector<int> distances(N, 100000000), source(N, 0);
	vector<bool> connected(N, false);

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			inf >> matrix[i][j];
		}
	}

	treeSize = 1;
	treeCost = matrix[0][0];
	connected[0] = true;
	for (int i = 0; i < N; ++i)
	{
		distances[i] = matrix[0][i];
		source[i] = 0;
	}

	while(treeSize < N) {
		minOne = 100000000;

		for (int i = 0; i < N; ++i)
		{
			if (distances[i] < minOne && connected[i] == false)
			{
				minOne = distances[i];
				index = i;
			}
		}

		source[index] = parent;
		connected[index] = true;
		++treeSize;
		treeCost += distances[index];

		for (int i = 0; i < N; ++i)
		{
			if (matrix[index][i] < distances[i])
			{
				distances[i] = matrix[index][i];
				source[i] = index;
			}
		}

		parent = index;
	}

	ouf << treeCost << endl;

	return 0;
}
