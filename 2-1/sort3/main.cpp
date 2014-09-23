/*
 ID: ShiehShieh
 PROG: sort3
 LANG: C++11
 */
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


bool checkout(vector<pair<int, int>>& allVertex, int& result, int& loops) {
	vector<pair<int, int>>::iterator tem = allVertex.begin();

	for (vector<pair<int, int>>::iterator i = allVertex.begin() + 1; i != allVertex.end(); ++i)
	{
		if (i->first == tem->second && tem->first == i->second)
		{
			/* code */
			++loops;
			result += 2;
			allVertex.erase(i);
			allVertex.erase(allVertex.begin());
//			cout << endl;
//			for(pair<int, int> p : allVertex) {
//				cout << p.first << ' ' << p.second << endl;
//			}
//			cout << 'b' << result << ' ' << loops << endl;
//			cout << endl;

			return true;
		}
		if (i->first == tem->second && tem->first != i->second)
		{
			/* code */
			result += 1;
			tem->second = i->second;
			allVertex.erase(i);
//			cout << 'a' << endl;
//			for(pair<int, int> p : allVertex) {
//				cout << p.first << ' ' << p.second << endl;
//			}
//			cout << 'b' << result << ' ' << loops << endl;
//			cout << 'a' << endl;

			return true;
		}
	}

	return false;
}


int main(int argc, char const *argv[])
{
	ifstream inf("sort3.in");
	ofstream ouf("sort3.out");
	int N = 0, k = 0;

	inf >> N;

	vector<int> theSequence;
	vector<int> finished;
	vector<pair<int, int>> allVertex;

	inf >> k;
	while(inf) {
		theSequence.push_back(k);
		inf >> k;
	}

//	for(int i : theSequence) {
//		cout << i << endl;
//	}

	finished = theSequence;
	sort(finished.begin(), finished.end());

	for (int i = 0; i < N; ++i)
	{
		/* code */
		if (finished[i] != theSequence[i])
		{
			/* code */
			allVertex.push_back(make_pair(theSequence[i], finished[i]));
		}
	}

	bool mark = true;
	int result = 0, loops = 0;
	sort(allVertex.begin(), allVertex.end());
	for ( ; mark && !allVertex.empty(); )
	{
		/* code */
		mark = checkout(allVertex, result, loops);
	}

	ouf << result - loops << endl;

//	for(pair<int, int> p : allVertex) {
//		cout << p.first << ' ' << p.second << endl;
//	}

	return 0;
}
