/*
 ID: ShiehShieh
 PROG: frac1
 LANG: C++11
 */
#include <fstream>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>


using namespace std;


struct myPair
{
	/* data */
	int first;
	int second;
};


bool myRule(const myPair& one, const myPair& two) {
	float last = (float)((float)one.first / (float)one.second);
	float next = (float)((float)two.first / (float)two.second);
//	cout << setprecision(1) << last << ' ' << next << endl;
//	printf("%f\\%f\n", last, next);
	if (last < next)
	{
		/* code */
		return true;
	}

	return false;
}


int main(int argc, char const *argv[])
{
	ifstream inf("frac1.in");
	ofstream ouf("frac1.out");
	vector<myPair> result;
	vector<myPair> newResult;
	myPair tem;
	int N = 0;

	inf >> N;

	vector<set<int>> allPossible(N + 1);

	for (int i = 1; i <= N; ++i)
	{
		/* code */
		for (int j = 2; j <= i; ++j)
		{
			/* code */
			if ((i % j) == 0)
			{
				/* code */
				allPossible[i].insert(j);
			}
		}
	}

	for (int i = 1; i <= N; ++i)
	{
		/* code */
		for (int j = 1; j <= i; ++j)
		{
			/* code */
			if (i != j)
			{
				/* code */
				for(int e : allPossible[j]) {
					if (allPossible[i].find(e) != allPossible[i].end())
					{
						/* code */
						goto label1;
					}
				}
				tem.first = j;
				tem.second = i;
				result.push_back(tem);
			}
			label1:{}
		}
	}

	for(set<int> s : allPossible) {
		for(int i : s) {
			cout << i << ' ' << flush;
		}
		cout << endl;
	}

	sort(result.begin(), result.end(), myRule);

	ouf << "0/1" << endl;
	for(myPair p : result) {
		ouf << p.first << '/' << p.second << endl;
	}
	ouf << "1/1" << endl;

	return 0;
}
