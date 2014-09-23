/*
 ID: ShiehShieh
 PROG: fact4
 LANG: C++11
 */
#include <fstream>
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cmath>


using namespace std;


int main(int argc, char const *argv[])
{
	ifstream inf("fact4.in");
	ofstream ouf("fact4.out");

	int N = 0, result = 1;

	inf >> N;

	for (int i = 1; i <= N; ++i)
	{
		result *= i;
		while(result % 10 == 0) {
			result /= 10;
		}

		result %= 100000;
	}

	ouf << result % 10 << endl;

	return 0;
}
