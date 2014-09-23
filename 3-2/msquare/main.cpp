/*
 ID: ShiehShieh
 PROG: msquare
 LANG: C++11
 */
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <set>


using namespace std;


void A(vector<vector<int>>& original) {
	vector<int> a(original[0].begin(), original[0].end());
	original[0].clear();
	original[0].insert(original[0].begin(), original[1].begin(), original[1].end());
	original[1].clear();
	original[1].insert(original[1].begin(), a.begin(), a.end());

	return;
}


void B(vector<vector<int>>& original) {
	int k = 0;

	k = original[0][3];
	original[0].erase(original[0].end() - 1);
	original[0].insert(original[0].begin(), k);
	k = original[1][3];
	original[1].erase(original[1].end() - 1);
	original[1].insert(original[1].begin(), k);

	return;
}


void C(vector<vector<int>>& original) {
	int k = 0;

	k = original[0][1];
	original[0][1] = original[1][1];
	original[1][1] = original[1][2];
	original[1][2] = original[0][2];
	original[0][2] = k;

	return;
}


bool isEqual(vector<vector<int>>& a, vector<vector<int>>& b) {
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			if (a[i][j] != b[i][j])
			{
				return false;
			}
		}
	}

	return true;
}


int main(int argc, char const *argv[])
{
	ifstream inf("msquare.in");
	ofstream ouf("msquare.out");
	int k = 0;
	set<vector<vector<int>>> checked;
	vector<vector<int>> target(2);
	vector<vector<int>> original(2);
	vector<vector<vector<int>>> theStackForVector;
	vector<string> theStackForString;
	string result;

	for (int i = 0; i < 4; ++i)
	{
		inf >> k;
		target[0].push_back(k);
		original[0].push_back(i + 1);
	}

	for (int i = 0; i < 4; ++i)
	{
		inf >> k;
		target[1].insert(target[1].begin(), k);
		original[1].insert(original[1].begin(), i + 5);
	}

	theStackForVector.push_back(original);
	theStackForString.push_back(string());

	if (isEqual(original, target))
	{
		ouf << 0 << endl;
		ouf << endl;

		return 0;
	}

	while(true) {
		vector<vector<int>> localVector, currentVector;
		string localString, currentString;

		k = theStackForVector.size();

		for (int l = 0; l < k; ++l)
		{
			currentVector = theStackForVector[l];
			currentString = theStackForString[l];
			if (checked.find(currentVector) != checked.end())
			{
				continue;
			}else {
				checked.insert(currentVector);
			}

			for (int i = 0; i < 3; ++i)
			{
				localVector = currentVector;
				localString = currentString;

				if (i == 0)
				{
					A(localVector);
					localString += 'A';
				}else if (i == 1)
				{
					B(localVector);
					localString += 'B';
				}else if (i == 2)
				{
					C(localVector);
					localString += 'C';
				}

				if (isEqual(localVector, target))
				{
					ouf << localString.length() << endl;
					ouf << localString << endl;

					return 0;
				}else {
					theStackForVector.push_back(localVector);
					theStackForString.push_back(localString);
				}
			}
		}

		theStackForVector.erase(theStackForVector.begin(), theStackForVector.begin() + k);
		theStackForString.erase(theStackForString.begin(), theStackForString.begin() + k);
	}

	return 0;
}
