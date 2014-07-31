/*
 ID: ShiehShieh
 PROG: holstein
 LANG: C++11
 */
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>


using namespace std;


bool checkout(int& V, vector<int>& allVitamin, vector<vector<int>>& allNutrition, set<int>& input) {
	int tem = 0;
	for (int i = 0; i < V; ++i)
	{
		/* code */
		tem = 0;
		for(int e : input) {
			tem += allNutrition[e][i];
		}
		if (tem >= allVitamin[i])
		{
			/* code */
			continue;
		}else {
			return false;
		}
	}

	return true;
}


int main(int argc, char const *argv[])
{
	ifstream inf("holstein.in");
	ofstream ouf("holstein.out");
	int V = 0, G = 0, k = 0;

	inf >> V;
	vector<int> allVitamin;
	for (int i = 0; i < V; ++i)
	{
		/* code */
		inf >> k;
		allVitamin.push_back(k);
	}

	inf >> G;
	vector<vector<int>> allNutrition(G);
	for (int i = 0; i < G; ++i)
	{
		/* code */
		for (int j = 0; j < V; ++j)
		{
			/* code */
			inf >> k;
			allNutrition[i].push_back(k);

		}
	}

	set<int> newSet;

	vector<set<int>> allPossible(G);
	for (int i = 0; i < G; ++i)
	{
		/* code */
		allPossible[i].insert(i);
	}

	for(set<int> i : allPossible) {

		if (checkout(V, allVitamin, allNutrition, i))
		{
			/* code */
			string str;
			ouf << i.size() << ' ' << flush;
			for(int e : i) {
				str += e + '1';
				str += ' ';
			}
			ouf << str.substr(0, str.length() - 1) << endl;
			exit(0);
		}
	}
/*
	for(set<int> s : allPossible) {
		for(int i : s) {
			cout << i << ' ' << flush;
		}
		cout << endl;
	}
*/
	vector<set<int>>::iterator tem;

	for ( ; true; )
	{
		/* code */
		int now = allPossible.size();

		for (int i = 0; i < now; ++i)
		{
			/* code */

			for (int j = 0; j < G; ++j)
			{
				/* code */
				newSet = *(allPossible.begin());

				if (newSet.find(j) == newSet.end())
				{
					/* code */
					newSet.insert(j);
				}else {
					continue;
				}
/*
				for(int e : newSet) {
					cout << e << ' ' << flush;
				}
				cout << endl;
*/
				if (checkout(V, allVitamin, allNutrition, newSet))
				{
					/* code */
					string str;
					ouf << newSet.size() << ' ' << flush;
					for(int e : newSet) {
						str += e + '1';
						str += ' ';
					}
					ouf << str.substr(0, str.length() - 1) << endl;
					exit(0);
				}
				allPossible.push_back(newSet);
			}
			allPossible.erase(allPossible.begin());
		}
	}

/*
	for(int i : allVitamin) {
		cout << i << ' ' << flush;
	}

	cout << endl;

	for(vector<int> v : allNutrition) {
		for(int i : v) {
			cout << i << ' ' << flush;
		}
		cout << endl;
	}
*/
	return 0;
}
