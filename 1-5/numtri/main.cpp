/*
 ID: ShiehShieh
 PROG: numtri
 LANG: C++11
 */
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>


using namespace std;


int R = 0;


int knapsack(int n, int w, int** triangle, int** result) {
	if (n == R - 1)
	{
		/* code */
		return 0;
	}

	if (result[n][w] != 0) return result[n][w];

	return result[n][w] = max(
		knapsack(n + 1, w, triangle, result) + triangle[n + 1][w],
		knapsack(n + 1, w + 1, triangle, result) + triangle[n + 1][w + 1]
	);
}


int max(int a, int b) {

	if (a < b) {

		return b;

	}else {

		return a;

	}
}


int main(int argc, char const *argv[])
{
	ifstream inf("numtri.in");
	ofstream ouf("numtri.out");
	int k = 0;
//	vector<vector<int>> triangle;
	int** triangle = nullptr;
//	vector<vector<int>> result;
	int** result = nullptr;
	string content;
	inf >> R;

	triangle = new int*[R];
	result = new int*[R];

	for (int i = 0; i < R; ++i)
	{
		/* code */
//		triangle.push_back(vector<int>());
		triangle[i] = new int[i + 1];
//		result.push_back(vector<int>());
		result[i] = new int[i + 1];

		for (int j = 0; j <= i; ++j)
		{
			/* code */
			inf >> k;
			triangle[i][j] = k;
//			triangle[i].push_back(k);
//			result[i].push_back(0);
			result[i][j] = 0;
		}
	}

	knapsack(0, 0, triangle, result);

	ouf << result[0][0] + triangle[0][0]<< endl;

//	for(vector<int> i :result) {
//		for(int j : i) {
//			cout << j + triangle[0][0] << ' ' << flush;
//		}
//		cout << endl;
//	}

//	for(vector<int> i : triangle) {
//		for(int j : i) {
//			cout << j << ' ' << flush;
//		}
//		cout << endl;
//	}

	return 0;
}
