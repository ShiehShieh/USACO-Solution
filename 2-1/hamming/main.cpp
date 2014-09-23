/*
 ID: ShiehShieh
 PROG: hamming
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


int checkoutBit(int input) {
	int count = 0;

	for (count = 0; input; ++count)
	{
		/* code */
		input &= (input - 1);
	}

	return count;
}


bool checkoutSingle(int& one, int& two, int& D) {
	int diff = checkoutBit(one ^ two);

	if (diff >= D)
	{
		/* code */
		return true;
	}else {
		return false;
	}
}


bool checkoutAll(vector<int>& allPossible, int& newOne, int& D) {
	for(int i : allPossible) {
		if (!checkoutSingle(newOne, i, D))
		{
			/* code */
			return false;
		}
	}

	return true;
}


int main(int argc, char const *argv[])
{
	ifstream inf("hamming.in");
	ofstream ouf("hamming.out");
	vector<int> allPossible;
	int N = 0, B = 0, D = 0, max = 1;
	inf >> N >> B >> D;

	for (int i = 0; i < B; ++i)
	{
		/* code */
		max *= 10;
	}

	allPossible.push_back(0);
	for (int i = 1; allPossible.size() < N && i < max; ++i)
	{
		/* code */
		if (checkoutAll(allPossible, i, D))
		{
			/* code */
			allPossible.push_back(i);
		}
	}

//	for(int i : allPossible) {
//		ouf << i << endl;
//	}

	for (int i = 0; i < allPossible.size(); ++i)
	{
		/* code */
		if (i % 10 == 0 && i != 0)
		{
			/* code */
			ouf << endl;
		}
		if (i != allPossible.size() - 1 && (i + 1) % 10 != 0)
		{
			/* code */
			ouf << allPossible[i] << ' ' << flush;
		}else {
			ouf << allPossible[i] << flush;
		}
	}
	ouf << endl;

	return 0;
}
